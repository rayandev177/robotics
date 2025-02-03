// Pin definitions
const int leftLineSensor = A0;
const int rightLineSensor = A1;
const int leftMotorForward = 3;
const int leftMotorBackward = 4;
const int rightMotorForward = 5;
const int rightMotorBackward = 6;

void setup() {
  pinMode(leftLineSensor, INPUT);
  pinMode(rightLineSensor, INPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(leftLineSensor);
  int rightSensorValue = analogRead(rightLineSensor);

  if (leftSensorValue < 500 && rightSensorValue > 500) {
    // Turn left
    moveLeft();
  } else if (leftSensorValue > 500 && rightSensorValue < 500) {
    // Turn right
    moveRight();
  } else {
    moveForward();
  }
}

void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void moveLeft() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void moveRight() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
}
