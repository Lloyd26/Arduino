#include <IRremote.h>

int IR_Recv = 2;

IRrecv irrecv(IR_Recv);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    long int decCode = results.value;
    Serial.println(decCode);

    switch (results.value) {
      case 16724175:  // Button 1 on remote
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      break;

      case 16718055:  // Button 2 on remote
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      break;

      case 16743045:  // Button 3 on remote
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      break;

      case 16738455:  // Button 0 on remote
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      break;

      case 16716015:  // Button 4 on remote
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      break;

      default:
      break;
    }
    irrecv.resume();
  }
}

