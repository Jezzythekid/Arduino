#include <Stepper.h>
#include <Servo.h>

// stappenmoter spul
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

int StepsRequired;

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
Servo servomotor;


// de rest

int PosStep = 0;
int PosServ = 0;
int PinAx = 0;
int PinAy = 1;
int stap = 0;     // stap = step
int speed = 0;

void setup() {
  Serial.begin(9600);
  servomotor.attach(2);
}

void loop()
{ 
  // Stepper
  PosStep = analogRead(PinAx);
  Serial.print("input: ");
  Serial.println(PosStep);
  if (PosStep < 500) {
    stap = 1;
    speed = 500 - PosStep;
    steppermotor.setSpeed(speed);  
    steppermotor.step(stap);
    Serial.println(speed);
  }
  else if (PosStep > 520) {
    stap = -1;
    speed = PosStep - 500;
    steppermotor.setSpeed(speed);  
    steppermotor.step(stap);
    Serial.println(speed);
  }
  else {
    stap = 0;
  }

  // Servo
  PosServ = analogRead(PinAy);
  PosServ = map(PosServ, 0, 1024, 0, 180);
  servomotor.write(PosServ);
 
}
