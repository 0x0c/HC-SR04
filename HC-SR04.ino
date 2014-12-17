int Echo = 14;
int Trig = 15;
int Duration;
float Distance;

void setup() {
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
}

void loop() {
  digitalWrite(Trig,LOW);
  delayMicroseconds(1);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(1);
  digitalWrite(Trig,LOW);
  Duration = pulseIn(Echo,HIGH);
  if (Duration>0) {
    Distance = Duration/2;
    Distance = Distance * 340 * 0.0001; // ultrasonic speed is 340m/s = 34000cm/s = 0.034cm/us
    Serial.write((int)floor(Distance));
  }
}
