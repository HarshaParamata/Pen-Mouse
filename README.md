# Pen-Mouse
The Pen Mouse is a compact, portable input device functions similar to a mouse built using a optical sensor to detect movement, and provide left or right clicks functionality through buttons. It was built with affordable components available and user-friendly to handle. It is especially useful for students or designers with limited desk space, ideal for presentations, graphic design applications.
## Features
• Move the cursor, performs clicks <br>
• Pen-like design offers precise control <br>
• Communicates wirelessly through Bluetooth
## Components Selection
• ___ATmega328p-pu microcontroller___: This microcontroller has a 8-bit AVR RISC architecture. It is chosen for its DIP-28 package which simplifies prototyping and assembly. Provides low-power connection, sufficient I/O, Memory and is compatible with Arduino development tools. <br>
• ___HC-06 4pin Bluetooth module___: Selected to enable wireless connectivity between the pen mouse and host devices. The HC-06 is widely supported, easy to interface with microcontrollers, and operates reliably at 3.3V or 5V logic levels. <br>
• ___Switching Regulator IC___: A voltage regulator (TPS61023DRLT) ensures stable voltage for sensitive components. <br>
• ___Li ion battery___: A rechargeable Li-ion battery provides portable power. <br>
• ___Arduino Uno___: Used in uploading the mouse code logic into the Microcontroller. <br>
• ___Passive Components___: (Resistors, Capacitors): Essential for signal conditioning, pull-ups, and power stabilization, these were chosen based on standard values for compatibility and availability.
## Getting Started
1. ___PCB Design___: We placed the ATMEGA328P at the center with decoupling capacitors near the power pins. We then routed the SPI(Serial Peripheral Interface) lines to the HC-06 Bluetooth module(pins 10-13 on the ATMEGA). Then the voltage regulation circuit was added using the switching regulator IC TPS61023DRLT for a stable 5V output.
## License
This project is licensed under the MIT License. See LICENSE file for details.
