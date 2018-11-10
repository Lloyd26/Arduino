const int btn[] = {0, 1};
const int led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const int led1[] = {2, 3, 4, 5, 6};
const int led2[] = {7, 8, 9, 10, 11, 12};

int Sbtn0;
int Sbtn1;
int lSbtn0 = LOW;
int lSbtn1 = LOW;

int ledState0 = LOW;
int ledState1 = LOW;

unsigned long lDbT0 = 0;
unsigned long lDbT1 = 0;
unsigned long dD0 = 50;
unsigned long dD1 = 50;

int r0 = digitalRead(btn[0]);
int r1 = digitalRead(btn[1]);

void setup() {
  for (int i = 0; i <= 1; i++) {
    pinMode(btn[i], INPUT);
  }
  for (int i = 0; i <= 11; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
}

void loop() {
  click(0);
    lSbtn0 = r0;
    lSbtn1 = r1;
    for (int i = 0; i <= 4; i++) {
          digitalWrite(led[i], ledState0);
          lSbtn0 = r0;
          delay(100);
    }
}

void click(int pin) {
  if (pin == 0) {
  
  if (r0 != lSbtn0) {
    lDbT0 = millis();
  }
  
  if ((millis() - lDbT0) > dD0) {
    if (r0 != Sbtn0) {
      Sbtn0 = r0;
      
      if (Sbtn0 == HIGH) {
        ledState0 = !ledState0;
      }
    }
  }
  }
  if (pin == 1) {
  
  if (r1 != lSbtn1) {
    lDbT1 = millis();
  }
  
  if ((millis() - lDbT1) > dD1) {
    if (r1 != Sbtn1) {
      Sbtn1 = r1;
      
      if (Sbtn1 == HIGH) {
        ledState1 = !ledState1;
      }
    }
  }
  }
}
