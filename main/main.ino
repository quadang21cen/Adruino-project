#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
char msg;
char call;
boolean st_led = false;
int led = 13;
int sensorPin=12;
int ledST = 0;
boolean val=1;   // 0 is sound, 1 is not
boolean Fan_Signal = 1; 

void setup(){
  Serial.println("GSM SIM800A BEGIN");
  pinMode(sensorPin,INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  delay(100);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
}

void loop(){
  val=digitalRead(sensorPin);   // sound sensor
  Serial.println(val);
  delay(1000);
  Serial.println(val);
  if (val == 1){
    Serial.println(val);
    int i = 0;
    int num_of_DIFF = 0;
    do{
      val=digitalRead(sensorPin);
      Serial.println(val);
      if (val == 1) num_of_DIFF ++;
      delay(500);
      i++;
    }while(i<=20);

    int check = 20 - num_of_DIFF;
    if(check > 2){
      Serial.println("Hoat Dong");
//      
      Serial.println(num_of_DIFF);
    }else{
      Serial.println("khong hoat dong");
      MakeCall();
    }
  }
  
  

  
//  if (val != new_sensor){
//    int i = 0;
//    int num_of_DIFF = 0;
//    do{
//        new_sensor = digitalRead(sensorPin);
//        Serial.println(new_sensor);
//        delay(1000);
//        if (new_sensor != val){
//           num_of_DIFF ++;
//        }
//        i++;
//    }while(i<=10);
//    Serial.println("TURN OFF");
//    if (num_of_DIFF >= 5){
//        if(ledST == 0){
//          digitalWrite(led, HIGH);
//          int ledST = 1;
//        }
//        
//        else {
//          digitalWrite(led, LOW);
//          int ledST = 0;
//        }
//    }
  }
  
  



  
//  
//  Serial.println(mySerial.read());
//  Serial.println(analogRead(A0));
//  if (Serial.available()>0)
//   switch(Serial.read()){
//    case 's':
//      SendMessage();
//      break;
//    case 'c':
//      MakeCall();
//      break;
//    case 'h':
//      HangupCall();
//      break;
//    case 'e':
//      RedialCall();
//      break;
//    case 'i':
//      ReceiveCall();
//      break;
//    case 'r':
//      ReceiveMessage();
//      break;
//  }
//  
// if (mySerial.available()>0){
//  if (st_led == false){
//    st_led = true;
//    digitalWrite(led, HIGH);
//  }else {
//    st_led = false;
//    digitalWrite(led, LOW);
//  }
//    Serial.write(mySerial.read());
//  do{
//  Serial.println(mySerial.read());
//  delay(1000);
// }while(mySerial.read()>0);
//  }
//  delay(100);


void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+YYxxxxxxxxxx\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("sim800a sms");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

void ReceiveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
  if (mySerial.available()>0)
  {
    msg=mySerial.read();
    Serial.print(msg);
  }
}

void MakeCall()
{
  mySerial.println("ATD+84946345543;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling  "); // print response over serial port
  delay(1000);
}


void HangupCall()
{
  mySerial.println("ATH");
  Serial.println("Hangup Call");
  delay(1000);
}

void ReceiveCall()
{
  mySerial.println("ATA");
  delay(1000);
  {
    call=mySerial.read();
    Serial.print(call);
  }
}

void RedialCall()
{
  mySerial.println("ATDL");
  Serial.println("Redialing");
  delay(1000);
}


void checkStatus(){
  char st_A[100] = "STATUS A is OK"  ;
  char st_B[100] = "STATUS B is ERR" ;
  SendMessage();

}

void ctr_led(){
if (st_led == true) {
  digitalWrite(led, HIGH);
  st_led = false;
}
else {
  digitalWrite(led, LOW);
  st_led = true;
}

}
