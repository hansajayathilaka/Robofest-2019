void picBox() {
  Kp = 0.07;
  Kd = 0.3;
  rightMaxSpeed  =  120;
  leftMaxSpeed   =  120;
  rightBaseSpeed =  80;
  leftBaseSpeed  =  80;
  lastError = 0;
  junkDelay = millis();
  PID();
  while (distance() > 8) {
    PID();
  }
  drive(0, 0);
  servo('U', 170);
  servo('H', 80);
  servo('C', 90);
  junkDelay = millis();
  while(millis() - junkDelay < 500){
    PID();
    }
  drive(0, 0);
  servo('C', 35);
  servo('U', 40);
  servo('C', 70);
  delay(50);
  servo('C', 40);
  delay(50);
  section = 3;
}

