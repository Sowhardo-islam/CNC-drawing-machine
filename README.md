# Mini Arduino CNC Drawing Machine

**Project setup and documentation by, Sowhardo Islam**

A small pen plotter built from two DVD-drive mechanisms. The Arduino moves the pen on the **X/Y axes**, and a servo lifts or lowers it.

## What You Need

- Arduino Uno
- L293D motor shield compatible with  **library`AFMotor.h`**
- Two DVD-drive stepper mechanisms
- Small servo motor and pen holder
- Wires, screws, spring, base, and paper
- USB cable and a suitable power supply.. **(for DVD stepper use 5v only)**

## Software

Install these tools:

- **Arduino IDE:** https://www.arduino.cc/en/software
- **Processing:** https://processing.org/download/
- **Inkscape:** https://inkscape.org/release/

'**'processing and inkscape are included'**'

This project also includes an old Inkscape 0.48 installer and a legacy G-code extension.

## Project Files

- `main_code/main_code.ino` — Arduino firmware
- `processing_code/processing_code.pde` — Processing program that sends G-code to the Arduino
- `servo_test/servo_test.ino` — stepper motor and servo test sketch
- `G-code extention/` — Inkscape G-code extension files
- `Template.svg` — sample drawing template
- `intro final.gcode` — sample G-code file
- `arduino library` — install these library to arduino IDE

## 1. Assemble and Wire It

1. Mount the two DVD-drive mechanisms at right angles to make the X and Y axes.
2. Attach the pen holder and servo so the pen can move up and down.
3. Put the compatible motor shield on the Arduino Uno.
4. Connect the X-axis stepper to **M2**, the Y-axis stepper to **M1**, and the servo signal to **pin 9** as expected by the code.
5. Connect suitable motor power to the shield. Disconnect power before changing any wiring.

**Important:** This code requires an **AFMotor-compatible V1 shield**. The newer Adafruit Motor Shield V2 is not compatible with `AFMotor.h` without changing the code. Never power the motors directly from Arduino GPIO pins.

## 2. Upload the Arduino Code

1. Open `main_code/main_code.ino` in Arduino IDE.
2. Install the matching **AFMotor and servo** library.
3. Choose **Tools → Board → Arduino Uno** and select the correct port.
4. Click **Upload**.

The firmware uses **9600 baud**. The pen-up and pen-down servo positions are set to `90` and `110` in the sketch. Adjust only after testing the mechanism gently.

## 3. Generate a G-code File

1. Copy the contents of `G-code extention/` (`unicorn.inx`, `unicorn.py`, and the `unicorn` folder) to ... `C:\Program Files (x86)\Inkscape\share\extensions` folder

2. Restart Inkscape.

3. Open `Template.svg` in Inkscape. then delete previews picture and import you own design then select and go **path > trace bitmap > ok > update** after delete the orignal design then resize the traced bitmap and place into template ...  after again **path > objects to path** after that just **file > save as > (name it) > MakerBot Unicorn G-Code Output (.gcode) > Save** 


## 4. Run the Processing Sender

1. Install and open **Processing** from https://processing.org/download/.
2. Open `processing_code/processing_code.pde` and click **Run**.
3. Close Arduino IDE's **Serial Monitor** so Processing can use the serial port.
4. Click the Processing window, then press:
   - **`p`** — choose the Arduino COM/serial port
   - **`g`** — choose your `.gcode` file; sending starts automatically
   - **`x`** — stop sending
5. Keep the Arduino connected over USB. The sender and firmware both use **9600 baud**.

If Processing reports that `processing.serial` is missing, install the **Serial** library through Processing's library manager and run the sketch again.

## 5. First Test

- Test the servo and motors using `servo_test/servo_test.ino` before attaching the pen firmly.
- Begin with a small, simple drawing and keep the pen close to the center of the machine's travel area.
- If an axis moves the wrong way or the drawing size is incorrect, stop the machine and check motor wiring and the X/Y calibration values in `main_code.ino`.
- Keep fingers, loose wires, and objects clear of moving parts.

## Notes

This firmware is a **basic custom G-code receiver, not GRBL**. It is designed around this project's commands and hardware, so random G-code from other CNC machines **may not work correctly.** Test with small drawings first.

