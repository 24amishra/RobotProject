#include <FEHLCD.h>

#include <FEHServo.h>

#include <FEHMotor.h>

#include <FEHUtility.h>

#include <FEHIO.h>

 

AnalogInputPin CdS_cell(FEHIO::P1_0);

DigitalInputPin pin1(FEHIO::P0_7 );

DigitalInputPin pin2(FEHIO::P3_0 );

DigitalInputPin pin3(FEHIO::P0_0 );

DigitalInputPin pin4(FEHIO::P3_7);

FEHServo servo(FEHServo::Servo0);

FEHMotor rightDrive(FEHMotor::Motor0,9.0);

FEHMotor leftDrive(FEHMotor::Motor1,9.0);

int main(void)

{      



}

 



 