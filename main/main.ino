#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
char msg;
char call;
boolean st_led = false;
int led = 13;

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("GSM SIM800A BEGIN");
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  delay(100);
}

void loop(){
//Serial.println(st_led);
Serial.println(mySerial.read());
delay(1000);
//if (mySerial.available()>0){
//    Serial.println("RING");
//    if (st_led = false) st_led = true;
//    else st_led = false;
//    if (st_led = true) digitalWrite(led, HIGH);
//    else digitalWrite(led, LOW);
//    
//    while (mySerial.read()>0){
//    delay(1000);
//    }
//  }
}
void check_sign(){
  if (st_led = false) st_led = true;
  else st_led = false;
  while (mySerial.read()>0){
    delay(1000);
  }
}
