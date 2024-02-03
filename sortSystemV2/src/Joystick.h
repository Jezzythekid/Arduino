//
// Created by Eigenaar on 2-2-2024.
//

#ifndef SORTSYSTEMV2_JOYSTICK_H
#define SORTSYSTEMV2_JOYSTICK_H

#define JS_SW 13
#define JS_VRx A0
#define JS_VRy A1

/// Function that initializes the joystick
void setup_joystick();

int joystick_x();

int joystick_y();

bool joystick_up();
bool joystick_down();
bool joystick_left();
bool joystick_right();

#endif //SORTSYSTEMV2_JOYSTICK_H
