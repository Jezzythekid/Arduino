int vKnop = 0; 
int Knop = 13;  //Knop = Button
int status = 1;

void setup() {
  // led's als output || led's as output
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }

  // Serial
  Serial.begin(9600);

  //overig
  pinMode(Knop, INPUT);
}

void WaitRelease() {
  vKnop = digitalRead(Knop);
  while (vKnop) {
          delay(20);
          vKnop = digitalRead(Knop);
  }
}

void NightRider() {
  // looplichtje zoals nightrider || animated lights like nightrider

  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, 1);

    //verkomen van storing met andere pin's ||  preventing disturbance with other pin's
    if (i < 8) {
    digitalWrite(i + 1, 1);
    digitalWrite(i + 2, 1);
    }

    //de laatste led uitschakelen || turn off previous led
    digitalWrite(i - 1, 0);
    delay(120);
  }
  digitalWrite(8, 0);
  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, 1);
    digitalWrite(i - 1, 1);
    digitalWrite(i - 2, 1);
    digitalWrite(i + 1, 0);
    delay(120);
  }
  digitalWrite(2, 0);
}

void loop() {
  Serial.println(status);
}
