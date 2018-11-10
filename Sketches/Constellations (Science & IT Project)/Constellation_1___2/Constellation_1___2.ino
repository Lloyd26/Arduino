const int btn[] = {0, 1};
const int led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int led1[] = {2, 3, 4, 5, 6};
const int led2[] = {7, 8, 9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i <= 1; i++) {
    pinMode(btn[i], INPUT);
  }
  for (int i = 0; i <= 11; i++) {
    pinMode(led[i], OUTPUT);
  }
  for (int i = 0; i <= 11; i++) {
      digitalWrite(led[i], LOW);
  }
}

void loop(){
  if (digitalRead(btn[0]) == HIGH) {
    for (int i = 0; i <= 4; i++) {
      digitalWrite(led1[i], HIGH);
    }
    for (int i = 0; i <= 6; i++) {
      digitalWrite(led2[i], LOW);
    }
  }
  else if (digitalRead(btn[1]) == HIGH) {
    for (int i = 0; i <= 6; i++) {
      digitalWrite(led2[i], HIGH);
    }
    for (int i = 0; i <= 4; i++) {
      digitalWrite(led1[i], LOW);
    }
  }
  else {
    for (int i = 0; i <= 11; i++) {
      digitalWrite(led[i], LOW);
    }
  }
}

