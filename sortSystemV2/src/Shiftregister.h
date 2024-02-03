//
// Created by Eigenaar on 30-1-2024.
//

#ifndef SORTSYSTEMV2_SHIFTREGISTER_H
#define SORTSYSTEMV2_SHIFTREGISTER_H

enum {

    SR1_SER = 2,
    SR1_RCLK = 3,    ///aka latch

    SR_SRCLK = 4,

    SR2_SER = 5,
    SR2_RCLK = 6,

    // input

    BTN1 = 12,
    BTN2 = 13
};

typedef struct {
    int x;
    int y;
} coord_t;

/// Function that setups the shift registers;
void setup_shiftRegister();

/// Function to test the wiring of a shift register
/// lets the output count in binary.
void test_shiftRegister();

/// Function that lets the output trail from left to right
/// uses delay because why not
void trailingLight(int speed);

/// Function that writes to a shift register
/// @param value the value to write to the shiftregister
void write_shiftRegister1(unsigned short int value);

/// Function that writes to a shift register
/// @param value the value to write to the shiftregister
void write_shiftRegister2(unsigned short int value);

/// Function writes the coordinate to the shift registers
/// @param coord coordinate to write
void coord_to_shiftRegister(coord_t coord);

/// Function blinks the coordinate to the shift registers
/// @param coord coordinate to blink
void blink_coordinate(coord_t coord);

#endif //SORTSYSTEMV2_SHIFTREGISTER_H
