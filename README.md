# Smart Blaster Library v1.2

Arduino library to make ammo counters and more for highly modified NERF blasters. 

___

## Contents:
- [Features Included](#features-included)
- [Parts and Tools Needed](#parts-and-tools-needed)
- [Getting Started](#getting-started)
- [Usage](#usage)


## Features Included:
To include any of these features, the corresponding hardware must be included.

1. **Ammo Counting:** Count your ammo. Whenever you fire a dart, it's detected using one of these methods:
	1. **Switch**: Detect shots every time the trigger is pressed. Orient a tactile switch to be pressed when the blaster's trigger is pressed, and wire it up to the microcontroller. May not be ideal for fully-automatic blasters.
	f2. **Infrared (IR) Gate**: Using both an IR transmitter diode and IR receiver diode to detect dart passage rather than physical trigger pulls. The transmitter and receiver should be positioned so the transmitter shines directly on the receiver along the diameter of the barrel, forming a "gate". When a dart is fired, the gate is broken, which is detected with the microcontroller.
2. **Chronograph**: Using an IR gate, a chronograph can be implemented by recording the time it took for the dart to completely break through the gate, divided by the known length of the dart. Units are in feet per second (fps).
3. **Voltmeter**: Using a voltage divider, the Arduino can read the voltage of the battery used. Ideal for electronic-powered blasters, so you know when to switch out the batteries. Can detect the voltage of the battery powering the blaster, or of the battery powering the microcontroller.
4. **Select-Fire**:  Want to conserve ammo in your fully-automatic blaster? Toggle between safety, single-shot. three-round-burst, or fully-automatic with this feature. Requires a relay or MOSFET to control the pusher motor. IR gate required.
5. **Magazine Insertion Detection**:  Check if magazine is inserted in blaster, and when magazine is swapped out, the ammo will reset.
6. **Different Magazine Sizes**: Toggle between various magazines sizes with the press of a button. All NERF-compatible magazines can be configured: 5, 6, 10, 12, 15, 18, 20, 21, 25, and 36.
7. **Count-Up Mode**: Instead of counting down, it can count up every time a shot is fired.

___


## Parts and Tools Needed:
All builds require some sort of Arduino-compatible microcontroller. I recommend the [Adafruit Pro Trinket](https://www.adafruit.com/product/2000). Also make sure to have the [Arduino IDE](https://www.arduino.cc/en/Main/Software) installed.

### Parts:
|Features vs Parts Required | Ammo Counter - Switch | Ammo Counter - IR Gate| Chronograph | Voltmeter| Select - Fire | Usages| Notes |
|:--------------------------|:---------------------:|:---------------------:|:-----------:| :-------:|:-------------:|:-----:|:-----:|
| Microcontroller           | X                     | X | X | X | X | Brains of everything. | Microcontroller recommendation above |
| [Slider Switch](https://www.amazon.com/Uxcell-a13042200ux0676-Solder-Position-Switch/dp/B00CQNQN4Q/ref=sr_1_7?ie=UTF8&qid=1498072224&sr=8-7&keywords=slider+switch) | X | X | X | X | X | Used to toggle power/on of microcontroller | Can be replaced by rocker switch |
| [I2C OLED Display](https://www.amazon.com/Diymall-Yellow-Serial-Arduino-Display/dp/B00O2LLT30/ref=sr_1_1?ie=UTF8&qid=1498070241&sr=8-1&keywords=i2c+oled+display)                  | X | X | X | X |X | Used for displaying ammo, and if applicable, mode, voltage, and chrono readings |
| [Lever Switch](https://www.amazon.com/Gikfun-Micro-Switch-Arduino-EK1713/dp/B015W8S8NA/ref=sr_1_2?ie=UTF8&qid=1498070421&sr=8-2&keywords=arduino+switch)                       | X (2)           | X | X | X | X | Used for magazine insertion detection. If switch varient of ammo counter is selected, then another switch will be used for ammo counting.
| [Momentary Push Button](https://www.amazon.com/Gikfun-Micro-Switch-Arduino-EK1713/dp/B015W8S8NA/ref=sr_1_2?ie=UTF8&qid=1498070421&sr=8-2&keywords=arduino+switch)                     | X | X      | X | X | X (2) | Used for toggling between the various magazines sizes. If Select-Fire mode setup, then another button will be used to toggle through the various fire modes.
| [IR Transmitter and Receiver Diode](https://www.amazon.com/Gikfun-Infrared-Emitter-Receiver-Arduino/dp/B01HGIQ8NG/ref=pd_sim_60_2?_encoding=UTF8&pd_rd_i=B01HGIQ8NG&pd_rd_r=M28XT7S0DNCFMEJPPKXT&pd_rd_w=INV1r&pd_rd_wg=61093&psc=1&refRID=M28XT7S0DNCFMEJPPKXT)                   | | X | X | | X | Used for IR gate |
| Resistors (10K and 100k) |  |  |  | X | | Used for voltage divider to drop the voltage to a safe level for the microcontroller. | Resistors can be different values, just make sure the battery being checked has its voltage dropped to a voltage safe for the microcontroller. |
| [Relay](https://www.amazon.com/Tolako-Arduino-Indicator-Channel-Official/dp/B00VRUAHLE/ref=sr_1_2?ie=UTF8&qid=1498071951&sr=8-2&keywords=arduino+relay)| | | | | X | Used to control the NERF blaster's motors through the microcontroller |

### Tools:
1. Phillips Head Screwdriver
2. Drill
3. Soldering Iron and Solder + soldering materials/tools (wire, flux, shrink wrap, helping hands, etc.)
3. Dremel or rotary tool (recommended, not required)
4. Hot glue and/or Epoxy putty (recommended, not required)
5. Sandpaper and/or files (recommened, not required)
6. Nuts and bolts to mount display and/or microcontroller


**Extra Notes on Parts and Tools**: 
 1. Most of the parts can be bought cheaper from EBay or Digikey or other electronics stores.
 2. Microcontroller will need a battery to power it. A 9v will work fine. If the blaster is an electronic blaster, the microcontroller can be powered off the same batttery as the blaster, at the cost of a slight decrease in the blaster's performance.


___

## Getting Started
A good foundation in basic electronics and a bit of physics as well a programming will help dramatically when building your blaster. 
### Installation
Go to folder 'libraries' to add some libraries which can be accessed through the Arduino IDE:

`cd ../Arduino/libraries`

Install library to Smart Your Blaster:

`git clone https://github.com/etnom/nerf-ammo-counter.git`

=Install Adafruit's library to work with display:

`git clone https://github.com/adafruit/Adafruit_SSD1306.git`

Install library to work with graphics on the dosplay:

`git clone https://github.com/adafruit/Adafruit-GFX-Library.git`

Install library to deal with buttons and debouncing:
 
`git clone https://github.com/JChristensen/Button.git`


Alternatively, the libraries can be installed the easy way:
- Go to https://github.com/etnom/nerf-ammo-counter, click the **Download ZIP** button and save the ZIP file to a convenient location on your PC. 
- Uncompress the downloaded file.  This will result in a folder containing all the files for the library, that has a name that includes the branch name, usually **nerf-ammo-counter-master**.
- Rename the folder to just **nerf-ammo-counter**.
- Copy the renamed folder to the Arduino/libraries folder.
- Open the folder **Libraries** in **nerf-ammo-counter**. Copy the three folders out to the Arduino/libraries folder.

### Importation
In an Arduino sketch, include the requirfed libraries:

```
 #include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Button.h>
#include <SmartBlaster.h>
```

Also set up some stuff for the display:
```
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
```

Set up modes:

`byte modes[] = {isIRAmmoCounter, isChronograph, isVoltmeter, isSelectFire};`
- All items in array are boolean values.
- First item specifies if ammo counting will be detected through a switch or IR gate. `false` if switch, `true` if IR gate. Can't be both switch and IR gate.
- Second item specifies whether or not the chronograph feature will be implemented, third for voltmeter, and fourth for select-fire.

Setup IO Pins:

`byte pins[] = {ammoCountingInputPin, magazineInsertionDetectionPin, magazineSizeTogglePin, voltmeterPin, firingModeTogglePin, firingModeOutputPin};`
- All items in array are integer values.
- If the corresponding mode for the pin was not set up, put `-1` for the pin value.
- First item will be pin which the ammo counting mechanism (switch or IR gate) is connected to. 
- Make sure if the ammo counting mechanism is switch, it's connecting to a digital pin. If the ammo counting mechanism is the IR gate, make sure it's connected to an analog pin. 
- Second item is digital pin which the magazine insertion detection switch is connected to.
- Third item is digital pin which the magazine size toggle button is connected to. 
- Fourth item is the analog pin which the voltage divider for the voltmeter is connected to. 
- Fifth item is the digital pin which the fire mode toggle button is connected to. 
- Sixth item is the digital pin which the relay for connecting the automatic blaster's motor is connected to. 

Also for the display, in `void setup()`:
```
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
SmartBlaster.initDisplay(display);
```


___

## Usage
