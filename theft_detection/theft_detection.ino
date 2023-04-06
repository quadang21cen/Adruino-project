#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
char msg;
char call;
int sensor_val;
boolean st_led = false;
int led = 13;

int ledST = 0;
int val=700;   // 0 is sound, 1 is not
boolean Fan_Signal = 1; 

void setup() 
{
  Serial.println("GSM SIM800A BEGIN");
  delay(100);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  /*Serial.println(digitalRead(3));*/
  sensor_val = analogRead(A3);
  Serial.println(sensor_val);
  if (sensor_val > 600){
    Serial.println("> 600");
    int num = 0;
    int i = 0;
    do{ 
      i = i + 1;
      sensor_val = analogRead(A3);
      if (sensor_val > 600){
        num = num + 1;
      }
      Serial.println(sensor_val);
      delay(1000);
    }while(i< 10);
    Serial.println("BREAK");
    Serial.println(num);
    if (num >=3){
      MakeCall();
      delay(10000);
    }
    delay(1000);
  }
  delay(1000);
}



void MakeCall()
{
  mySerial.println("ATD+84946345543;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}
