//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void drive(int m1Speed, int m2Speed) {
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}

void setM2Speed(int speed) {
  unsigned char reverse = 0;

  if (speed < 0) {
    speed = -speed; // make speed a positive quantity
    reverse = 1;    // preserve the direction
  }

  if (speed > 0xFF) // 0xFF = 255
    speed = 0xFF;

  if (reverse) {
    digitalWrite(DIRB, HIGH);
    analogWrite(PWM0B, 0xFF - speed);
  }
  else { // forward
    digitalWrite(DIRB, LOW);
    analogWrite(PWM0B, speed);
  }
}

void setM1Speed(int speed) {
  unsigned char reverse = 0;

  if (speed < 0) {
    speed = -speed; // make speed a positive quantity
    reverse = 1;    // preserve the direction
  }

  if (speed > 0xFF) // 0xFF = 255
    speed = 0xFF;

  if (reverse) {
    digitalWrite(DIRA, HIGH);
    analogWrite(PWM0A, 0xFF - speed);
  }
  else { // forward
    digitalWrite(DIRA, LOW);
    analogWrite(PWM0A, speed);
  }
}

