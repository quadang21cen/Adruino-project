
int sensorPin=7;
boolean val=1;   // 0 is sound, 1 is not

void setup(){
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}
 
void loop(){
 delay(1000);
 val=digitalRead(sensorPin);
 Serial.println(val);
}
