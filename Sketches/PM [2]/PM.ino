int x = 0, y = 0, i = 4;

void setup() {
  for (i = 4; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  for (i = 4; i <= 8; i++) {
    digitalWrite(i, HIGH);
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
    y -= 1;
    delay(200);
  }
  if (y == 3) {
    digitalWrite(i, LOW);
    i -= 1;
    y = 0;
  }
}
