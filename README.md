![nrfBlueNullifier](https://github.com/user-attachments/assets/88434037-27e6-4874-9e59-be4a89456f3f)

# nrfBlueNullifier
A tool which jam classic bluetooth signals.

# Key Features
- Minimal Setup.

# Hardware Requirements
- NodeMCU ESP-32S V1.1 38-Pins
- One nrf24L01 Module OR nrf24L01+PA/LNA Module
- `7` Female to Female Jumper Wires

# Note
- nrf24L01 and nrf24L01+PA/LNA modules have same pinout.

# Pinout Table
| NODEMCU ESP-32S | nrf24l01 |
|-----------------|----------|
| 3.3V            | VCC      |
| GND             | GND      |
| GPIO22          | CE       |
| GPIO21          | CSN      |
| GPIO18          | SCK      |
| GPIO23          | MOSI     |
| GPIO19          | MISO     |

# Connection Diagram
![ESP32 38-Pins with nrf24L01](https://github.com/user-attachments/assets/8066151b-2e73-4e15-accc-a7685f9a41d0)

# Images
![NodeMCU ESP-32S](https://github.com/user-attachments/assets/b790a39f-dae6-4087-a740-148f6b272aa4)
![nrf24L01](https://github.com/user-attachments/assets/706db436-8ce3-431d-8b0e-51e8936e28ff)

# Setup
1. Download Arduino IDE from [here](https://www.arduino.cc/en/software) according to your Operating System.
2. Install it.
3. Go to `File` → `Preferences` → `Additional Boards Manager URLs`.
4. Paste the following link :
   
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
5. Click on `OK`.
6. Go to `Tools` → `Board` → `Board Manager`.
7. Wait for sometimes and search `esp32` by `Espressif Systems`.
8. Simply install it.
9. Wait for sometime and after that it is installed.
10. Go to `Sketch` → `Include Library` → `Manage Libraries`.
11. Wait for sometimes and search `rf24` by `TMRh20, Avamander`.
12. Simply install it.
13. Wait for sometime and after that it is installed.
14. Restart the Arduino IDE by closing and open again.
15. Done!

# Install
1. Download or Clone the Repository.
2. Open the folder and just double click on `nrfBlueNullifier.ino` file.
3. It opens in Arduino IDE.
4. Compile the code.
5. Select the correct board from the `Tools` → `Board` → `ESP32 Arduino`.
   - It is generally `NodeMCU-32S`.
6. Select the correct port number of that board.
7. Upload the code.
8. When show `Connecting.....` press and hold `BOOT` button.
9. When show `Writing at ` then release the `BOOT` button.
10. Done!
   - The script starts running automatically.

# What happened after script is running?
- It breaks the sound.
- It blocks the sound even the device playing the music.
- Sometimes it disconnects the bluetoth from the device.
