#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHSD.h>

// Declarations for analog optosensors
AnalogInputPin right_opto(FEHIO::P2_2);
AnalogInputPin middle_opto(FEHIO::P2_1);
AnalogInputPin left_opto(FEHIO::P2_0);

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

    Sleep(1); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (1/12)");


    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>

        SD.FPrintf(optptr,"Left Optosensor on Straight Line: ");
        SD.FPrintf(optptr,"%f",left_opto.Value());
        LCD.Write(left_opto.Value());






    // Left Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor off straight line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (2/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Left Optosensor off Straight Line: ");
    SD.FPrintf(optptr,"%f",left_opto.Value());
            LCD.Write(left_opto.Value());


    // Repeat process for remaining optosensors, and repeat all three for the curved line values
    // <ADD CODE HERE>

    // Right Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor off straight line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (3/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Right Optosensor off Straight Line: ");
    SD.FPrintf(optptr,"%f",right_opto.Value());
            LCD.Write(right_opto.Value());



      LCD.Clear(BLACK);
    LCD.WriteLine("Place Right optosensor on straight line");

    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (4/12)");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
        SD.FPrintf(optptr,"right Optosensor on Straight Line: ");
        SD.FPrintf(optptr,"%f",right_opto.Value());
            LCD.Write(right_opto.Value());







    // Middle Optosensor off straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor off straight line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (5/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Middle Optosensor off Straight Line: ");
    SD.FPrintf(optptr,"%f",middle_opto.Value());
            LCD.Write(middle_opto.Value());







    // Middle Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor on straight line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (6/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Middle Optosensor on Straight Line: ");
    SD.FPrintf(optptr,"%f",middle_opto.Value());
                LCD.Write(middle_opto.Value());




SD.FPrintf(optptr,"Curved Line: ");
LCD.WriteLine("Part 2: Curved Line. Press Screen to Begin");
     while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed

    // Record values for optosensors on and off of the straight line
    // Left Optosensor on straight line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor on curved line");

    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (7/12)");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
        SD.FPrintf(optptr,"Left Optosensor on curved Line: ");
        SD.FPrintf(optptr,"%f",left_opto.Value());
                    LCD.Write(left_opto.Value());







    // Left Optosensor off curved line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place left optosensor off curved line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (8/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Left Optosensor off curved Line: ");
    SD.FPrintf(optptr,"%f",left_opto.Value());
                LCD.Write(left_opto.Value());



    // Repeat process for remaining optosensors, and repeat all three for the curved line values
    // <ADD CODE HERE>

    // Right Optosensor off curved line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place right optosensor off curved line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (9/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
       

      SD.FPrintf(optptr,"Right Optosensor off curved Line: ");
    SD.FPrintf(optptr,"%f",right_opto.Value());
                LCD.Write(right_opto.Value());



      LCD.Clear(BLACK);
    LCD.WriteLine("Place Right optosensor on curved line");

    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (10/12)");
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
        SD.FPrintf(optptr,"right Optosensor on curved Line: ");
        SD.FPrintf(optptr,"%f",right_opto.Value());
                    LCD.Write(right_opto.Value());







    // Middle Optosensor off curved line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor off curved line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (11/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Middle Optosensor off curved Line: ");
    SD.FPrintf(optptr,"%f",middle_opto.Value());
                LCD.Write(middle_opto.Value());







    // Middle Optosensor on curved line
    LCD.Clear(BLACK);
    LCD.WriteLine("Place middle optosensor on curved line");
    Sleep(0.25); // Wait to avoid double input
    LCD.WriteLine("Touch screen to record value (12/12)");

   
    while(!LCD.Touch(&x,&y)); //Wait for screen to be pressed
    while(LCD.Touch(&x,&y)); //Wait for screen to be unpressed
    // Write the value returned by the optosensor to your output file
    // <ADD CODE HERE>
      SD.FPrintf(optptr,"Middle Optosensor on curved Line: ");
    SD.FPrintf(optptr,"%f",middle_opto.Value());
                LCD.Write(middle_opto.Value());






    // Close output file
    // <ADD CODE HERE> 
    SD.FClose(optptr);
    // Print end message to screen
    LCD.Clear(BLACK);
    LCD.WriteLine("Test Finished");

    return 0;
}