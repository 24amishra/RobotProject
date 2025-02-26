#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

//Declarations for encoders & motors
DigitalEncoder right_encoder(FEHIO::P0_0);
DigitalEncoder left_encoder(FEHIO::P0_1);
FEHMotor right_motor(FEHMotor::Motor0,9.0);
FEHMotor left_motor(FEHMotor::Motor1,9.0);

void reset(){
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();
}

void move_forward(int percent, int counts) //using encoders
{
    //Reset encoder counts
    right_encoder.ResetCounts();
    left_encoder.ResetCounts();

    //Set both motors to desired percent
    right_motor.SetPercent(percent);
    left_motor.SetPercent(percent);

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((left_encoder.Counts() + right_encoder.Counts()) / 2. < counts);

    //Turn off motors
    right_motor.Stop();
    left_motor.Stop();
}

void turn_right(int percent, int counts)
    {
 //Reset encoder counts
 right_encoder.ResetCounts();
 left_encoder.ResetCounts();

 //Set both motors to desired percent
 right_motor.SetPercent(-percent);
 left_motor.SetPercent(percent);

 //While the average of the left and right encoder is less than counts,
 //keep running motors
 while((left_encoder.Counts() - right_encoder.Counts()) / 2. < counts);

 //Turn off motors
 right_motor.Stop();
 left_motor.Stop();
    }

void turn_left(int percent, int counts){
     //Reset encoder counts
     right_encoder.ResetCounts();
     left_encoder.ResetCounts();
 
     //Set both motors to desired percent
     right_motor.SetPercent(percent);
     left_motor.SetPercent(-percent);
 
     //While the average of the left and right encoder is less than counts,
     //keep running motors
     while((right_encoder.Counts() - left_encoder.Counts()) / 2. < counts);
 
     //Turn off motors
     right_motor.Stop();
     left_motor.Stop();
}


int main(void)
{
    int motor_percent = 0.4;
    int oneInchCount = 20.2445/2 ; //Input theoretical counts here
    int ninetyDegree_expected_counts = 119.0/2;

    float x, y; //for touch screen

    //Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);

    LCD.WriteLine("Shaft Encoder Exploration Test");
    LCD.WriteLine("Touch the screen");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed

    move_forward(motor_percent, 14 * oneInchCount); //see function
    Sleep(2.0); //Wait for counts to stabilize
    turn_left(motor_percent, ninetyDegree_expected_counts);
    Sleep(2.0); //Wait for counts to stabilize
    move_forward(motor_percent, 10 * oneInchCount);
    Sleep(2.0); //Wait for counts to stabilize
    turn_right(motor_percent, ninetyDegree_expected_counts);
    Sleep(2.0); //Wait for counts to stabilize
    move_forward(motor_percent, 4 * oneInchCount);

    Sleep(2.0); //Wait for counts to stabilize

    //Print out data
    //LCD.Write("Theoretical Counts: ")
    //LCD.WriteLine(oneInchCount);
    LCD.Write("Motor Percent: ");
    LCD.WriteLine(motor_percent);
    LCD.Write("Actual LE Counts: ");
    LCD.WriteLine(left_encoder.Counts());
    LCD.Write("Actual RE Counts: ");
    LCD.WriteLine(right_encoder.Counts());

    return 0;
}