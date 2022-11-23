int Segment = 1;
int Knop = 12;
int vLed = 0;
int vKnop = 0;
int Status = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Knop, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  vKnop = digitalRead(Knop);
  
  if (vKnop) {
    switch (Status) {
      case 0:
        WaitRelease();
      break;
      case 1:
        WaitRelease();
      break;
      case 2:
        WaitRelease();
      break;
      case 3:
        WaitRelease();
      break;
      case 4:
        WaitRelease();
      break;
      case 5:
        WaitRelease();
      break;
      case 6:
        WaitRelease();
      break;
      case 7:
        WaitRelease();
      break;
      case 8:
        Status = 0;
        Serial.println(Status);
        while (vKnop) {
          delay(20);
          vKnop = digitalRead(Knop);
          }
          Segment = 2;
      break;
    }
  }
  // debug
}

void WaitRelease() {
  Status++;
  Segment++;
  Serial.println(Status);
  Serial.println(Segment);
  digitalWrite(Segment, 1);

  while (vKnop) {
          delay(20);
          vKnop = digitalRead(Knop);
  }
}