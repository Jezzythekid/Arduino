int Segment = 1;
int Knop = 11; 	//Knop = Button
int vLed = 0;
int vKnop = 0;	//vKnop = vButton
int Status = 1;

void setup() {
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
  vKnop = digitalRead(Knop);
  
  //for (int i = 2; i <= 9; i++) {
  //digitalWrite(i-1, 0);
	//digitalWrite(i, 1);
  //delay(500);
  //}
  //digitalWrite(9, 0);

  if (vKnop) {
    while (vKnop){
      vKnop = digitalRead(Knop);
      delay(30);
    }
    if (Status == 9) {
      Status = 2;
      digitalWrite(9, 0);
    }
    else {
      Status++;
      Serial.println(Status);
    }
    digitalWrite(Status, 1);
    digitalWrite(Status-1, 0);
  }
}
