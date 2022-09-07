#define R A13
#define G A14
#define B A15

int red = 500;
int green = 540;
int blue = 600;

char readCol() {
  char col;

  int red1 = analogRead(R);
  int green1 = analogRead(G);
  int blue1 = analogRead(B);
  for (int i = 0; i < 100; i++) {
    red1 = (red1 + analogRead(R)) / 2;
    green1 = (green1 + analogRead(G)) / 2;
    blue1 = (blue1 + analogRead(B)) / 2;
  }

  if ((red - red1) > (blue - blue1))
    if ((red - red1) > (green - green1))
      return 'R';
    else
      return 'G';
  else if ((green - green1) > (blue - blue1))
    return 'G';
  else
    return 'B';
  //  Serial.print(red - red1);
  //  Serial.print("\t");
  //  Serial.print(green - green1);
  //  Serial.print("\t");
  //  Serial.print(blue - blue1);
  //  Serial.print("\t");
}
