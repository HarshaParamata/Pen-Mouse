# 🖊️ Pen Mouse – A Wireless Pen-Style Mouse using ATmega328P

The **Pen Mouse** is a compact, pen-like input device that functions similarly to a traditional mouse. It uses an optical sensor to detect movement and buttons for left/right click functionality. Built using affordable and widely available components, this device is ideal for students, designers, and users with limited desk space—particularly during presentations or graphic design work.

---

## ✨ Features

- Move the cursor and perform clicks
- Pen-like ergonomic design for precise control
- Communicates wirelessly via Bluetooth
- Rechargeable and portable

---

## 🔩 Components Selection

- **ATmega328P-PU Microcontroller**  
  8-bit AVR RISC-based MCU with DIP-28 package for easy prototyping. Offers sufficient I/O, memory, and Arduino compatibility.

- **HC-06 Bluetooth Module (4-pin)**  
  Provides wireless connectivity. Simple UART interface, works with 3.3V or 5V logic.

- **TPS61023DRLT Switching Regulator**  
  Ensures stable 5V output from a Li-ion battery input, essential for reliable operation.

- **Li-ion Battery**  
  Rechargeable power source for portable use.

- **Arduino Uno**  
  Used for uploading firmware to the ATmega328P.

- **Passive Components (Resistors, Capacitors)**  
  For pull-ups, filtering, and power stabilization.

---
## 🛠️ Getting Started

### ⚙️ PCB Design

- The ATmega328P is placed centrally with decoupling capacitors near its power pins.
- SPI lines (MOSI, MISO, SCK, SS) are routed to the HC-06 Bluetooth module via pins 10–13 on the ATmega.
- A voltage regulation circuit using TPS61023DRLT generates a stable 5V from the Li-ion battery.

### 💻 Uploading Code to ATmega328P

1. Use an **Arduino Uno as ISP** to program the ATmega328P.
2. Follow this official Arduino tutorial for setup and connections:  
   🔗 [How to program ATmega328P using Arduino Uno – Arduino to Breadboard](https://docs.arduino.cc/built-in-examples/arduino-isp/ArduinoToBreadboard/)
3. Flash the Pen Mouse firmware (provided in the `codes/` folder).
4. After successful upload, remove the Arduino and power the Pen Mouse from the battery.

\section*{Pen Mouse: Computer-Side Setup Guide (Windows/Linux/macOS)}

This guide explains how to configure your computer to receive Pen Mouse input over Bluetooth and convert it into actual mouse movements using a Python script.

\subsection*{Prerequisites}
\begin{itemize}
  \item Python 3.6 or later
  \item Pip package manager
  \item HC-06 Bluetooth module paired with your system
  \item Basic code/text editor (e.g., Notepad++, VS Code, nano)
\end{itemize}

\subsection*{Step 1: Install Required Python Packages}
In your terminal or command prompt, run:
\begin{verbatim}
pip install pyserial pyautogui
\end{verbatim}

\subsection*{Step 2: Create and Save the Python Script}
\begin{enumerate}
  \item Open any code/text editor.
  \item Copy the provided Python code for Pen Mouse control (refer to firmware section).
  \item Save the file as \texttt{pen\_mouse.py}.
\end{enumerate}

\subsection*{Step 3: Pair HC-06 and Find Serial Port}

\subsubsection*{Windows}
\begin{itemize}
  \item Pair HC-06 from \textit{Settings > Devices > Bluetooth}.
  \item Open \textit{Device Manager > Ports (COM \& LPT)} to find the COM port (e.g., \texttt{COM5}).
\end{itemize}

\subsubsection*{Linux}
\begin{verbatim}
bluetoothctl
scan on
pair XX:XX:XX:XX:XX:XX
trust XX:XX:XX:XX:XX:XX
connect XX:XX:XX:XX:XX:XX
ls /dev/rfcomm*
\end{verbatim}

\subsubsection*{macOS}
\begin{itemize}
  \item Pair HC-06 via \textit{System Preferences > Bluetooth}.
  \item Locate the device in terminal:
  \begin{verbatim}
ls /dev/tty.HC-06*
  \end{verbatim}
\end{itemize}

\subsection*{Step 4: Run the Script}
Run the following command in terminal or command prompt:
\begin{verbatim}
python pen_mouse.py
\end{verbatim}

\noindent Once running, your Pen Mouse should control the system cursor via Bluetooth.

\subsection*{Permissions and Troubleshooting}

\subsubsection*{Linux/macOS Serial Port Permissions}
\begin{verbatim}
sudo chmod a+rw /dev/rfcomm0          % Linux
sudo chmod a+rw /dev/tty.HC-06-DevB   % macOS
\end{verbatim}

\subsubsection*{macOS Accessibility Permissions}
\begin{itemize}
  \item Go to \textit{System Preferences > Security \& Privacy > Accessibility}
  \item Add and allow your terminal or Python environment to control your mouse.
\end{itemize}

\subsection*{References}
\begin{itemize}
  \item \href{https://pyserial.readthedocs.io/}{PySerial Documentation}
  \item \href{https://pyautogui.readthedocs.io/}{PyAutoGUI Documentation}
\end{itemize}



---

## 🖼️ Hardware Snapshots

### 📐 Schematic Diagram  
![Schematic](./images/schematic.png)

### 🛠️ PCB Layout  
![PCB](./images/pcb.png)

### 🛠️ 3D PCB View  
![3D](./images/3d.png)
---

## 📁 Repository Structure

PenMouse/ \\
├── kicad files/ # Schematic,BOM and PCB file 
├── images/ # Schematic and PCB images
├── datasheets/ # datasheet of components used
├── Codes/ # code used for promgraming atmega and computer
├── Introduction # introduction and first idea of the project
├── PCB design # pcb design review  
└── README.md


---

## 🚀 Future Improvements

- Add rechargeable support with USB charging
- Integrate gesture detection
- Replace HC-06 with BLE module for lower power and broader compatibility

---

## 📄 License

This project is licensed under the MIT License. See `LICENSE` file for details.

---

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you'd like to change.

---

## 🙌 Acknowledgements

- Inspired by DIY input devices and custom hardware projects
- Built at **IIT Hyderabad** as part of a ESDP Course Project

