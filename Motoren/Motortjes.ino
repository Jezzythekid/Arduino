#include <Stepper.h>

// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

int StepsRequired;

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);

void setup() {

}

void loop()
{
  // Slow - 4-step CW sequence to observe lights on driver board
  //steppermotor.setSpeed(1);    
  //StepsRequired  =  4;
  //steppermotor.step(StepsRequired);
  //delay(2000);
 
   // Rotate CW 1/2 turn slowly
  //StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  //steppermotor.setSpeed(100);   
  //steppermotor.step(StepsRequired);
  //delay(1000);
  
  // Rotate CCW 1/2 turn quickly
  //StepsRequired  =  - STEPS_PER_OUT_REV;   
  steppermotor.setSpeed(700);  
  steppermotor.step(4);
 
}