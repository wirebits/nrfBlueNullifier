# 🛜nrfBlueNullifier
A tool which jam classic bluetooth signals using 1 nrf24L01+PA/LNA module at VSPI.

# 📦Requirements
- NodeMCU ESP-32S 38-Pins
- One nrf24L01 Module OR nrf24L01+PA/LNA Module
- `7` Female to Female Jumper Wires

# 🗒️Note
- nrf24L01 and nrf24L01+PA/LNA modules have same pinout.

# 🔌Pinout Table
| NODEMCU ESP-32S | nrf24l01 |
|-----------------|----------|
| 3.3V            | VCC      |
| GND             | GND      |
| GPIO22          | CE       |
| GPIO21          | CSN      |
| GPIO18          | SCK      |
| GPIO23          | MOSI     |
| GPIO19          | MISO     |

# 🖼️Images
![NodeMCU ESP-32S](https://github.com/user-attachments/assets/b790a39f-dae6-4087-a740-148f6b272aa4)
![nrf24L01](https://github.com/user-attachments/assets/706db436-8ce3-431d-8b0e-51e8936e28ff)

# ⚙️Setup
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

# 🔧Install
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

# 🔧Install using ESP Web Flasher
1. Open Adafruit ESP Web Flasher from [here](https://adafruit.github.io/Adafruit_WebSerial_ESPTool/).
2. Set the Baud Rate to `115200 Baud`.
3. Connect `ESP32` with a USB cable and then to the PC/Laptop.
4. Press and hold the `BOOT` button.
5. Click on `Connect` button.
6. Select your Device COM Port in the Pop-Up Window.
7. Release the `BOOT` button.
   - When connected successfully, then it show this <img width="386" height="217" alt="Adafruit ESP Web Flasher" src="https://github.com/user-attachments/assets/47b8888e-25d2-4a29-ab6d-25055cf3a033" />
8. Click on `Erase` button.
   - Wait for sometimes to successfully erased.
9. Download `3` files from this directory.
    - The files are :
      1. `nrfBlueNullifier-VSPI-nrf24L01-bootloader.bin`
      2. `nrfBlueNullifier-VSPI-nrf24L01-partitions.bin`
      3. `nrfBlueNullifier-VSPI-nrf24L01.bin`
10. Select `nrfBlueNullifier-VSPI-nrf24L01-bootloader.bin` file with offset `0x1000`.
11. Select `nrfBlueNullifier-VSPI-nrf24L01-partitions.bin` file with offset `0x8000`.
12. Select `nrfBlueNullifier-VSPI-nrf24L01.bin` file with offset `0x10000`.
13. Click on `Program` button.
    - Wait for sometimes to successfully programmed.
14. Press and release the `BOOT` button.
15. Unplug and plug the `ESP32` on the PC/Laptop.
16. Done! `nrfBlueNullifier-VSPI-nrf24L01` is ready.

# 🤔What happened after script is running?
- It breaks the sound.
- It blocks the sound even the device playing the music.
- Sometimes it disconnects the bluetoth from the device.

# 🛠️Modification In Code
- The code effects on classic bluetooth and wifi.
- If want to put most of the effect on classic bluetooth only, modify the code by replacing the code in line 14 by following :
```
byte hopping_channel[] = {32, 34, 46, 48, 50, 52, 26, 28, 30, 74, 76, 78};
```
- Save the code.
- Compile the code and then upload it.

# 🤔What happened after modified script is running?
- It blocks the sound even the device playing the music.
- It slow down the speed of the wifi.
