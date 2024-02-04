//
// Created by Eigenaar on 3-2-2024.
//

#ifndef SORTSYSTEMV2_SCREENS_H
#define SORTSYSTEMV2_SCREENS_H

#include "LCD.h"

#define NUMBER_OF_SCREENS 7

/*
lcdText_t screens[NUMBER_OF_SCREENS] = {
        {"Resistors", ""},
        {"Diodes", ""},
        {"Capacitors", ""},
        {"Transistors", ""},
        {"Headers", ""},
        {"Switches", ""},
        {"IC's", ""},
};
*/

const char* components[NUMBER_OF_SCREENS] = {"Resistors","Diodes","Capacitors",
                                             "Transistors","Headers","Switches","IC's"};

// @todo add other subtexts
const char* values[NUMBER_OF_SCREENS][20] = {
                                {"10 100 1K","10K 100K 1M","150","200, 2K, 20K",
                                 "22, 220, 2K2","220K", "270", "300K", "3K3", "47, 470, 4k7",
                                 "47k, 470k", "510, 5K1, 51K", "68, 680, 6k8", "680k"},
                                {"Regular", "LED's"},
                                {""},
                                {""},
                                {""},
                                {""},
                                {""}
};

const int listLength[NUMBER_OF_SCREENS] {13, 2, 1, 1, 1, 1,1};

enum {
    RESISTOR,
    DIODES,
    CAPACITORS,
    TRANSISTORS,
    HEADERS,
    SWITCHES,
    ICS
};

#endif //SORTSYSTEMV2_SCREENS_H
