//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

int const turnDelay = 500;     //delay to make a 90 degrees turn

void turn(int left, int right, int straight, int back) {
  if (shortRun == false) {
    if (back == 1) {
      turnBack();
    }
    else if (right == 1) {
      turnRight();
    }
    else if (straight == 1) {
      turnStraight();
    }
    else if (left == 1) {
      turnLeft();
    }
  }

  else {
    if ((shortPath[pathVariable] == 'R') && (right == 1))
      turnRight();
    else if ((shortPath[pathVariable] == 'S') && (straight == 1))
      turnStraight();
    else if ((shortPath[pathVariable] == 'L') && (left == 1))
      turnLeft();
  }
}

void turnRight() {
  drive(60, 60);
  delay(150);
  if (section == 1) {
    path1[pathVariable] = 'R';
    pathVariable ++;
  }
//  if (section == 3)
//  {
//    drive(0, 0);
//    delay(100);
//  }

  drive(60, -60);
//  if (section == 3)
//  {
//    delay(300);
//  }
//  else {
    delay(turnDelay);
 // }

  updateVal();
  while (s(0) == 0) {
    drive(60, -60);
    updateVal();
  }

  drive(0, 0);
}

void turnLeft() {
  drive(60, 60);
  delay(150);
  if (section == 1) {
    path1[pathVariable] = 'L';
    pathVariable ++;
  }
//  if (section == 3)
//  {
//    drive(0, 0);
//    delay(100);
//  }
  drive(-60, 60);
//  if (section == 3)
//  {
//    delay(300);
//  }
 // else
    delay(turnDelay);

  updateVal();
  while (s(7) == 0) {
    drive(-60, 60);
    updateVal();
  }
  drive(0, 0);
}

void turnStraight() {
  if (section == 1) {
    path1[pathVariable] = 'S';
    pathVariable ++;
  }

  drive(80, 80);
  delay(20);
  drive(0, 0);
}

void turnBack() {
  if (section == 1) {
    path1[pathVariable] = 'B';
    pathVariable ++;
  }

  drive(100, 100);
  delay(300);

  //  drive(-60, 60);
  //  delay(700);

  updateVal();
  while (s(5) == 0) {
    drive(100, -100);
    updateVal();
  }
  drive(0, 0);
}

