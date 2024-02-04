#include "Arduino.h"
#include "Shiftregister.h"
#include "LCD.h"
#include "Joystick.h"
#include "Menu.h"

coord_t resistor = {1, 2};
coord_t servo = {2, 6};
coord_t led = {0, 7};

void setup() {
// write your initialization code here

//    Serial.begin(9600);

    setup_shiftRegister();
    setup_LCD();
    setup_joystick();

    lcdText_t startup = {"Move joystick to", "begin."};
    write_LCD(startup);


}


void loop() {
// write your code her

    //trailingLight(100);

    //blink_coordinate(servo);

    menu_show();


}