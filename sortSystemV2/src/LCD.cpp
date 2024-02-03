//
// Created by Eigenaar on 2-2-2024.
//

#include "Arduino.h"
#include "LCD.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup_LCD() {

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Initializing...");
    delay(5);
    lcd.clear();

}

void write_LCD(lcdText_t *text){

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(text->textUp);

    lcd.setCursor(0, 1);
    lcd.print(text->textDown);


}

