float Kp = 0.05;
float Kd = 0.3;
int rightMaxSpeed  =  150;
int leftMaxSpeed   =  150;
int rightBaseSpeed =  100;
int leftBaseSpeed  =  100;
int lastError = 0;

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   12     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {
  A7, A6, A5, A4, A3, A2, A1, A0
},
NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

void PID() {
  unsigned int sensors[NUM_SENSORS];
  int position = qtrrc.readLine(sensors, QTR_EMITTERS_ON , 0);    //, QTR_EMITTERS_ON , 1
  int error = position - 3500;
//  Serial.println(error);

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed - motorSpeed;
  int leftMotorSpeed = leftBaseSpeed + motorSpeed;

  rightMotorSpeed = constrain(rightMotorSpeed, -rightMaxSpeed, rightMaxSpeed);
  leftMotorSpeed = constrain(leftMotorSpeed, -leftMaxSpeed, leftMaxSpeed);

//  updateVal();
//  if (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {                                           // T detection
//    junkDelay = millis();
//    drive(130, 130);
//    updateVal();
//    while (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {
//      updateVal();
//    }
//    if (millis() - junkDelay > 20) {
//      Serial.println(millis() - junkDelay);
//      drive(130, 130);
//      delay(100);
//      drive(0, 0);
//      if ((s(3) == 1) && (s(4) == 1)) {
//        Serial.println("Straight Line Detected");
//      }
//      delay(2000);
//    }
//  }
  drive(leftMotorSpeed, rightMotorSpeed);
}
