

// Shadow Price Firing & ammo counter code

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <JC_Button.h>
#include <AmmoCounter.h> 

//pins for button
#define TRIGGER_BTN_PIN 0
#define RELOAD_BTN_PIN 1
#define MAG_SZ_TOG_BTN_PIN 4

#define TEXT_SIZE 6  // multiplier on text size
#define ROTATION 1   // rotation of text i.e. 0 = 0deg, 1 = 90deg, 2 = 180deg, 3 = 270deg
#define WIDTH 0      // how far to move from long edge (128 pixel edge)
#define HEIGHT -32   // fow far from edge with wires (32 pixel edge)

AmmoCounter AC = AmmoCounter(TRIGGER_BTN_PIN, RELOAD_BTN_PIN, MAG_SZ_TOG_BTN_PIN);

void setup() {
  AC.begin(TEXT_SIZE, ROTATION, WIDTH, HEIGHT);
}

void loop() {
  // put your main code here, to run repeatedly:
  AC.countAmmo();    //count ammo, constantly check for the trigger switch to be pressed to count
  AC.reload();       //reload, constantly check for the magazine switch to be pressed/not pressed
  AC.toggleMags();   //toggle between magazine sizes, constanly check for the magazine toggle switch to be pressed
}
