const int trigPin = 3;
const int echoPin = 4;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //clear trigpin
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  //pulse trig
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  //lezen echo
  duration = pulseIn(echoPin, 1);
  //berekenen afstand
  distance = duration * 0.034 / 2;
  //print
  Serial.print(duration);
  Serial.print(" Afstand in CM: ");
  Serial.println(distance);
}
