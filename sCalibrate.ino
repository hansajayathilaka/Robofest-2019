//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void sCalibrate() {
  int calibrateVariable = 80;       // should be devided by 5
  int calibrateSpeed = 100;

  for (int i = 0; i < calibrateVariable; i++) {         // 50
    if (i < calibrateVariable / 5) {                    // 10
      drive(0, 0);
    }
    else if (i < 2 * calibrateVariable / 5) {           // 20
      drive(-calibrateSpeed, calibrateSpeed);
    }
    else if (i < 4 * calibrateVariable / 5) {           // 40
      drive(calibrateSpeed, -calibrateSpeed);
    }
    else {
      drive(-calibrateSpeed, calibrateSpeed);
    }
    qtrrc.calibrate();
  }
  drive(0, 0);


  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();

}
