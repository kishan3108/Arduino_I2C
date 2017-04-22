#include<Wire.h>
int table[]={0,0};
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Wire.begin();
  Serial.begin(9600);
}
void loop(){
  Wire.requestFrom(8,4);
  for(int i=0;i<=1;i++){
    int c=Wire.read();
    //Serial.println(c);
    table[i]=c;
    Serial.print('\t');
    }
    //  Serial.println();
      Serial.print(table[0]);
      Serial.print('\t');
      Serial.print(table[1]);
      Serial.println('\t');
      if(table[0]>10 && table[1]>10){
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
      }
      else if(table[0]<10 && table[1]>10){
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
      }
      else if(table[0]>10 && table[1]<10){
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
      }
      else if(table[0]<10 && table[1]<10){
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
      }
  delay(500);
}

