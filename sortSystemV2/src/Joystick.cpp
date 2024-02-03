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
    if (joystick_y() < 50) return true;
    return false;
}

bool joystick_down() {
    if (joystick_y() > 950) return true;
    return false;
}

bool joystick_left() {
    if (joystick_x() < 50) return true;
    return false;
}

bool joystick_right() {
    if (joystick_x() > 950) return true;
    return false;
}

bool joystick_press() {
    if (digitalRead(JS_SW)) return true;
    return false;
}

