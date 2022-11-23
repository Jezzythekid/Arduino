int Segment = 1;
int Knop = 10;
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
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}

void loop() {
  for (int a = 10; a < 14; a++) {
    digitalWrite(a, 0);
    digitalWrite(a+1, 1);
    digitalWrite(a+2, 1);
    digitalWrite(a+3, 1);
    Serial.print("Digit: ");
    Serial.println(a - 9);

    for (int i = 2; i < 10; i++) {
      digitalWrite(i, 1);
      Serial.print("segment: ");
      Serial.println(i);
      delay(250);
      if (i > 2); {
        digitalWrite(i, 0);
      }
    }

    Serial.println(" ");
    digitalWrite(a, 1);
  }
}
