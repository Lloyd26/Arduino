#include <ATX2.h>

int sensorpin = 30;
int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(sensorpin);
  Serial.println(value);
  delay(500);
  
  if (digitalRead(28) == HIGH) {
    motor(1, -20);
    motor(3, 20);
  }
  else if (digitalRead(30) == HIGH) {
    motor(1, 20);
    motor(3, -20);
  }
  else {
    motor(1, -20);
    motor(3, -2);
    
    
  }
}

