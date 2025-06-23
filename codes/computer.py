import serial
import pyautogui
import time

# Replace with your HC-06 COM port
SERIAL_PORT = 'COM5'
BAUD_RATE = 9600

try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud.")
    time.sleep(2)  # Allow Bluetooth to stabilize
except:
    print(f"Failed to connect to {SERIAL_PORT}.")
    exit()

# Main loop
while True:
    if ser.in_waiting >= 3:
        data = ser.read(3)
        buttons = data[0]
        dx = data[1] - 256 if data[1] > 127 else data[1]
        dy = data[2] - 256 if data[2] > 127 else data[2]

        # Move mouse (invert Y to match natural direction)
        pyautogui.moveRel(dx, -dy)

        # Handle mouse clicks
        if buttons & 0x01:
            pyautogui.mouseDown(button='left')
        else:
            pyautogui.mouseUp(button='left')

        if buttons & 0x02:
            pyautogui.mouseDown(button='right')
        else:
            pyautogui.mouseUp(button='right')
