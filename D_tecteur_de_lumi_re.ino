// Pin definitions
const int lightSensorLeft = A0;
const int lightSensorRight = A1;
const int leftMotorForward = 3;
const int leftMotorBackward = 4;
const int rightMotorForward = 5;
const int rightMotorBackward = 6;

void setup() {
  pinMode(lightSensorLeft, INPUT);
  pinMode(lightSensorRight, INPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValueLeft = analogRead(lightSensorLeft);
  int lightValueRight = analogRead(lightSensorRight);

  if (lightValueLeft > 600 || lightValueRight > 600) {
    if (lightValueLeft > lightValueRight) {
      // Move towards left light
      moveLeft();
    } else {
      // Move towards right light
      moveRight();
    }
  } else {
    stop();
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

void stop() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
