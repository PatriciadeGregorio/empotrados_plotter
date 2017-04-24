#include "MeOrion.h"
#include <SoftwareSerial.h>

MeStepper stepper(PORT_1); 
MeStepper stepper2(PORT_2);
MeJoystick joystick(PORT_6);
char a = '1';
int x = 0;
int y = 0;

void setup()
{  
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(20000);
  joystick.CalCenterValue(-1, -11.5);

  stepper2.setMaxSpeed(3000);
  stepper2.setAcceleration(20000);
}

void loop()
{
    x = joystick.read(1);
    y = joystick.read(2);
    if (((x < -10) || (x > 10)) || ((y<-10)|| (y>10))){
      stepper.move(x * -1);
    
      stepper2.move(y * -1);
      stepper.run();
      stepper2.run();
    }
    stepper.run();
    stepper2.run();
}
