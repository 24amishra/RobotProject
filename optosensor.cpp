#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHSD.h>

// Declarations for analog optosensors
AnalogInputPin right_opto(FEHIO::P2_0);
AnalogInputPin middle_opto(FEHIO::P2_1);
AnalogInputPin left_opto(FEHIO::P2_2);

int main(void)
{
    float x, y; //for touch screen

    // Open output file and prepare for writing values to it
    // <ADD CODE HERE>

   
    FEHFile *optptr;
    optptr = SD.FOpen("output.txt","w");

    //Initialize the screen
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);

    LCD.WriteLine("Analog Optosensor Testing");
    LCD.WriteLine("Touch the screen");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor on straight line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (1/12)");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>

    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor off straight line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (2/12)");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
SD.FPrintf(optptr,"Straight Line: ");
    SD.FPrintf(optptr,"%f",left_opto.Value());
    SD.FPrintf(optptr,"%f",right_opto.Value());
       SD.FPrintf(optptr,"%f",middle_opto.Value());




    // Repeat process for remaining optosensors, and repeat all three for the curved line values
    // <ADD CODE HERE>
SD.FPrintf(optptr,"Curved Line: ");
     SD.FPrintf(optptr,"%f",left_opto.Value());
    SD.FPrintf(optptr,"%f",right_opto.Value());
       SD.FPrintf(optptr,"%f",middle_opto.Value());






    // Close output file
    // <ADD CODE HERE> 
    SD.FClose(optptr);
    // Print end message to screen
    LCD.Clear(BLACK);
    LCD.WriteLine("Test Finished");

    return 0;
}