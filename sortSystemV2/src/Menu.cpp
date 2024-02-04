//
// Created by Eigenaar on 2-2-2024.
//

#include "Menu.h"
#include "screens.h"
#include "LCD.h"
#include "Joystick.h"





void menu_show() {

    static int submenu[NUMBER_OF_SCREENS];
    static int cur = 0;

    bool joystickdown = joystick_down();

    // read input of joystick
    if (joystick_left()) cur--;
    else if (joystick_right()) cur++;
    else if (joystickdown && submenu[cur] <= 0) submenu[cur] = listLength[cur] - 1;
    else if (joystickdown) submenu[cur]--;
    else if (joystick_up()) submenu[cur] = (submenu[cur] + 1) % listLength[cur];
    else return;


    if (cur >= NUMBER_OF_SCREENS) cur = 0;
    if (cur < 0) cur = NUMBER_OF_SCREENS - 1;

    write_LCD({components[cur], values[cur][submenu[cur]]});

    switch (cur) {
        case RESISTOR:
            add_custom_char(13, 1, OMEGA);
            break;
        case CAPACITORS:
            add_custom_char(14, 1, MU);
            break;
        default:
            return;

    }
}

