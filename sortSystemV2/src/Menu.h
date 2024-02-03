//
// Created by Eigenaar on 2-2-2024.
//

#ifndef SORTSYSTEMV2_MENU_H
#define SORTSYSTEMV2_MENU_H

enum {

    Root_Search = 1,
    Root_Settings = 2,
    Root_Other = 3,

    Search_other = 11,
    Search_electrical = 12,
    Search_Tools = 13,

};

void menu_show();

void menu_search_item();

void menu_settings();

void menu_other();

void menu_s_other();
void menu_s_electrical();
void menu_s_tools();

#endif //SORTSYSTEMV2_MENU_H
