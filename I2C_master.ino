#include<Wire.h>
//int pingpin=7;
int table[]={0,0};
void setup() {
  pinMode(3,OUTPUT);
  digitalWrite(3,HIGH);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  // put your setup code here, to run once:

}

void loop() {
  delay(100);
  table[0]=read_sensor(7);
  table[1]=read_sensor(5);
  // put your main code here, to run repeatedly:

}
void requestEvent(){
  /*Wire.write(read_sensor(7));
  Wire.write(" ");
  Wire.write(read_sensor(5));
*/
uint8_t Buffer[2];
Buffer[0]=table[0];
Buffer[1]=table[1];
Wire.write(Buffer,2);
}
long read_sensor(int pingpin) {
  long duration, inches, cm;
  pinMode(pingpin, OUTPUT);
  digitalWrite(pingpin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingpin, LOW);


  pinMode(pingpin, INPUT);
  duration = pulseIn(pingpin, HIGH);

  cm = microsecondsToCentimeters(duration);

  return cm;

  delay(100);
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}


