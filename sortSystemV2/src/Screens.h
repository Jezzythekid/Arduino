//
// Created by Eigenaar on 3-2-2024.
//

#ifndef SORTSYSTEMV2_SCREENS_H
#define SORTSYSTEMV2_SCREENS_H
#include "Menu.h"



screenType_t st_Main = {0, 1};
screenType_t st_Home = {TYPE_HOME, SCREENS_HOME};
screenType_t st_Search = {TYPE_SEARCH, SCREENS_SEARCH};
screenType_t st_Lights = {TYPE_LIGHTS, SCREENS_LIGHTS};
screenType_t st_Settings = {TYPE_SETTINGS, SCREENS_SETTINGS};


screen_t s_MAIN = {
        MAIN,
        st_Main,
        "Sorting system",
        "Work in progress",
        HOME_SEARCH
};

screen_t s_HOME[3] = {
        {
            HOME_SEARCH,
            st_Home,
            "Search",
            "",
            TYPE_SEARCH
        },{
            HOME_LIGHTS,
                st_Home,
            "Lights",
            "",
            TYPE_LIGHTS
        }, {
            HOME_SETTINGS,
                st_Home,
            "Settings",
            "",
            TYPE_SETTINGS
        }

};

#endif //SORTSYSTEMV2_SCREENS_H
