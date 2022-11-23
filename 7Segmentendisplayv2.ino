

int Segment = 1;
int Knop = 10;
int vLed = 0;
int vKnop = 0;
int Status = 0;

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

void WriteSegment() {
  for (int i = 0; i <= 7; i++) {
    digitalWrite(i+2,Nummers[Status][i]);
  }
  Serial.print("Wrote to display: ");
  Serial.println(Status);
}

void Step() {
  if (Status == 9) {
      Status = 0;}
    else {
      Status++;}
}

void loop() {
  // doorlopen van de stappen.
  vKnop = digitalRead(Knop);

  if (vKnop) {
    while (vKnop){
      vKnop = digitalRead(Knop);
      delay(30);
      }
    Step();
    WriteSegment();
  }
}