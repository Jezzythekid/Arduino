//
// Created by Eigenaar on 30-1-2024.
//

#include "Shiftregister.h"
#include "Arduino.h"

void setup_shiftRegister() {

    pinMode(SR1_SER, OUTPUT);
    pinMode(SR1_RCLK, OUTPUT);
    pinMode(SR_SRCLK, OUTPUT);
    pinMode(SR2_SER, OUTPUT);
    pinMode(SR2_RCLK, OUTPUT);

}

void test_shiftRegister() {

        for (unsigned short int i = 0; i < 256; ++i) {

            digitalWrite(SR1_RCLK, LOW);

            shiftOut(SR1_SER, SR_SRCLK, LSBFIRST, i);

            digitalWrite(SR1_RCLK, HIGH);

            delay(500);
        }
}

void trailingLight(int speed) {

    int i = 0;

    while (i < 8) {

        for (int j = 0; j < 4; ++j) {

            coord_to_shiftRegister({j, i});
            delay(speed);
        }

        i++;

        for (int j = 3; j > -1; --j) {

            coord_to_shiftRegister({j, i});
            delay(speed);
        }

        i++;

    }



        //coord_to_shiftRegister({0, i});

}


void write_shiftRegister1(unsigned short int value) {
    digitalWrite(SR1_RCLK, LOW);

    shiftOut(SR1_SER, SR_SRCLK, LSBFIRST, value);

    digitalWrite(SR1_RCLK, HIGH);
}

void write_shiftRegister2(unsigned short int value) {
    digitalWrite(SR2_RCLK, LOW);

    shiftOut(SR2_SER, SR_SRCLK, LSBFIRST, value);

    digitalWrite(SR2_RCLK, HIGH);
}

void coord_to_shiftRegister(coord_t coord) {

    int sr1 = B11111111;
    int sr2 = B00000000;

    write_shiftRegister1(bitClear(sr1, 7 - coord.y));
    write_shiftRegister2(bitSet(sr2, 7 - coord.x));


}

void blink_coordinate(coord_t coord) {

    coord_to_shiftRegister(coord);
    delay(200);
    coord_to_shiftRegister({8, 8});
    delay(200);

}