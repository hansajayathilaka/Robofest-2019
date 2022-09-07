//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void calShortPath() {
  int i = 0;
  int j = 0;
  bool back = true;
  while (back) {
    i = 0;
    j = 0;
    while (i < 98) {
      if ((path1[i] == 'R') && (path1[i + 1] == 'B') && (path1[i + 2] == 'R')) {               //RBR = S
        path2[j] = 'S';
        i = i + 2;
      }
      else if ((path1[i] == 'R') && (path1[i + 1] == 'B') && (path1[i + 2] == 'S')) {          //RBS = L
        path2[j] = 'L';
        i = i + 2;
      }
      else if ((path1[i] == 'R') && (path1[i + 1] == 'B') && (path1[i + 2] == 'L')) {          //RBL = B
        path2[j] = 'B';
        i = i + 2;
      }
      else if ((path1[i] == 'S') && (path1[i + 1] == 'B') && (path1[i + 2] == 'R')) {          //SBR = L
        path2[j] = 'L';
        i = i + 2;
      }
      else if ((path1[i] == 'S') && (path1[i + 1] == 'B') && (path1[i + 2] == 'S')) {          //SBS = B
        path2[j] = 'B';
        i = i + 2;
      }
      else if ((path1[i] == 'S') && (path1[i + 1] == 'B') && (path1[i + 2] == 'L')) {          //SBL = R
        path2[j] = 'R';
        i = i + 2;
      }
      else if ((path1[i] == 'L') && (path1[i + 1] == 'B') && (path1[i + 2] == 'R')) {          //LBR = B
        path2[j] = 'B';
        i = i + 2;
      }
      else if ((path1[i] == 'L') && (path1[i + 1] == 'B') && (path1[i + 2] == 'S')) {          //LBS = R
        path2[j] = 'R';
        i = i + 2;
      }
      else if ((path1[i] == 'L') && (path1[i + 1] == 'B') && (path1[i + 2] == 'L')) {          //LBL = S
        path2[j] = 'S';
        i = i + 2;
      }
      else {
        path2[j] = path1[i];
      }
      i++;
      j++;
      //      for (int x = 0; x < 20; x++) {
      //        Serial.print(path2[x]);
      //        Serial.print(" , ");
      //      }
      //      Serial.println(i);
    }
    for (int k = 0; k < 100; k++) {
      path1[k] = path2[k];
    }

    for (int k = 0; k < 100; k++) {
      if (path1[k] == 'B') {
        Serial.print("B    ");
        back = true;
        break;
      }
      else {
        back = false;
      }
    }

    for (int x = 0; x < 100; x++) {
      Serial.print(path2[x]);
      //      Serial.print(" , ");
    }
    Serial.println("***");
  }


  for (int k = 0; k < 100; k++) {
    shortPath[k] = path1[k];
  }

  //  for (int x = 0; x < 100; x++) {
  //    Serial.print(shortPath[x]);
  //    Serial.print(" , ");
  //  }
  //  Serial.println();
delay(1000);
  drive(-100, 100);
  delay(1000);
  drive(0, 0);
  shortRun = true;
  pathVariable = 0;
}

