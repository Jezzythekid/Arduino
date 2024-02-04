//
// Created by Eigenaar on 2-2-2024.
//

#include "Arduino.h"
#include "LCD.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

unsigned char customCharacters[2][8] = {
        {
                B00000,
                B00000,
                B01110,
                B10001,
                B10001,
                B11011,
                B01010,
                B11011,
        }, {
                B00000,
                B00000,
                B10001,
                B10001,
                B11111,
                B10001,
                B10000,
                B10000,
        }
};

void setup_LCD() {

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Initializing...");
    delay(5);
    lcd.clear();

}

void write_LCD(lcdText_t text){

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(text.textUp);

    lcd.setCursor(0, 1);
    lcd.print(text.textDown);


}

void add_custom_char(int colum, int row, int character) {

    unsigned char *selected;



    switch (character) {
        case OMEGA:
            selected = customCharacters[OMEGA];
            break;
        case MU:
            selected = customCharacters[MU];
            break;
        default:
            return;
    }

    lcd.createChar(0, selected);
    lcd.setCursor(colum, row);
    lcd.write(selected,1);

}
