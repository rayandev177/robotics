// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int leftLineSensor = A0;
const int rightLineSensor = A1;
const int leftMotorForward = 3;
const int leftMotorBackward = 4;
const int rightMotorForward = 5;
const int rightMotorBackward = 6;
const int lightSensorLeft = A2;
const int lightSensorRight = A3;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftLineSensor, INPUT);
  pinMode(rightLineSensor, INPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(lightSensorLeft, INPUT);
  pinMode(lightSensorRight, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Obstacle avoidance
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 20) {
    // Obstacle detected
    stop();
    delay(500);
    moveBackward();
    delay(500);
    moveRight();
    delay(500);
  } else {
    // Line following
    int leftSensorValue = analogRead(leftLineSensor);
    int rightSensorValue = analogRead(rightLineSensor);

    if (leftSensorValue < 500 && rightSensorValue > 500) {
      moveLeft();
    } else if (leftSensorValue > 500 && rightSensorValue < 500) {
      moveRight();
    } else {
      moveForward();
    }

    // Light detection
    int lightValueLeft = analogRead(lightSensorLeft);
    int lightValueRight = analogRead(lightSensorRight);

    if (lightValueLeft > 600 || lightValueRight > 600) {
      stop();

      if (lightValueLeft > lightValueRight) {
        moveLeft();
      } else {
        moveRight();
      }
    }
  }
}

void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void moveBackward() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
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
