//
// Created by Eigenaar on 2-2-2024.
//

#ifndef SORTSYSTEMV2_MENU_H
#define SORTSYSTEMV2_MENU_H

typedef struct  {
    int type;
    int numberOfScreens;
} screenType_t;

typedef struct {
    int screenNumber;
    screenType_t screenType;

    const char *textUp;

    const char *textDown;
    int submenu;    // 0 for no submenu

} screen_t;

enum {
    MAIN = 0,

    SCREENS_HOME = 3,           ///Number of Screens in HOME
    TYPE_HOME = 100,
    /// Screens:
    HOME_SEARCH = 101,
    HOME_LIGHTS = 102,
    HOME_SETTINGS = 103,

    SCREENS_SEARCH = 4,         ///Number of Screens in SEARCH
    TYPE_SEARCH = 200,
    /// Screens:
    SEARCH_ELECTRICAL = 201,
    SEARCH_OTHER = 202,
    SEARCH_TOOLS = 203,

    SCREENS_LIGHTS = 1,         ///Number of Screens in LIGHTS
    TYPE_LIGHTS = 300,
    /// Screens:
    LIGHTS_WIP = 301,

    SCREENS_SETTINGS = 1,       ///Number of Screens in SETTINGS
    TYPE_SETTINGS = 400,
    /// Screens:
    SETTINGS_WIP = 401,
};

void menu_show();

/*
void menu_search_item();

void menu_settings();

void menu_other();

void menu_s_other();
void menu_s_electrical();
void menu_s_tools();
*/

#endif //SORTSYSTEMV2_MENU_H
