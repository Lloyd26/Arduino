/*
 * IR Sensor
 * Version: 2.1
 * Written by: Lloyd Refuerzo
 * 
 */

// ----------------
// MAKE SURE TO SET
// THE RIGHT COURSE
// FOR YOUR ROBOT!!
// ----------------

// Type "AB" (right)
// or "BA" (left)
int course = "BA";

// Declare variables for motors
const int LF = 3;  // Left Forward
const int LB = 5;  // Left Backward
const int RF = 6;  // Right Forward
const int RB = 9;  // Right Backward

// Set IR sensor to pin 7
const int IR = 7;

// Initialize the sensor reading
int IR_detected = 0;

// Motorspeed for calibration
int Lspeed = 255; 
int Rspeed = 255;

// Delay for turning
int rotateDelay = 250;

void setup() {
  // Set motors to output mode
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);

  // Set IR sensor to input mode
  pinMode(IR, INPUT);
}

void loop() {
  /*  
   * If the IR sensor detected
   * an obstacle, the robot will
   * go left / right
   * (depending on your course),
   * else if the sensor detects
   * nothing, the robot will
   * go straight ahead (forward).
   */

  // Read the value
  // from the IR sensor

  IR_detected = digitalRead(IR);

  if (IR_detected == LOW) {
    /*if (course != "AB" || course != "BA" || !course) {
      // Return an error
      return;
    }*/
    if (course == "AB") {
       // Backward
       analogWrite(LF, LOW);
       analogWrite(LB, Lspeed);
       analogWrite(RF, LOW);
       analogWrite(RB, Rspeed);
       delay(1000);
       // Turn right
       analogWrite(LF, Lspeed);
       analogWrite(LB, LOW);
       analogWrite(RF, LOW);
       analogWrite(RB, Rspeed);
       delay(rotateDelay);
    }
    if (course == "BA") {
      // Turn left
      analogWrite(LF, LOW);
      analogWrite(LB, Lspeed);
      analogWrite(RF, LOW);
      analogWrite(RB, Rspeed);
      delay(1000);
      analogWrite(LF, LOW);
      analogWrite(LB, Lspeed);
      analogWrite(RF, Rspeed);
      analogWrite(RB, LOW); 
      delay(rotateDelay);
    }
  }
  else {
    // Go straight forward
    analogWrite(LF, Lspeed);
    analogWrite(LB, LOW);
    analogWrite(RF, Rspeed);
    analogWrite(RB, LOW);
  }
  
}

