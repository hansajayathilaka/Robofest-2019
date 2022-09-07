//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

#include <QTRSensors.h>
#include <Servo.h>
#include <Button.h>
#include "Variables.h"

void setup() {
  Serial.begin(9600);
  Serial.println("BEGIN");

  //Button
  btnStart.begin();
  //  pinMode(btnShortPath, INPUT_PULLUP);

  // Motors
  pinMode(PWM0A, OUTPUT);
  pinMode(PWM0B, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  //Sonar
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // Servo
  servoU.attach(4);
  servoC.attach(5);
  servoH.attach(6);

  servoU.write(60);   //  60 - 170
  servoC.write(140);  // 140 -  40
  servoH.write(30);   //  30 -  80

  sCalibrate();

  section = 0;

  Round = 0;
}

void loop() {
  //  PID();
  //  if (sumSensors() > 5){
  //    drive(0, 0);
  //    delay(2000);
  //    drive(100, 100);
  //    delay(10);
  //    }
  //  Serial.println(distance());
  //  updateVal();
  //   for (unsigned char i = 0; i < 8; i++)
  //  {
  //    Serial.print(s(i));
  //    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  //  }
  //  Serial.println();
  //  delay(100);
  //  meshSolving();
  //  updateVal();
  //  Serial.print(distance());
  //  Serial.print("\t");
  //  updateVal();
  //  Serial.print(s(0));
  //  Serial.print("\t");
  //  Serial.print(s(1));
  //  Serial.print("\t");
  //  Serial.print(s(2));
  //  Serial.print("\t");
  //  Serial.print(s(3));
  //  Serial.print("\t");
  //  Serial.print(s(4));
  //  Serial.print("\t");
  //  Serial.print(s(5));
  //  Serial.print("\t");
  //  Serial.print(s(6));
  //  Serial.print("\t");
  //  Serial.println(s(7));

  //  Serial.println("***");
  //  calShortPath();
  //  Serial.println("*********");
  //  delay(5000);

//
  if (btnStart.toggled()) {
    if (btnStart.read() != Button::PRESSED) {
      Round += 1;
      section = 1;
      pathVariable = 0;
      shortRun = true;
    }
    if (Round == 1) {
      shortRun = false;
    }
  }

  switch (section) {
    case 1:
      meshSolving();
      break;
    case 2:
      picBox();
      break;
    case 3:
      placeBox();
      break;
    default:
      drive(0, 0);
  }
//drive(60,60);
//delay(500);
//drive(0,0);
//delay(2000);
//turnRight();
//drive(0,0);
//delay(2000);

}
