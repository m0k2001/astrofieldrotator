// Initialization routine
#define DirectionPin 2
#define PulsePin 3
#define EnablePin 9
#define MS1Pin 8
#define MS2Pin 7
#define MS3Pin 6
#define ReversePin 12

void setup() {
  pinMode(PulsePin, OUTPUT);
  digitalWrite(PulsePin, LOW);
  pinMode(DirectionPin, OUTPUT);
  digitalWrite(DirectionPin, LOW);
  pinMode(EnablePin, OUTPUT);
  digitalWrite(EnablePin, LOW);
  pinMode(MS1Pin, OUTPUT);
  pinMode(MS2Pin, OUTPUT);
  pinMode(MS3Pin, OUTPUT);

  switch (microsteps) {
    case 16:
    {
      digitalWrite(MS1Pin, HIGH);
      digitalWrite(MS2Pin, HIGH);
      digitalWrite(MS3Pin, HIGH);
      break;
    }
    case 8:
    {
      digitalWrite(MS1Pin, HIGH);
      digitalWrite(MS2Pin, HIGH);
      digitalWrite(MS3Pin, LOW);
      break;
    }
    case 4:
    {
      digitalWrite(MS1Pin, LOW);
      digitalWrite(MS2Pin, HIGH);
      digitalWrite(MS3Pin, LOW);
      break;
    }
    case 2:
    {
      digitalWrite(MS1Pin, HIGH);
      digitalWrite(MS2Pin, LOW);
      digitalWrite(MS3Pin, LOW);
      break;
    }
    case 1:
    {
      digitalWrite(MS1Pin, LOW);
      digitalWrite(MS2Pin, LOW);
      digitalWrite(MS3Pin, LOW);
      break;
    }

    
  }

  pinMode(ReversePin, INPUT);

  // Initialize serial
  Serial.begin(9600);
  Serial.setTimeout(2000);

  // Initialize stepper motor
  stepper.setMaxSpeed(gear*2500);     // 5000 works good,  use 500000 for confrom test1000 geared rotator10000 for geared stepper   200 for non-geared large stepper(500 max)  also may depend on what else is on loop()
  stepper.setAcceleration(gear*500);  //1000 for geared rotator  10000 for geared stepper    1000 for non-geared large stepper
  stepper.setCurrentPosition(readFocuserPos());
  positionSaved = true;
  inputString = "";
  Serial.print("ASCOM.Arduino.Rotator ");
  Serial.println("ver 1.0.0.8");
  reverseDir(digitalRead(ReversePin));  // reverseDir(digitalRead(!ReversePin));      // if NO SWITCH soldered and if you need to reverse rotation
  Serial.print("Pos = ");
  Serial.println(stepper.currentPosition());
}
