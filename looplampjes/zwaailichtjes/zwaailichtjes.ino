int vKnop = 0;
int Knop = 13;
int Schakelaar = 12;
int vSchakelaar = 0;
int status = 1;

void setup() {
  // led's als output
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }

  // Serial
  Serial.begin(9600);

  //overig
  pinMode(Knop, INPUT);
  pinMode(Schakelaar, INPUT);
}

void WaitRelease() {
  vKnop = digitalRead(Knop);
  while (vKnop) {
          delay(20);
          vKnop = digitalRead(Knop);
  }
}

void NightRider() {
  // looplichtje zoals nightrider

  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, 1);

    //verkomen van storing met andere Q's
    if (i < 8) {
    digitalWrite(i + 1, 1);
    digitalWrite(i + 2, 1);
    }

    //de laatste led uitschakelen
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

void Zwaailicht() {
  for (int i = 0; i <= 5; i++) {
    digitalWrite(10, 1);
    delay(40);
    digitalWrite(10,0);
    delay(40);
  }
  delay(10);
  for (int i = 0; i <= 5; i++) {
    digitalWrite(11, 1);
    delay(40);
    digitalWrite(11,0);
    delay(40);
  }

}

void loop() {
  vSchakelaar = digitalRead(Schakelaar);
  if (vSchakelaar) {
    Zwaailicht();
  }
  else {
    NightRider();
  }
  Serial.println(vSchakelaar);
}
