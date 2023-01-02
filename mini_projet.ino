#include <Servo.h>
const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino
const int ledPin=13;
const int ledPinn = 12;
const int digitalPin = 2;
const int analogPin = A1;

//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;
int digitalVal;
int analogVal; 
Servo servo;




void setup() {
	Serial.begin(9600);//sets the baud rate
	pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
	pinMode(ledPin, OUTPUT);
  //sets the pin as an output of the arduino
   pinMode(ledPinn, OUTPUT);
  pinMode(digitalPin, INPUT);
  
  Serial.println(F("Flame Sensor Initialized"));
}
void setupp() {
    servo.attach(7);
    servo.write(180);
    delay(2000);
}



 void readFlameSensor(){
    // Read the digital interface
  digitalVal = digitalRead(digitalPin);
  if (digitalVal == HIGH){
    digitalWrite(ledPinn, HIGH);
    Serial.println(F("    -> Flame detected"));
  }else{
    digitalWrite(ledPinn, LOW); 
  }
 }

void loop()
{
  value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
	limit= digitalRead(DOUTpin);//reads the digital value from the CO sensor's DOUT pin
	Serial.print("CO value: ");
	Serial.println(value);//prints the CO value
	Serial.print("Limit: ");
	Serial.println(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
	delay(100);
	if (limit == HIGH){
		digitalWrite(ledPin, HIGH);//if limit has been reached, LED turns on as status indicator
	}
	else{
		digitalWrite(ledPin, LOW);//if threshold not reached, LED remains off
	}
  readFlameSensor();
  delay(500);

 

  // Read the analog interface
  analogVal = analogRead(analogPin);
  Serial.println(F("Sensor Value"));Serial.println(analogVal);

delay(1000);
servo.write(90);
    delay(100);
    servo.write(180);
    delay(100);


}



