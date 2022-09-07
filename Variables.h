#define PWM0A   9    // Left Forword
#define PWM0B   11    // Right Forword
#define DIRA    8    // Left Backword
#define DIRB    10    // Right Backword

byte section = 0;

//Delays
long junkDelay;

//Servo
Servo servoU;
Servo servoC;
Servo servoH;

//Sonar
#define trigPin 51
#define echoPin 49

//Button
Button btnStart(33);
bool shortRun = false;
byte Round = 0;

char shortPath[100];
char path1[100]; // = {'R', 'L', 'R', 'L', 'R', 'B', 'S', 'R', 'S', 'R', 'R', 'L', 'R', 'R', 'R', 'B', 'R', 'R', 'B', 'S', 'R', 'B', 'R', 'L', 'L', 'R', 'R', 'R', 'R', 'B', 'S', 'B', 'R', 'R', 'S', 'R'};
char path2[100];
int pathVariable = 0;

