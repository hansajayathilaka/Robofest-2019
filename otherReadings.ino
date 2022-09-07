//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void updateVal() {
  qtrrc.read(sensorValues);
}

bool s(byte val) {
  if (sensorValues[val] >= 2400)
    return 1;
  else
    return 0;
}

byte sumSensors() {
  updateVal();
  byte num = 0;
  for (byte x = 0; x < NUM_SENSORS; x++) {
    num = num + s(x);
  }
  return num;
}

long turnError() {
  unsigned int sensors[NUM_SENSORS];
  int position = qtrrc.readLine(sensors);
  int error = position - 3500;
  //  error = error / 500;
  return (error);
}


long distance () {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 2000);
  distance = (duration / 2.0) / 29.1;
  if (distance == 0)
    distance = 20.0;
  else
    distance = constrain(distance, 0, 20);
  return distance;
}

int servoDelay = 10;

void servo(char motor, int location) {
  if (motor == 'U') {
    if (servoU.read() > location) {
      while (servoU.read() != location) {
        servoU.write(servoU.read() - 1);
        delay(servoDelay);
      }
    } else {
      while (servoU.read() != location) {
        servoU.write(servoU.read() + 1);
        delay(servoDelay);
      }
    }
  }
  if (motor == 'H') {
    if (servoH.read() > location) {
      while (servoH.read() != location) {
        servoH.write(servoH.read() - 1);
        delay(servoDelay);
      }
    } else {
      while (servoH.read() != location) {
        servoH.write(servoH.read() + 1);
        delay(servoDelay);
      }
    }
  }
  if (motor == 'C') {
    if (servoC.read() > location) {
      while (servoC.read() != location) {
        servoC.write(servoC.read() - 1);
        delay(servoDelay);
      }
    } else {
      while (servoC.read() != location) {
        servoC.write(servoC.read() + 1);
        delay(servoDelay);
      }
    }
  }
}
