void placeBox() {
  while (true) {
    PID();
    updateVal();
    if (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {
      junkDelay = millis();
      drive(100, 100);
      updateVal();
      while (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {
        updateVal();
      }
      if (millis() - junkDelay > 90) {
        break;
      }
    }
  }

  char col = readCol();
  switch (col) {
    case 'R':
      turnRight();
      break;
    case 'G':
      turnLeft();
      break;
    case 'B':
      turnStraight();
      break;
  }
  drive(0, 0);


  while (true) {
    PID();
    if (sumSensors() > 5) {
      junkDelay = millis();
      drive(100, 100);
      while (sumSensors() > 5 && millis() - junkDelay < 30);
      drive(0, 0);
      break;
    }
  }
  drive(-80, -80);
  delay(400);
  drive(0, 0);
  servo('U', 170);
  servo('H', 30);
  servo('C', 140);
  delay(50);
  servo('U', 60);
  drive(-120, -120);
  delay(200);
  drive(0, 0);
  section = 4;
  if (Round == 1) {
    calShortPath();
  }
}
