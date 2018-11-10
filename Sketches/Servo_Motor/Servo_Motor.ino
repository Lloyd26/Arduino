#include <Servo.h>

const int buttonPin = 3;
const int buttonPin2 = 5;

int buttonState = 0;
int buttonState2 = 0;

Servo servoA;

int position = 0;

void setup() {
servoA.attach(9);
pinMode(buttonPin, INPUT);
pinMode(buttonPin2,INPUT);

}

void loop() {
buttonState = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);

if(buttonState == HIGH && position < 180){
servoA.write(position++);
delay(5);
}

if(buttonState2 == HIGH && position > 3){
servoA.write(position--);
delay(5);
}

}
