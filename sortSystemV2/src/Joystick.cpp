//
// Created by Eigenaar on 2-2-2024.
//

#include "Joystick.h"
#include "Arduino.h"

void setup_joystick() {

    pinMode(JS_SW, INPUT);

}

int joystick_x() {

    return analogRead(JS_VRx);
}

int joystick_y() {

    return analogRead(JS_VRy);
}

bool joystick_up() {
    static bool holding = false;

    if (joystick_y() > 50) {
        holding = false;
        return false;
    } else if (!holding) {   // if joystick < 50 and holding is false return true
        holding = true;
        return true;
    }

    return false;
}

bool joystick_down() {
    static bool holding = false;

    if (joystick_y() < 950) {
        holding = false;
        return false;
    } else if (!holding) {   // if joystick < 50 and holding is false return true
        holding = true;
        return true;
    }

    return false;
}

bool joystick_left() {
    static bool holding = false;

    if (joystick_x() > 50) {
        holding = false;
        return false;
    } else if (!holding) {   // if joystick < 50 and holding is false return true
        holding = true;
        return true;
    }

    return false;
}

bool joystick_right() {
    static bool holding = false;

    if (joystick_x() < 950) {
        holding = false;
        return false;
    } else if (!holding) {   // if joystick < 50 and holding is false return true
        holding = true;
        return true;
    }

    return false;
}

