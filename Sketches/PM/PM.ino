int x = 0, y = 0, i = 9;

void setup() {
  for (int a = 4; a <= 13; a++) {
    pinMode(a, OUTPUT);
  }
  for (int a = 6; a <= 9; a++) {
    digitalWrite(a, HIGH);
  }
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    x += 1;
    delay(200);
  }
  if (x == 3) {
    i += 1;
    digitalWrite(i, HIGH);
    x = 0;
  }

  if (digitalRead(3) == HIGH) {
    y += 1;
    delay(200);
  }
  if (y == 3) {
    digitalWrite(i, LOW);
    i -= 1;
    y = 0;
  }

  if (i == 5 || i < 5) {
    digitalWrite(4, HIGH);
    i = 5;
  } else if (i == 13 || i > 13) {
    digitalWrite(5, HIGH);
    i = 13;
  }
  else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
