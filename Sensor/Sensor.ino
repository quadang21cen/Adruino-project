
int sensorPin=7;
boolean val=1;   // 0 is sound, 1 is not
int led = 13;
void setup(){
  pinMode(sensorPin,INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}
 
void loop(){
 val=digitalRead(sensorPin);
 Serial.println(val);
 if (val == 0) digitalWrite(led, HIGH);
 else digitalWrite(led, LOW);
 delay(1000);
 
}
