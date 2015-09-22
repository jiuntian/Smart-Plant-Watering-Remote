//Created by jiuntian.com @2015 version 1.0 
//Use pin2 for water pump/valve ,pin3 for warning Led (optional) ,pin4 for Ok/Idle LED (optional) 
//connect bluetooth module with Tx> RX  ; Rx > TX
//Android application : https://play.google.com/store/apps/details?id=appinventor.ai_jiuntian.PlantWatering
const int analogInPin = A0 ;
int sensorValue = 0;
const int waterPin = 2;//water valve pin
const int drySoilValue = 750; //value of sensor when soil is dry
const int warningLed = 3; //warning led pin , red
const int okPin = 4; //ok pin ,green
const int waterTime = 1000; //time of watering , in ms
//serial ask sensor data code 8
//force water code 9
//bluetooth adapter name HC 06 , password 1234
int data;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(waterPin, OUTPUT);
}
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  //Serial.print(sensorValue);
  //Serial.print("\n");
  if (Serial.available() > 0 ) {
    data = Serial.read();
    if (data == '8') {
      Serial.print(sensorValue);
    }
    if (data == '9') {
      digitalWrite(waterPin, HIGH);
      delay(1000);
      digitalWrite(waterPin, LOW);
    }
  }
  //Warning
  if (sensorValue >= 900 ) {
    digitalWrite(warningLed, HIGH);
    digitalWrite(waterPin, LOW);
    digitalWrite(okPin, LOW);
  }
  //watering
  else if (sensorValue >= drySoilValue) {
    digitalWrite(warningLed, LOW);
    digitalWrite(okPin, LOW);
    digitalWrite(waterPin, HIGH) ;
    delay(waterTime);
  }
  //idle
  else {
    digitalWrite(waterPin, LOW);
    digitalWrite(warningLed, LOW);
    digitalWrite(okPin, HIGH);
  }
}
