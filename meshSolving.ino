//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

int const goDelay   = 25;     //delay to goto the end of the line
int const lineDelay = 20;     //delay to cross a line

void meshSolving() {
  Kp = 0.04;
  Kd = 0.2;
  rightMaxSpeed  =  130;
  leftMaxSpeed   =  130;
  rightBaseSpeed =  80;
  leftBaseSpeed  =  80;


  while (section == 1) {
    PID();

    bool error = 0;
    bool left = 0;
    bool right = 0;
    bool straight = 0;
    bool back = 0;

    updateVal();
    if (sumSensors() == 0) {     // Back (Dead end detected)
      back = 1;
    }



    else if (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {                                          // T detection
      junkDelay = millis();
      updateVal();
      while (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {
        updateVal();
        drive(100, 100);
      }
      //      Serial.println(millis() - junkDelay);
      drive(0, 0);
      //      delay(3000);
      //      continue;
      if (millis() - junkDelay > lineDelay) {
        left = 1;
        right = 1;
        junkDelay = millis();
        straight = 1;
        while (millis() - junkDelay < goDelay) {
          drive(100, 100);
          updateVal();
          if ((s(3) == 0) && (s(4) == 0)) {
            straight = 0;
            break;
          }
        }

        drive(0, 0);

      }
    }




    else if ((s(0) == 1) && (s(1) == 1) && (s(2) == 1) && (s(3) == 1) && (s(4) == 1) && (s(5) == 1) && (s(7) == 0)) {      // Left detection  euwrobscxpl;bijnl;k ,fbvscxvhobjknlm;bgdfvsdcxcvguhbojnkml;gbdvfcsxubinjomkl,
      junkDelay = millis();
      updateVal();
      while ((s(0) == 1) && (s(1) == 1) && (s(2) == 1) && (s(3) == 1) && (s(4) == 1)  && (s(5) == 1) && (s(7) == 0)) {
        drive(60, 60);
        updateVal();
      }
      if (millis() - junkDelay > lineDelay) {
        junkDelay = millis();
        updateVal();
        if ((s(7) == 1)) {                                                               // Second Y detection
          updateVal();
          while ((s(7) == 1)) {
            drive(100, 100);
            updateVal();
          }
          drive(0, 0);
          if (millis() - junkDelay > goDelay) {
            right = 1;
            left = 1;
            turn(left, right, straight, back);
            continue;
          }
        }
        left = 1;
        junkDelay = millis();
        straight = 1;
        while (millis() - junkDelay < goDelay) {
          drive(100, 100);
          updateVal();
          if ((s(3) == 0) && (s(4) == 0)) {
            straight = 0;
            break;
          }
        }
        drive(0, 0);
      }
    }




    else if ((s(0) == 0) && (s(2) == 1) && (s(3) == 1) && (s(4) == 1) && (s(5) == 1) && (s(6) == 1) && (s(7) == 1)) {      // Right detection
      junkDelay = millis();
      updateVal();
      while ((s(0) == 0) && (s(2) == 1) && (s(3) == 1) && (s(4) == 1) && (s(5) == 1) && (s(6) == 1) && (s(7) == 1)) {
        drive(100, 100);
        updateVal();
      }
      if (millis() - junkDelay > lineDelay) {
        right = 1;
        junkDelay = millis();
        straight = 1;
        while (millis() - junkDelay < goDelay) {
          drive(100, 100);
          updateVal();
          if ((s(3) == 0) && (s(4) == 0)) {
            straight = 0;
            break;
          }
        }
      }
 
      drive(0, 0);

    }

    turn(left, right, straight, back);

    long x = distance();
    if (x < 15) {
      drive(0, 0);
      delay(2000);
      junkDelay = millis();
      drive(100, 100);
      section = 2;
      while (millis() - junkDelay < goDelay) {
        x = distance();
        if (x > 15) {
          section = 1;
          break;
        }
      }
    }
  }
}

