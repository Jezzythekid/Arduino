//
// Created by Eigenaar on 2-2-2024.
//

#include "Menu.h"
#include "LCD.h"
#include "Joystick.h"



static int m_current = 1;

void menu_show() {

    switch (m_current) {
        case Root_Search:
            menu_search_item();
            break;
        case Root_Settings:
            menu_settings();
            break;
        case Root_Other:
            menu_other();
            break;
        case Search_other:
            menu_s_other();
            break;
        case Search_electrical:
            menu_s_electrical();
            break;
        case Search_Tools:
            menu_s_tools();
            break;
    }

}

void menu_search_item() {

    write_LCD("Search item", "");

    if (joystick_left()) m_current = Root_Other;
    if (joystick_right()) m_current = Root_Settings;
    if (joystick_down()) m_current = Search_electrical;
}

void menu_settings() {

    write_LCD("Settings", "w.i.p.");

    if (joystick_left()) m_current = Root_Search;
    if (joystick_right()) m_current = Root_Other;
}

void menu_other() {

    write_LCD("Other", "w.i.p.");

    if (joystick_left()) m_current = Root_Settings;
    if (joystick_right()) m_current = Root_Search;
}

void menu_s_other() {

    write_LCD("Search:", "Other");

    if (joystick_left()) m_current = Search_Tools;
    if (joystick_right()) m_current = Search_electrical;

    if (joystick_up()) m_current = Root_Search;

}

void menu_s_electrical() {

    write_LCD("Search:", "Electrical");

    if (joystick_left()) m_current = Search_other;
    if (joystick_right()) m_current = Search_Tools;

    if (joystick_up()) m_current = Root_Search;
}

void menu_s_tools() {

    write_LCD("Search:", "Tools");

    if (joystick_left()) m_current = Search_electrical;
    if (joystick_right()) m_current = Search_other;

    if (joystick_up()) m_current = Root_Search;
}

