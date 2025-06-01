#include <AccelStepper.h>
#include <EEPROM.h>
#define DirectionPin 2
#define PulsePin 3
#define EnablePin 9
#define gear 9
#define microsteps 16

#define DEVICE_RESPONSE "scopfocus Rotator ver 1008"
int ver = 1008;
// EEPROM addresses
#define FOCUSER_POS_START 0
#define STEPPER_SPEED_ADD 3

AccelStepper stepper(1, PulsePin, DirectionPin);  //(mode, stepPin, directionPin)

// Global vars
boolean hold = false;
boolean reversed;
boolean positionSaved;  // Flag indicates if stepper position was saved as new focuser position
boolean firstPrint = false;
String inputString;  // Serial input command string (terminated with \n)

// *************  this value must be changed for each specific setup ***************************************
long maxSteps = 46080*gear;  // **** steps needed for 2 complete revolutions.  prevent cord wrap.
//  Must also enter this value/720 = steps/degree for first time ASCOM driver setup, click "properties
// ******************************************************************************************************

//int manualMoveStepSize = 50;  //higher number for faster manual moves
//int findHomeStepSize = 100; //adjusts finding home speed

int HEState = 0;
long lastDebounceTime = 0;
//  int counter = 0;
long debounceDelay = 20;

void loop() {
  // Stepper loop
  digitalWrite(EnablePin, LOW);
  if (stepper.distanceToGo() == 0 && !positionSaved) {
    saveFocuserPos(stepper.currentPosition());
    positionSaved = true;
  }
  if (stepper.distanceToGo() != 0 && !firstPrint) {
    firstPrint = true;
    Serial.print("P ");
    Serial.print(stepper.targetPosition());  //currentPosition() no accurate until move is done  **** was println, changes w/ adding # below
    Serial.print(";");
    Serial.print("M ");
    Serial.print("true");  //true
    Serial.println("#");
  }

  stepper.run();
}
