const int BLINK_L = 2;
const int BLINK_R = 3;
const int HEADLIGHTS = 4;
const int BTN_LIGHTS_L = 5;
const int BTN_LIGHTS_R = 6;
const int SWITCH_HEADLIGHTS = 7;
const int SWITCH_LIGHTFUNCTION = 8;

const int BLINK_SPEED = 200;

void setup() {
  // put your setup code here, to run once:

  pinMode(BLINK_L, OUTPUT);
  pinMode(BLINK_R, OUTPUT);
  pinMode(HEADLIGHTS, OUTPUT);

  pinMode(BTN_LIGHTS_L, INPUT);
  pinMode(BTN_LIGHTS_R, INPUT);
  pinMode(SWITCH_HEADLIGHTS, INPUT);
  pinMode(SWITCH_LIGHTFUNCTION, INPUT);

}

// function thats blinks BLINK_L with the frequency of freq
void blinkLeft(int freq);

// function that blinks at a set blinkPattern
void warning();

// function thats blinks BLINK_R with the frequency of freq
void blinkRight(int freq);

// function that toggles HEADLIGHTS eacht time the function is called
void toggleLights();

// funcion that checks if pinNo had been pressed (only use function for one pin)
bool left_button_pressed(int pinNo);

// funcion that checks if pinNo had been pressed (only use function for one pin)
bool right_button_pressed(int pinNo);

void loop() {
  // put your main code here, to run repeatedly:

  static bool toggleLeft = true;
  static bool toggleRight = false;
  static bool lightFunction = false;

  // *****************BLINKER LEFT*********************
  // toggle blinking left
  if (left_button_pressed(BTN_LIGHTS_L)) {

    // turn off right blinker if left is blinking
    if (toggleRight) {
      toggleRight = false;
    }
    toggleLeft = !toggleLeft;
  }

  // turn off blinker when blinking is turned off
  if (toggleLeft && !lightFunction) blinkLeft(BLINK_SPEED);
  else if (!lightFunction) digitalWrite(BLINK_L, false);


// *****************BLINKER RIGHT*********************
// toggle blinking right
  if (right_button_pressed(BTN_LIGHTS_R)) {

    // turn off left blinker if right is blinking
    if (toggleLeft) {
      toggleLeft = false;
    }

    toggleRight = !toggleRight;
  }

  // turn off blinker when blinking is turned off
  if (toggleRight && !lightFunction) blinkRight(BLINK_SPEED);
  else if (!lightFunction) digitalWrite(BLINK_R, false);


  //*****************HEADLIGHTS***********************
  // toggle HEADLIGHTS with SWITCH_HEADLIGHTS
  if (digitalRead(SWITCH_HEADLIGHTS)) digitalWrite(HEADLIGHTS, true);
  else digitalWrite(HEADLIGHTS, false);

  //*****************FUCTION**************************
  if (digitalRead(SWITCH_LIGHTFUNCTION)) {

    lightFunction = true;
    warning();
  } 
  else lightFunction = false;
  
}

void blinkLeft(int freq) {
  static int start;
  static int mem = false;
  int buff = millis() - start;


  if (buff > freq) {

    start = millis();

    mem = !mem;

    digitalWrite(BLINK_L, mem);

  
  }

}

// the blinkPattern of the blinking 
const bool blinkPattern[10] = {0,1,0,1,0,1,0,0,0,1};

void warning() {
  static int start = 0;
  static int mem = false;
  int buff = millis() - start;


  // switch case, cycles through the indexes in the array
  switch (buff) {
    case 0 ... 50:
      digitalWrite(BLINK_L, blinkPattern[0]);
      digitalWrite(BLINK_R, blinkPattern[0]);
      break;

    case 51 ... 100:
      digitalWrite(BLINK_L, blinkPattern[1]);
      digitalWrite(BLINK_R, blinkPattern[1]);
      break;

    case 101 ... 150:
      digitalWrite(BLINK_L, blinkPattern[2]);
      digitalWrite(BLINK_R, blinkPattern[2]);
      break;

    case 151 ... 200:
      digitalWrite(BLINK_L, blinkPattern[3]);
      digitalWrite(BLINK_R, blinkPattern[3]);
      break;
    
    case 201 ... 250:
      digitalWrite(BLINK_L, blinkPattern[4]);
      digitalWrite(BLINK_R, blinkPattern[4]);
      break;

    case 251 ... 300:
      digitalWrite(BLINK_L, blinkPattern[5]);
      digitalWrite(BLINK_R, blinkPattern[5]);
      break;

    case 301 ... 400:
      digitalWrite(BLINK_L, blinkPattern[6]);
      digitalWrite(BLINK_R, blinkPattern[6]);
      break;

    case 401 ... 500:
      digitalWrite(BLINK_L, blinkPattern[7]);
      digitalWrite(BLINK_R, blinkPattern[7]);
      break;

    case 501 ... 600:
      digitalWrite(BLINK_L, blinkPattern[8]);
      digitalWrite(BLINK_R, blinkPattern[8]);
      break;

    case 601 ... 650:
      digitalWrite(BLINK_L, blinkPattern[9]);
      digitalWrite(BLINK_R, blinkPattern[9]);
      start = millis();
      break;
  }

  if (buff > 651) start = millis();

}

void blinkRight(int freq) {

  static int start = 0;
  static bool mem = false;
  int buff = millis() - start;


  if (buff > freq) {

    start = millis();

    mem = !mem;

    digitalWrite(BLINK_R, mem);

  
  }

}

void toggleLights() {

  static bool state = false;

  state = !state;

  digitalWrite(HEADLIGHTS, state);

  Serial.println(state);

}

bool right_button_pressed(int pinNo) {

  static bool output;
  static bool buffer;
  bool input = digitalRead(pinNo);

  delay(5); //To counteract bouncing

  if (input && !output && !buffer) {
    output = true;
    buffer = true;
  } else output = false;

  if (buffer && !input) {
    buffer = false;
  }

  return output;
}

bool left_button_pressed(int pinNo) {

  static bool output;
  static bool buffer;
  bool input = digitalRead(pinNo);

  delay(5); // To counteract bouncing 

  if (input && !output && !buffer) {
    output = true;
    buffer = true;
  } else output = false;

  if (buffer && !input) {
    buffer = false;
  }

  return output;
}