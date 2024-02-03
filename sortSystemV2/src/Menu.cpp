//
// Created by Eigenaar on 2-2-2024.
//

#include "Menu.h"
#include "Screens.h"
#include "LCD.h"
#include "Joystick.h"

int m_menu = 0;

void menu_show() {

    switch (m_menu) {
        case MAIN:
            write_menu_LCD(&s_MAIN);

            if (joystick_press()) m_menu = HOME_SEARCH;
            break;

        case HOME_SEARCH:
            write_LCD("Search", "");

            if (joystick_press()) m_menu = SEARCH_ELECTRICAL;
            break;

        case HOME_SETTINGS:

            break;
        case SEARCH_OTHER:

            break;
        case SEARCH_ELECTRICAL:

            break;
        case SEARCH_TOOLS:

            break;
    }

}

void menu_input(screen_t *screen) {

    if (joystick_right()) {
        screen->screenNumber = (screen->screenNumber - screen->screenType.type + 1) % screen->screenType.numberOfScreens;
    }

    // @todo yea this is way to complicated, I'll first make a simple one see branch "SortSystemMenuSimple"
}

/*
void menu_search_item() {

    write_LCD("Search item", "");

    if (joystick_left()) m_current = HOME_OTHER;
    if (joystick_right()) m_current = HOME_SETTINGS;
    if (joystick_down()) m_current = SEARCH_ELECTRICAL;
}

void menu_settings() {

    write_LCD("Settings", "w.i.p.");

    if (joystick_left()) m_current = HOME_SEARCH;
    if (joystick_right()) m_current = HOME_OTHER;
}

void menu_other() {

    write_LCD("Other", "w.i.p.");

    if (joystick_left()) m_current = HOME_SETTINGS;
    if (joystick_right()) m_current = HOME_SEARCH;
}

void menu_s_other() {

    write_LCD("Search:", "Other");

    if (joystick_left()) m_current = SEARCH_TOOLS;
    if (joystick_right()) m_current = SEARCH_ELECTRICAL;

    if (joystick_up()) m_current = HOME_SEARCH;

}

void menu_s_electrical() {

    write_LCD("Search:", "Electrical");

    if (joystick_left()) m_current = SEARCH_OTHER;
    if (joystick_right()) m_current = SEARCH_TOOLS;

    if (joystick_up()) m_current = HOME_SEARCH;
}

void menu_s_tools() {

    write_LCD("Search:", "Tools");

    if (joystick_left()) m_current = SEARCH_ELECTRICAL;
    if (joystick_right()) m_current = SEARCH_OTHER;

    if (joystick_up()) m_current = HOME_SEARCH;
}
*/

