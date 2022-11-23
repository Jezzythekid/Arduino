int Status = 0;
int Tijd = 0;   //Tijd = Time

byte Nummers[10][8] {
  {1,1,1,0,1,1,0,1}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,0,1,1,1,0}, //2
  {1,1,1,0,1,0,1,0}, //3
  {0,1,1,0,0,0,1,1}, //4
  {1,0,1,0,1,0,1,1}, //5
  {1,0,1,0,1,1,1,1}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,0,1,1,1,1}, //8
  {1,1,1,0,1,0,1,1}  //9
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  Tijd = 20;

  for (int i = 0; i < 10; i++) {
    for (int a = 0; a < Tijd; a++){
      WriteDigit(0, 0, 0, i);
    }
  }
}

int WriteDigit(int D1, int D2, int D3, int D4) {
  int digit[] {D1, D2, D3, D4};

  for (int i = 0; i < 4; i++) {
    digitalWrite(i + 10, 0);
    
    for (int a = 2; a < 10; a++) {
      digitalWrite(a, Nummers[digit[i]][a-2]);
    }

    delay(2);

    for (int a = 2; a < 10; a++) {
      digitalWrite(a, 0);
    }
    Serial.println(" ");
    digitalWrite(i + 10, 1);
  }
}
