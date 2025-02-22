#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHSD.h>


#include <FEHServo.h>

#include <FEHMotor.h>

#include <FEHUtility.h>



AnalogInputPin right_opto(FEHIO::P2_2);
AnalogInputPin middle_opto(FEHIO::P2_1);
AnalogInputPin left_opto(FEHIO::P2_0);


AnalogInputPin CdS_cell(FEHIO::P1_0);

DigitalInputPin pin1(FEHIO::P0_7 );

DigitalInputPin pin2(FEHIO::P3_0 );

DigitalInputPin pin3(FEHIO::P0_0 );

DigitalInputPin pin4(FEHIO::P3_7);

FEHServo servo(FEHServo::Servo0);

FEHMotor rightDrive(FEHMotor::Motor0,9.0);

FEHMotor leftDrive(FEHMotor::Motor1,9.0);


enum LineStates{ MIDDLE, RIGHT, LEFT};
#define LEFTPOWER 25
#define RIGHTPOWER 25
#define RIGHTBOUND 1.5
#define MIDDLEBOUND 
#define LEFTBOUND 1

int main(){

int state = MIDDLE;

while(true){

    switch(state){

case MIDDLE:
while(middle_opto.Value() > 2.2){
    leftDrive.SetPercent(LEFTPOWER);
    rightDrive.SetPercent(RIGHTPOWER);
}
    
    if (right_opto.Value() < RIGHTBOUND){
        state = RIGHT;
    }else if (left_opto.Value() < LEFTBOUND){

        state = LEFT;

    }
    

    break;

case RIGHT:
while(!right_opto.Value() > 1.9){
leftDrive.Stop();
rightDrive.Stop();
Sleep(2);

    leftDrive.SetPercent(10);
    rightDrive.SetPercent(25);
}

if (middle_opto.Value() > 2.2){
    leftDrive.Stop();
    rightDrive.Stop();
       Sleep(2);
       state = MIDDLE;

 break;

 
}




   

   

case LEFT:
while(!left_opto.Value() > 1.9){
leftDrive.Stop();
rightDrive.Stop();
Sleep(2);
    leftDrive.SetPercent(10);
    rightDrive.SetPercent(25);
}

if (middle_opto.Value() > 2.2 ){
state = MIDDLE;
break;

    }













default: 
    break;

    }

    Sleep(1);
}



}
