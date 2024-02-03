#include "stdlib.h"
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

/*
    static int sr1 = B01111111;
    static int sr2 = B10000000;

    bitToggle(sr1, 1);
    int newsr2 = bitToggle(sr2, 8-2);

    write_shiftRegister1(sr1);
    write_shiftRegister2(newsr2);
*/


}


void loop() {
// write your code her

    //trailingLight(100);

    //blink_coordinate(servo);

    menu_show();

    delay(200);


}