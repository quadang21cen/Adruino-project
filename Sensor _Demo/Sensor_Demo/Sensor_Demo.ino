void setup()
{
  Serial.begin(9600); //bật serial monitor ở mức baudrate 9600
}
 
void loop()
{
  int value = analogRead(A0); //A0 là chân analogA0 á
  Serial.print("Gia tri cam bien: ");
  Serial.println(value);
  delay(500); //delay 100 mới thấy được sự thay đổi
}
