// C++ code

#include <Servo.h>
//Red LED pin 7
//Sensor and motor power 5V
//Define temperature A4
int red = 7;
int temp = A4;


Servo servo_9;
int position = 0;  //states position of the servo
int previousPosition;

void setup() {
  pinMode(temp,INPUT); //Temperature changes
  pinMode(red, OUTPUT);  //Reacts to the change of the temperature
  servo_9.attach(9);    //Servo is attached to pin 9
  
  
//Serial.begin(9600);
}

void loop(){
  int tempReading = analogRead(temp);
  float voltage = tempReading * 5.0;  //if temperature is 5 degrees
  
  //converts voltage 10mv per degree
  voltage /= 1024;
  float tempC = (voltage - 0.5) * 100;
  
  int position = map(tempC, 0, 50, 0, 180);
  Serial.println(position);
  if(previousPosition != position) {
    servo_9.write(position);
    digitalWrite(red, HIGH);
    delay(1000);

  }

}
//void setup()
//{
//servo_9.attach(9, 500, 2500);
//}

//void loop()
//{
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  //for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    //servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    //delay(15); // Wait for 15 millisecond(s)
  //}
  //for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    //servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    //delay(15); // Wait for 15 millisecond(s)
  //}
//}