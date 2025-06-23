#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#define BAUD_RATE 9600

// Define pins for buttons
#define LEFT_CLICK_PIN PC0
#define RIGHT_CLICK_PIN PC1

// Define MX8733B sensor pins
#define SENSOR_SCLK PB5
#define SENSOR_SDIO PB4
#define SENSOR_NCS PB3

// UART initialization
void UART_init(void) {
    uint16_t ubrr = F_CPU/16/BAUD_RATE - 1;
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
}

void UART_transmit(unsigned char data) {
    while (!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

// SPI functions for MX8733B
void SPI_init() {
    DDRB |= (1<<SENSOR_SCLK)|(1<<SENSOR_NCS);
    DDRB &= ~(1<<SENSOR_SDIO);
    PORTB |= (1<<SENSOR_NCS);
}

uint8_t SPI_transfer(uint8_t data) {
    uint8_t i;
    for (i = 0; i < 8; i++) {
        if (data & 0x80)
            PORTB |= (1<<SENSOR_SDIO);
        else
            PORTB &= ~(1<<SENSOR_SDIO);
        
        PORTB |= (1<<SENSOR_SCLK);
        _delay_us(1);
        data <<= 1;
        if (PINB & (1<<SENSOR_SDIO))
            data |= 1;
        PORTB &= ~(1<<SENSOR_SCLK);
        _delay_us(1);
    }
    return data;
}

void MX8733B_write(uint8_t address, uint8_t data) {
    PORTB &= ~(1<<SENSOR_NCS);
    SPI_transfer(address | 0x80);
    SPI_transfer(data);
    PORTB |= (1<<SENSOR_NCS);
}

uint8_t MX8733B_read(uint8_t address) {
    PORTB &= ~(1<<SENSOR_NCS);
    SPI_transfer(address);
    uint8_t data = SPI_transfer(0x00);
    PORTB |= (1<<SENSOR_NCS);
    return data;
}

void MX8733B_init() {
    _delay_ms(50);  // Power-up delay
    MX8733B_write(0x0D, 0x01);  // Enter configuration mode
    _delay_ms(1);
    MX8733B_write(0x0E, 0x80);  // Reset
    _delay_ms(1);
    MX8733B_write(0x0D, 0x00);  // Exit configuration mode
    _delay_ms(1);
}

int main(void) {
    UART_init();
    SPI_init();
    MX8733B_init();

    DDRC &= ~((1<<LEFT_CLICK_PIN)|(1<<RIGHT_CLICK_PIN));
    PORTC |= (1<<LEFT_CLICK_PIN)|(1<<RIGHT_CLICK_PIN);

    int8_t dx, dy;
    uint8_t buttons;

    while(1) {
        buttons = 0;
        if (!(PINC & (1<<LEFT_CLICK_PIN))) buttons |= 0x01;
        if (!(PINC & (1<<RIGHT_CLICK_PIN))) buttons |= 0x02;

        uint8_t motion = MX8733B_read(0x02);
        if (motion & 0x80) {
            dx = MX8733B_read(0x03);
            dy = MX8733B_read(0x04);
        } else {
            dx = dy = 0;
        }

        UART_transmit(buttons);
        UART_transmit(dx);
        UART_transmit(dy);

        _delay_ms(10);
    }

    return 0;
}
