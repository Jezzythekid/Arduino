//
// Created by Eigenaar on 2-2-2024.
//

#ifndef SORTSYSTEMV2_LCD_H
#define SORTSYSTEMV2_LCD_H

typedef struct {
    const char *textUp;
    const char *textDown;

} lcdText_t;

enum {

    LCD_RS = 12,
    LCD_Enable = 11,

    LCD_D4 = 10,
    LCD_D5 = 9,
    LCD_D6 = 8,
    LCD_D7 = 7

};

/// Function that initializes the LCD display
void setup_LCD();

/// Function writes a string to an LCD display
/// @param string to write
/// @param row row to write
void write_LCD(lcdText_t *text);

#endif //SORTSYSTEMV2_LCD_H
