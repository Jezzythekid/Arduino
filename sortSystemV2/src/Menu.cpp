//
// Created by Eigenaar on 2-2-2024.
//

#include "Menu.h"
#include "screens.h"
#include "LCD.h"
#include "Joystick.h"





void menu_show() {

    static int current_screen = 0;

    if (joystick_left()) current_screen--;
    else if (joystick_right()) current_screen++;
    else return;

    if (current_screen >= NUMBER_OF_SCREENS) current_screen = 0;
    if (current_screen < 0) current_screen = NUMBER_OF_SCREENS - 1;

    write_LCD(&screens[current_screen]);
}

