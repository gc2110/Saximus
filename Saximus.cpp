//
//  Saximus.cpp
//
//
//  Created by Giancarlo Lezama on 1/9/15.
//
//

#include "Servo.h"
#include "Arduino.h"
#include "Saximus.h"

Saximus::Saximus(int OctaveKeyPin, int Upper1stKeyPin, int Upper2ndKeyPin, int Upper3rdKeyPin, int Lower1stKeyPin, int Lower2ndKeyPin, int Lower3rdKeyPin, int Altissimo_D_Keypin, int EbKeyPin, int A_SharpKeyPin, int G_SharpKeyPin, int Tongue_Motor, int Tempo)
{
    // initialize the relay pin as an output:
    pinMode(OctaveKeyPin, OUTPUT);
    pinMode(Upper1stKeyPin, OUTPUT);
    pinMode(Upper2ndKeyPin, OUTPUT);
    pinMode(Upper3rdKeyPin, OUTPUT);
    pinMode(Lower1stKeyPin, OUTPUT);
    pinMode(Lower2ndKeyPin, OUTPUT);
    pinMode(Lower3rdKeyPin, OUTPUT);
    pinMode(Altissimo_D_Keypin, OUTPUT);
    pinMode(EbKeyPin, OUTPUT);
    pinMode(A_SharpKeyPin, OUTPUT);
    pinMode(G_SharpKeyPin, OUTPUT);
    pinMode(Tongue_Motor, OUTPUT);
    
    // Set pin numbers for different things:
    _Tongue_Motor = Tongue_Motor; // Tongue Servo pin
    _OctaveKeyPin = OctaveKeyPin; // Octave Key
    _Upper1stKeyPin = Upper1stKeyPin;// Upper 1st Key
    _Upper2ndKeyPin = Upper2ndKeyPin;// Upper 2nd Key
    _Upper3rdKeyPin = Upper3rdKeyPin;// Upper 3rd Key
    _Lower1stKeyPin = Lower1stKeyPin;// Lower 1st Key
    _Lower2ndKeyPin = Lower2ndKeyPin;// Lower 2nd Key
    _Lower3rdKeyPin = Lower3rdKeyPin;// Lower 3rd Key
    _Altissimo_D_Keypin = Altissimo_D_Keypin;// High D Key
    _EbKeyPin = EbKeyPin;// Eb Key
    _A_SharpKeyPin = A_SharpKeyPin;// A_Sharp/Bb Key Above Eb Key
    _G_SharpKeyPin = G_SharpKeyPin;// G_Sharp Key
    
    //Set Different Note Delay Times
    _Tempo = Tempo;
    
    _Half_Note_Delay = (2)*(60,000/_Tempo);
    _Quarter_Delay = ((60,000)/(_Tempo));
    _Dotted_Quarter_Delay = (60,000/_Tempo)*(1.5);
    _8th_Delay = (60,000/(2*_Tempo))*(1.5);
    _Dotted_8th_Delay = (60,000/(2*_Tempo))*(1.5);
    _16th_Delay = (60,000)/(4*_Tempo);
    _32nd_Delay = (60,000)/(8*_Tempo);
     
}

//Turns all solenoids off so that the next note can then be played.
void Saximus::ResetAllSolenoids()
{
    digitalWrite(_OctaveKeyPin, LOW);
    digitalWrite(_Upper1stKeyPin, LOW);
    digitalWrite(_Upper2ndKeyPin, LOW);
    digitalWrite(_Upper3rdKeyPin, LOW);
    digitalWrite(_Lower1stKeyPin, LOW);
    digitalWrite(_Lower2ndKeyPin, LOW);
    digitalWrite(_Lower3rdKeyPin, LOW);
    digitalWrite(_Altissimo_D_Keypin, LOW);
    digitalWrite(_EbKeyPin, LOW);
    digitalWrite(_A_SharpKeyPin, LOW);
    digitalWrite(_G_SharpKeyPin, LOW);
}

//Function that plays Low D
void Saximus::LowDRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids(); 
    
}

//Function that plays Low D
void Saximus::LowDNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);

    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low Eb
void Saximus::LowEbRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_EbKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low Eb
void Saximus::LowEbNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_EbKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low E
void Saximus::LowERegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low E
void Saximus::LowENoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low F
void Saximus::LowFRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low F
void Saximus::LowFNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low F_Sharp
void Saximus::LowF_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low F_Sharp
void Saximus::LowF_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low G; puts a high signal for the upper three solenoids
void Saximus::LowGRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low G
void Saximus::LowGNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low G_Sharp
void Saximus::LowG_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_G_SharpKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low G_Sharp
void Saximus::LowG_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_G_SharpKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low A
void Saximus::LowARegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low A
void Saximus::LowANoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low A_Sharp
void Saximus::LowA_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_A_SharpKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low A_Sharp
void Saximus::LowA_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_A_SharpKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low B
void Saximus::LowBRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low B
void Saximus::LowBNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper1stKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low C
void Saximus::LowCRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays Low C
void Saximus::LowCNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fire
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Low C Sharp
void Saximus::LowC_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //No Solenoid(s) Fire FOR THIS NOTE
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays C Sharp
void Saximus::LowC_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //No Solenoid(s) Fire FOR THIS NOTE
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High D
void Saximus::HighDRegularTongue(int NoteLength)
{
    
    /*
     // Set up the Lips
     Servo Lip_Servo;  // create servo object to control a servo
     Lip_Servo.attach(_Lip_Motor); // attaches the servo on pin 9 to the servo object
     int interval = 15;
     int posLip = 0;    // variable to store the servo position
     int Desired_Lip_Angle = 50;
     int increment = 5;
     */
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    
    /*
     for(posLip = 0; posLip <= Desired_Lip_Angle; posLip += increment) // goes from 0 degrees to 180 degrees
     {                                  // in steps of 1 degree
     Lip_Servo.write(posLip);              // tell servo to go to position in variable 'posLip'
     delay(interval);                       // waits 15ms for the servo to reach the position
     }
     */
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    /*
     for(posLip = Desired_Angle; posLip>=0; posLip-= increment) // goes from 180 degrees to 0 degrees
     {                                  // in steps of 1 degree
     Lip_Servo.write(posLip);              // tell servo to go to position in variable 'posLip'
     delay(interval);                       // waits 15ms for the servo to reach the position
     }
     */
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays D
void Saximus::HighDNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High E
void Saximus::HighERegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays E
void Saximus::HighENoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High Eb
void Saximus::HighEbRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    digitalWrite(_EbKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}
    
//Function that plays Eb
void Saximus::HighEbNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    digitalWrite(_Lower3rdKeyPin, HIGH);
    digitalWrite(_EbKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High F
void Saximus::HighFRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays F
void Saximus::HighFNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower1stKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High F_Sharp
void Saximus::HighF_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High F_Sharp
void Saximus::HighF_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_Lower2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High G
void Saximus::HighGRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High G
void Saximus::HighGNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High G_Sharp
void Saximus::HighG_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_G_SharpKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High G_Sharp
void Saximus::HighG_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_Upper3rdKeyPin, HIGH);
    digitalWrite(_G_SharpKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High A
void Saximus::HighARegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High A
void Saximus::HighANoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High A_Sharp
void Saximus::HighA_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_A_SharpKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High A_Sharp
void Saximus::HighA_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    digitalWrite(_A_SharpKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High B
void Saximus::HighBRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High B
void Saximus::HighBNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper1stKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High C
void Saximus::HighCRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High C
void Saximus::HighCNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Upper2ndKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays High C Sharp
void Saximus::HighC_SharpRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    
    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays High C Sharp
void Saximus::HighC_SharpNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}

//Function that plays Altissimo D
void Saximus::AltissimoDRegularTongue(int NoteLength)
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 4;
    int Tongue_Start = 10;
    
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Altissimo_D_Keypin, HIGH);

    //Tongue Starts
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength-2*interval*(Desired_Angle/increment));
    
    //Solenoids Reset
    ResetAllSolenoids();
}

//Function that plays Altissimo D
void Saximus::AltissimoDNoTongue(int NoteLength)
{
    //Set up Note Function
    
    //Solenoid(s) Fired
    digitalWrite(_OctaveKeyPin, HIGH);
    digitalWrite(_Altissimo_D_Keypin, HIGH);
    
    //Delay by time left to keep solenoids on after tongue was in use
    delay(NoteLength);
    
    //Solenoids Reset
    ResetAllSolenoids();
    
}


// Rest Functions: Each requires a delay of all the solenoids being turned off. Each also requires that the tongue be kept up so there is no air flow through the saxophone. Once the delay is over, the tongue must go back down to its initial position. 

//Function for a Whole Note Rest
void Saximus::Whole_Note_Rest()
{

    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_Whole_Note_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
}

//Function for a Half Note Rest
void Saximus::Half_Note_Rest()
{

    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_Half_Note_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
}

//Function for a Quarter Rest
void Saximus::Quarter_Rest()
{

    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_Quarter_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
}

//Function for a Dotted Quarter Rest
void Saximus::Dotted_Quarter_Rest()
{

    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_Dotted_Quarter_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
}

//Function for an Eighth Rest
void Saximus::Eighth_Rest()
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_8th_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }

}

//Function for a Dotted Eighth Rest
void Saximus::Dotted_Eighth_Rest()
{
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_Dotted_8th_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }

}

//Function for a Sixteenth Rest
void Saximus::Sixteenth_Rest()
{
    ResetAllSolenoids();
    
    // Set up the Tongue
    Servo Tongue_Servo;  // create servo object to control a servo
    Tongue_Servo.attach(_Tongue_Motor); // attaches the servo on pin 9 to the servo object
    int interval = 15;
    int pos = 0;    // variable to store the servo position
    int Desired_Angle = 50;
    int increment = 5;
    int Tongue_Start = 10;
    
    //Tongue goes to reed, keeps it up to stop air flow, and then releases once the rest is over in order to play the next note
    for(pos = 0; pos <= Desired_Angle; pos += increment) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }
    
    delay(_16th_Delay); // Keep tongue pressed on reed for rest time
    
    for(pos = Desired_Angle; pos>=0; pos-= increment)     // goes from 180 degrees to 0 degrees
    {
        Tongue_Servo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(interval);                       // waits 15ms for the servo to reach the position
    }

}

// END OF REST FUNCTIONS

//START OF TEST FUNCTIONS

//Test Low G to tune the Saximus
void Saximus::TunerNote()
{
    LowGRegularTongue(2000);
}

//Tests the Eb Concert Scale on the alto saxophone
void Saximus::Blues_Scale()
{
    HighGNoTongue(4000);
    LowANoTongue(2000);
    LowCNoTongue(500);
    HighDNoTongue(500);
    HighFNoTongue(500);
    HighGNoTongue(500);
    HighG_SharpNoTongue(500);
    HighANoTongue(500);
    HighCNoTongue(500);
    AltissimoDNoTongue(500);
    HighGNoTongue(4000);
}

// Plays Mary Had a Little Lamb
// Link to the Song:
// www.youtube.com/watch?v=_8vu1brDtEA
void Saximus::MHALL()
{
    int Tongue_Start = 10; //Initialize Tongue Mechanism code
    
    _Tempo = 140; //Set the Tempo to 74 BPM
    
    //Start of Mary Had a Little Lamb
    
    /*
    LowBRegularTongue(600); //Measure 1
    LowARegularTongue(600);
    LowGRegularTongue(600);
    LowARegularTongue(600);
    LowBRegularTongue(600); //Measure 2
    LowBRegularTongue(600);
    LowBRegularTongue(1200);
    LowARegularTongue(600); //Measure 3
    LowARegularTongue(600);
    LowARegularTongue(1200);
    LowBRegularTongue(600); //Measure 4, Either two B's after or two D's
    LowBRegularTongue(600);
    LowBRegularTongue(1200);
    //LowDRegularTongue(600);
    //LowDRegularTongue(1200);
    LowBRegularTongue(600); //Measure 5
    LowARegularTongue(600);
    LowGRegularTongue(600);
    LowARegularTongue(600);
    LowBRegularTongue(600); //Measure 6
    LowBRegularTongue(600);
    LowBRegularTongue(1200);
    LowARegularTongue(600); //Measure 7
    LowARegularTongue(600);
    LowBRegularTongue(600);
    LowARegularTongue(600);
    LowGRegularTongue(2400); //Measure 8
    */
    
    HighARegularTongue(600); //Measure 1
    HighA_SharpRegularTongue(1000);
    HighCRegularTongue(700);
    HighA_SharpRegularTongue(600);
    HighARegularTongue(600); //Measure 1
    HighCRegularTongue(700); //Measure 1
    HighBRegularTongue(600); //Measure 1
    HighARegularTongue(600); //Measure 1
}

// Plays Hey Jude
// Here's the link to the sheet music:
// cloud.freehandmusic.netdna-cdn.com/preview/530x4/sonysnylmhyjudls.png
void Saximus::Hey_Jude()
{
    int Tongue_Start = 10; //Initialize Tongue Mechanism code
    
    _Tempo = 74; //Set the Tempo to 74 BPM
    
    //Start of Hey Jude
    LowCRegularTongue(_Quarter_Delay); //Measure 1
    LowARegularTongue(_Quarter_Delay);  //Measure 2
    Quarter_Rest(); 
    Eighth_Rest();
    LowARegularTongue(_8th_Delay);
    LowCRegularTongue(_8th_Delay);
    HighDRegularTongue(_8th_Delay);
    LowGRegularTongue(_Half_Note_Delay);  //Measure 3
    Quarter_Rest();
    LowGRegularTongue(_8th_Delay);
    LowARegularTongue(_8th_Delay);
    LowA_SharpRegularTongue(_Quarter_Delay);
    HighFRegularTongue(_Quarter_Delay+_16th_Delay);
    HighFRegularTongue(_16th_Delay);
    HighERegularTongue(_16th_Delay);
    LowCRegularTongue(_16th_Delay);
    HighDRegularTongue(_16th_Delay); //Measure 4
    LowCRegularTongue(_32nd_Delay);
    LowA_SharpRegularTongue(_32nd_Delay);
    LowARegularTongue(_Half_Note_Delay);
    Eighth_Rest();
    LowCRegularTongue(_8th_Delay);
    HighDRegularTongue(_8th_Delay); //Measure 5
    HighDRegularTongue(_8th_Delay);
    Eighth_Rest();
    HighDRegularTongue(_8th_Delay);
    HighGRegularTongue(_16th_Delay);
    HighFRegularTongue(_8th_Delay);
    HighERegularTongue(_16th_Delay+_32nd_Delay);
    HighFRegularTongue(_32nd_Delay);
    HighDRegularTongue(_8th_Delay);
    LowCRegularTongue(_Half_Note_Delay); //Measure 6
    LowFRegularTongue(_16th_Delay);
    LowGRegularTongue(_16th_Delay);
    LowARegularTongue(_16th_Delay);
    HighDRegularTongue(_16th_Delay+_8th_Delay);
    LowCRegularTongue(_8th_Delay);
    Eighth_Rest();
    
    //End of Hey Jude
    
    ResetAllSolenoids();  
}

// The Pink Panther
// Here's the link to the sheet music:
// www.musicnotes.com/images/productimages/mtd/MN0026912.gif
void Saximus::Pink_Panther()
{
    int Tongue_Start = 10; //Initialize Tongue Mechanism code
    
    _Tempo = 90; //Set the Tempo to 90 BPM
    
    //Start off with G
    HighGNoTongue(4500);
    
    //Start of Pink Panther
	HighEbRegularTongue(333);
	HighENoTongue(333);
	HighFRegularTongue(333);
	HighF_SharpNoTongue(4000);
	HighEbRegularTongue(333);
	HighENoTongue(333);
	HighFRegularTongue(333);
	HighF_SharpNoTongue(4000);
	
	HighFRegularTongue(333);
	HighENoTongue(333);
	HighEbNoTongue(333);
	HighDNoTongue(4000);
    
	HighEbRegularTongue(333);
	HighENoTongue(333);
	HighFRegularTongue(333);
	HighF_SharpNoTongue(4000);
    
    HighEbRegularTongue(333);
    HighENoTongue(667);
    HighF_SharpRegularTongue(333);
    HighGNoTongue(667);
    HighEbRegularTongue(333);
    HighENoTongue(333);
    HighF_SharpRegularTongue(333);
    HighGNoTongue(333);
    HighCRegularTongue(333);
    HighBNoTongue(333);
    HighERegularTongue(333);
    HighGNoTongue(333);
    HighBRegularTongue(333);
    HighA_SharpNoTongue(1333);
    HighA_SharpRegularTongue(333);
    HighANoTongue(333);
    HighGNoTongue(333);
    HighENoTongue(333);
    HighDNoTongue(333);
    HighENoTongue(2000);
    
	HighEbRegularTongue(333);
    HighENoTongue(667);
    HighF_SharpRegularTongue(333);
    HighGNoTongue(667);
    HighEbRegularTongue(333);
    HighENoTongue(333);
    HighF_SharpRegularTongue(333);
    HighGNoTongue(333);
    HighCRegularTongue(333);
    HighBNoTongue(333);
    HighERegularTongue(333);
    HighGNoTongue(333);
	HighERegularTongue(333);
	HighEbNoTongue(4666);
    
	HighEbRegularTongue(333);
    HighENoTongue(667);
    HighF_SharpRegularTongue(333);
    HighGNoTongue(667);
    HighEbRegularTongue(333);
    HighENoTongue(333);
    HighF_SharpRegularTongue(333);
    HighGNoTongue(333);
    HighCRegularTongue(333);
    HighBNoTongue(333);
    HighERegularTongue(333);
    HighGNoTongue(333);
    HighBRegularTongue(333);
    HighA_SharpNoTongue(1333);
    HighA_SharpRegularTongue(333);
    HighANoTongue(333);
    HighGNoTongue(333);
    HighENoTongue(333);
    HighDNoTongue(333);
    HighENoTongue(2000);
    
    //End of Pink Panther
    
    ResetAllSolenoids();
}

// Baker Street
//Link To Background Music:
//www.youtube.com/watch?v=zZ13gNicUNw
void Saximus::Baker_Street()
{
    _Tempo = 115; //Set the Tempo to 115 BPM
    
    //Start off with G
    HighGNoTongue(4500);
    
    //Start of Baker Street
    HighDRegularTongue(333); //Measure 1
    /* HighENoTongue(300);
    HighFNoTongue(300);
    HighGNoTongue(300);
    HighANoTongue(300);
    HighBNoTongue(300); */
    AltissimoDNoTongue(333);
    HighC_SharpRegularTongue(650);
    //HighBRegularTongue(300);
    //HighARegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    //HighBRegularTongue(300); //Measure 2
    HighBNoTongue(300);
    HighC_SharpNoTongue(300);
    HighBNoTongue(1830);
    
    HighDRegularTongue(333); //Measure 3
    /* HighENoTongue(300);
    HighFNoTongue(300);
    HighGNoTongue(300);
    HighANoTongue(300);
    HighBNoTongue(300); */
    AltissimoDNoTongue(333);
    HighC_SharpRegularTongue(650);
    //HighBRegularTongue(300);
    //HighANoTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    //HighF_SharpRegularTongue(650); //Measure 4
    HighF_SharpNoTongue(650);
    HighENoTongue(300);
    HighF_SharpNoTongue(1566);
    
    HighF_SharpRegularTongue(300); //Measure 5
    AltissimoDNoTongue(333);
    //HighC_SharpRegularTongue(650);
    HighC_SharpNoTongue(650);
    //HighBRegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(650);
    
    HighARegularTongue(783);//Measure 6
    HighARegularTongue(300);
    HighARegularTongue(783);
    HighARegularTongue(300);
    
    //HighF_SharpRegularTongue(783); //Measure 7
    HighF_SharpNoTongue(783);
    HighF_SharpRegularTongue(300);
    AltissimoDNoTongue(333);
    //HighC_SharpRegularTongue(650);
    HighC_SharpNoTongue(650);
    //HighBRegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    HighBRegularTongue(300); //Measure 8
    HighC_SharpNoTongue(300);
    HighBNoTongue(1830);
    
    HighDRegularTongue(333); //Measure 9
    AltissimoDNoTongue(333);
    //HighC_SharpRegularTongue(650);
    HighC_SharpNoTongue(650);
    //HighBRegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    HighBRegularTongue(2086); //Measure 10
    
    HighDRegularTongue(333); //Measure 11
    AltissimoDNoTongue(333);
    //HighC_SharpRegularTongue(650);
    HighC_SharpNoTongue(650);
    //HighBRegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    HighF_SharpRegularTongue(650); //Measure 12
    HighENoTongue(300);
    HighF_SharpNoTongue(1566);
    
    HighF_SharpRegularTongue(300); //Measure 13
    AltissimoDNoTongue(333);
    //HighC_SharpRegularTongue(650);
    HighC_SharpNoTongue(650);
    //HighBRegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    HighARegularTongue(783);//Measure 14
    HighARegularTongue(300);
    HighARegularTongue(783);
    HighARegularTongue(300);
    
    //HighF_SharpRegularTongue(783); //Measure 15
    HighF_SharpNoTongue(783);
    HighF_SharpRegularTongue(300);
    AltissimoDNoTongue(333);
    //HighC_SharpRegularTongue(650);
    HighC_SharpNoTongue(650);
    //HighBRegularTongue(300);
    HighBNoTongue(300);
    HighANoTongue(300);
    
    HighBRegularTongue(300); //Measure 16
    HighC_SharpNoTongue(300);
    HighBNoTongue(1830);
    
    HighERegularTongue(300);
    HighFNoTongue(300);
    HighENoTongue(300);
    //HighDRegularTongue(650);
    //HighEbRegularTongue(300);
    //HighENoTongue(300);
    //HighEbRegularTongue(300);
    HighDNoTongue(650);
    HighEbNoTongue(300);
    HighENoTongue(300);
    HighEbNoTongue(300);
    HighENoTongue(300);
    HighDRegularTongue(30000);
    
    //End of Baker Street
    
    ResetAllSolenoids();
}

// Careless Whisper
void Saximus::Careless_Whisper()
{
    //_Tempo = 77; //Set the Tempo to 77 BPM
    _Tempo = 80; //Set the Tempo to 115 BPM
    
    //Start off with G
    HighGNoTongue(4500);
    
    //Start of Careless Whisper
    HighC_SharpRegularTongue(400); //Measure 1
    HighDRegularTongue(300);
    HighENoTongue(300);
    HighFNoTongue(300);
    HighGNoTongue(300);
    HighANoTongue(300);
    HighBNoTongue(300);
    
    HighC_SharpNoTongue(800); //Measure 2
    HighBNoTongue(400);
    HighF_SharpNoTongue(800);
    HighDNoTongue(400);
    HighBNoTongue(300);
    HighC_SharpNoTongue(800);
    HighBNoTongue(400);
    HighF_SharpNoTongue(800);
    HighDNoTongue(400);
    
    HighGRegularTongue(300); //Measure 3
    HighANoTongue(800);
    HighGNoTongue(400);
    HighDNoTongue(800);
    LowBNoTongue(400);
    HighANoTongue(800);
    HighGNoTongue(400);
    HighDNoTongue(975);
    
    HighGRegularTongue(800); //Measure 4
    HighF_SharpNoTongue(400);
    HighDNoTongue(800);
    HighANoTongue(300);
    HighBNoTongue(400);
    HighGNoTongue(1560);
    
    HighANoTongue(400); //Measure 5
    HighG_SharpNoTongue(300);
    HighGNoTongue(300);
    HighF_SharpNoTongue(400);
    HighGNoTongue(400);
    HighANoTongue(400);
    HighBNoTongue(400);
    LowC_SharpNoTongue(400);
    HighDNoTongue(400);
    HighENoTongue(400);
    HighF_SharpNoTongue(400);
    
    HighBRegularTongue(300); //Measure 6
    HighC_SharpNoTongue(800);
    HighBNoTongue(400);
    HighF_SharpNoTongue(800);
    HighDNoTongue(400);
    HighBNoTongue(300);
    HighC_SharpNoTongue(800);
    HighBNoTongue(400);
    HighF_SharpNoTongue(800);
    HighDNoTongue(400);
    
    HighGRegularTongue(300); //Measure 7
    HighANoTongue(800);
    HighGNoTongue(400);
    HighDNoTongue(800);
    LowBNoTongue(400);
    HighANoTongue(800);
    HighGNoTongue(400);
    HighDNoTongue(975);
    
    HighGNoTongue(800); //Measure 8
    HighF_SharpNoTongue(400);
    HighDNoTongue(800);
    HighANoTongue(300);
    HighBNoTongue(400);
    HighGNoTongue(1560);
    
    HighANoTongue(400); //Measure 9
    HighGNoTongue(300);
    HighF_SharpNoTongue(400);
    HighGNoTongue(400);
    HighANoTongue(400);
    HighBNoTongue(400);
    LowC_SharpNoTongue(400);
    HighDNoTongue(400);
    HighENoTongue(400);
    HighF_SharpNoTongue(400);
    
    HighERegularTongue(300); //Measure 10
    HighF_SharpNoTongue(8000);
    
    //End of Careless Whisper
}

// Spiderman Theme
void Saximus::Spiderman_Theme()
{
    _Tempo = 100; //Set the Tempo to 100 BPM
    
    //Tune Up
    HighGNoTongue(3000);
    
    //Start Spiderman Theme
    
    HighANoTongue(600); //Measure 1
    LowCNoTongue(300);
    HighENoTongue(900);
    
    HighEbNoTongue(600); //Measure 2
    LowCNoTongue(300);
    HighANoTongue(900);
    
    HighANoTongue(600); //Measure 3
    LowCNoTongue(300);
    HighENoTongue(600);
    HighFNoTongue(300);
    HighENoTongue(600);
    
    HighEbNoTongue(600); //Measure 4
    LowCNoTongue(300);
    HighANoTongue(900);
    
    HighDNoTongue(600); //Measure 5
    HighFNoTongue(300);
    HighANoTongue(900);
    
    HighG_SharpNoTongue(600); //Measure 6
    HighFNoTongue(300);
    HighDNoTongue(900);
    
    HighANoTongue(600); //Measure 7
    LowCNoTongue(300);
    HighENoTongue(900);
    
    HighEbNoTongue(600); //Measure 8
    LowCNoTongue(300);
    HighANoTongue(900);
    HighFNoTongue(300);
    HighENoTongue(1500); //Measure 9
    
    HighEbNoTongue(300); //Measure 10
    HighDNoTongue(300);
    LowCNoTongue(300);
    HighDNoTongue(600);
    LowCNoTongue(300);
    HighANoTongue(5000); //Measure 11
}

//Tequila
//Link to Song:
//www.youtube.com/watch?v=N4yT7EhG0oI
void Saximus::Tequila()
{
    //_Tempo = 77; //Set the Tempo to 77 BPM
    _Tempo = 100; //Set the Tempo to 115 BPM
    
    //Tune Up
    HighGNoTongue(3000);
    
    //Start Spiderman Theme
    HighDNoTongue(300);
    HighGNoTongue(600);
    HighGRegularTongue(300);
    HighFNoTongue(300);
    HighANoTongue(600);
    HighFNoTongue(300);
    HighGNoTongue(600);
    HighDNoTongue(300);
    
    HighDNoTongue(300);
    HighGNoTongue(600);
    HighGRegularTongue(300);
    HighFNoTongue(300);
    HighANoTongue(600);
    HighFNoTongue(300);
    HighGNoTongue(300);

    HighDNoTongue(300);
    HighGNoTongue(600);
    HighGRegularTongue(300);
    HighFNoTongue(300);
    HighANoTongue(600);
    HighFNoTongue(300);
    HighGNoTongue(600);
    HighDNoTongue(300);
    
    HighEbNoTongue(300);
    HighENoTongue(600);
    HighEbNoTongue(300);
    HighENoTongue(600);
    HighDNoTongue(1000);
    
    HighGNoTongue(300);
    HighGRegularTongue(600);
    HighFNoTongue(300);
    HighANoTongue(300);
    HighFNoTongue(300);
    HighFRegularTongue(300);
    HighGNoTongue(300);
    
    HighDNoTongue(300);
    HighFNoTongue(300);
    HighGNoTongue(300);
    HighA_SharpNoTongue(1500);
    HighGNoTongue(300);
    
    HighDNoTongue(300);
    HighFNoTongue(300);
    HighGNoTongue(300);
    HighA_SharpNoTongue(1500);
    HighGNoTongue(300);
    
    HighDNoTongue(300);
    HighFNoTongue(300);
    HighGNoTongue(300);
    HighA_SharpNoTongue(1500);
    HighGNoTongue(300);
    
    HighANoTongue(300);
    HighCNoTongue(300);
    HighANoTongue(300);
    HighG_SharpNoTongue(300);
    HighGNoTongue(300);
    HighDNoTongue(300);
    HighEbNoTongue(300);
    HighENoTongue(3000);
}

//Legend of Zelda-Woods Theme
void Saximus::Zelda_Woods()
{
    //_Tempo = 77; //Set the Tempo to 77 BPM
    _Tempo = 100; //Set the Tempo to 115 BPM
    
    //Tune Up
    HighGNoTongue(3000);
    
    //Start of the Woods Theme
    
    HighDNoTongue(300); //Measure 1
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    HighDNoTongue(300);
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    
    HighDNoTongue(300); //Measure 2
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(300);
    HighC_SharpNoTongue(300);
    HighBNoTongue(600);
    HighG_SharpNoTongue(300);
    HighANoTongue(300);
    
    HighG_SharpNoTongue(300); //Measure 3
    HighANoTongue(300);
    HighG_SharpNoTongue(300);
    HighENoTongue(300);
    LowC_SharpNoTongue(1500);
    
    LowBNoTongue(300); //Measure 4
    LowC_SharpNoTongue(300);
    HighENoTongue(300);
    LowC_SharpNoTongue(1800);
    
    HighDNoTongue(300); //Measure 5
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    HighDNoTongue(300);
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    
    HighDNoTongue(300); //Measure 6
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(300);
    HighC_SharpNoTongue(300);
    HighBNoTongue(600);
    HighG_SharpNoTongue(300);
    HighANoTongue(300);
    
    HighG_SharpNoTongue(300); //Measure 7
    HighANoTongue(300);
    HighG_SharpNoTongue(300);
    HighENoTongue(300);
    LowC_SharpNoTongue(1500);
    
    LowBNoTongue(300); //Measure 8
    LowC_SharpNoTongue(300);
    HighENoTongue(300);
    LowC_SharpNoTongue(1800);
    
    LowBNoTongue(300); //Measure 9
    LowC_SharpNoTongue(300);
    HighDNoTongue(600);
    HighENoTongue(300);
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    
    HighANoTongue(300); //Measure 10
    HighG_SharpNoTongue(300);
    LowC_SharpNoTongue(1500);
    
    LowBNoTongue(300); //Measure 11
    LowC_SharpNoTongue(300);
    HighDNoTongue(600);
    HighENoTongue(300);
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    
    HighANoTongue(300); //Measure 12
    HighBNoTongue(300);
    HighC_SharpNoTongue(1500);
    
    LowBNoTongue(300); //Measure 13
    LowC_SharpNoTongue(300);
    HighDNoTongue(600);
    HighENoTongue(300);
    HighF_SharpNoTongue(300);
    HighG_SharpNoTongue(600);
    
    HighANoTongue(300); //Measure 14
    HighG_SharpNoTongue(300);
    LowC_SharpNoTongue(1500);
    
    // End of the Woods Theme
}

//Heart and Soul
void Saximus::HeartandSoul()
{
    _Tempo = 90; //Set the Tempo to 90 BPM
    
    //Tune Up
    HighGNoTongue(3000);
    
    //Start of Heart and Soul
    
    LowCNoTongue(333); //Measure 1
    LowCRegularTongue(333);
    LowCRegularTongue(1333);
    
    LowCNoTongue(333); //Measure 2
    LowCRegularTongue(333);
    LowBNoTongue(333);
    LowANoTongue(333);
    LowBNoTongue(333);
    LowCNoTongue(333);
    HighDNoTongue(667);
    
    HighENoTongue(667); //Measure 3
    HighERegularTongue(667);
    HighERegularTongue(1333);
    
    HighENoTongue(333); //Measure 4
    HighERegularTongue(333);
    HighDNoTongue(333);
    LowCNoTongue(333);
    HighDNoTongue(333);
    HighENoTongue(333);
    HighFNoTongue(667);
    
    HighGNoTongue(1333); //Measure 5
    LowCNoTongue(1333);
    LowCNoTongue(333);
    HighANoTongue(333);
    HighGNoTongue(333);
    HighFNoTongue(333);
    HighENoTongue(667);
    HighDNoTongue(667);
    
    LowCNoTongue(1333); //Measure 6
    LowCNoTongue(333); //Eighth Rest
    HighDNoTongue(333);
    HighENoTongue(333);
    HighFNoTongue(333);
    
    HighGNoTongue(667); //Measure 7
    HighFNoTongue(333);
    HighENoTongue(333);
    HighDNoTongue(1333);
    
    LowCNoTongue(333); //Measure 8
    LowCRegularTongue(333);
    LowCRegularTongue(1333);
    
    LowCNoTongue(333); //Measure 9
    LowCRegularTongue(333);
    LowBNoTongue(333);
    LowANoTongue(333);
    LowBNoTongue(333);
    LowCNoTongue(333);
    HighDNoTongue(667);
    
    HighENoTongue(667); //Measure 10
    HighERegularTongue(667);
    HighERegularTongue(1333);
    
    HighENoTongue(333); //Measure 11
    HighERegularTongue(333);
    HighDNoTongue(333);
    LowCNoTongue(333);
    HighDNoTongue(333);
    HighENoTongue(333);
    HighFNoTongue(667);
    
    HighGNoTongue(1333); //Measure 12
    LowCNoTongue(1333);
    LowCNoTongue(333);
    HighANoTongue(333);
    HighGNoTongue(333);
    HighFNoTongue(333);
    HighENoTongue(667);
    HighDNoTongue(667);
    
    LowCNoTongue(1333); //Measure 13
    LowCNoTongue(333); //Eighth Rest
    HighDNoTongue(333);
    HighENoTongue(333);
    HighFNoTongue(333);
    
    HighGNoTongue(667); //Measure 14
    HighFNoTongue(333);
    HighENoTongue(333);
    HighDNoTongue(1333);
    
    HighGNoTongue(667);
    LowCNoTongue(3000);
    
    //End of Heart and Soul
}

//Pokemon Medley
void Saximus::Pokemon_Medley()
{
    _Tempo = 100; //Set the Tempo to 100 BPM
    
    //Tune Up
    HighGNoTongue(3000);
    
    //Start of Pokemon Medley
    
    //LowC_SharpNoTongue();
    //LowC_SharpNoTongue();
    //HighG_SharpNoTongue();
    
    //End of Pokemon Medley
}

//Besame Mucho
void Saximus::Besame_Mucho()
{
    _Tempo = 100; //Set the Tempo to 90 BPM
    
    //Tune Up
    HighGNoTongue(4000);
    
    //Start of Besame Mucho
    
    HighGNoTongue(300); //Measure 1
    HighG_SharpNoTongue(300);
    HighANoTongue(300);
    HighBNoTongue(600);
    HighANoTongue(400);
    HighGNoTongue(400);
    
    HighF_SharpNoTongue(1500); //Measure 2
    HighGNoTongue(400);
    HighANoTongue(400);
    HighGNoTongue(400);
    
    HighF_SharpNoTongue(400); //Measure 3
    HighENoTongue(1300);
    HighF_SharpNoTongue(400);
    HighGNoTongue(400);
    HighF_SharpNoTongue(400);
    
    HighENoTongue(400);
    HighEbNoTongue(1300);
    
    HighGNoTongue(300); //Measure 4
    HighG_SharpNoTongue(300);
    HighANoTongue(300);
    HighBNoTongue(600);
    HighANoTongue(400);
    HighGNoTongue(400);
    
    HighF_SharpNoTongue(1500); //Measure 5
    HighGNoTongue(400);
    HighANoTongue(400);
    HighGNoTongue(400);
    
    
    HighF_SharpNoTongue(400); //Measure 6
    HighFNoTongue(1400);
    LowC_SharpNoTongue(300);
    HighDNoTongue(300);
    LowC_SharpNoTongue(300);
    LowCNoTongue(300);
    LowC_SharpNoTongue(300);
    
    HighF_SharpNoTongue(20000); //Measure 7
    
	//Make this up
    
	HighDNoTongue(300);
    HighENoTongue(300);
    HighF_SharpNoTongue(300);
    HighGNoTongue(300);
    HighF_SharpNoTongue(20000);
    
    HighDNoTongue(1000);
    HighEbNoTongue(300);
    HighENoTongue(400);
    HighEbNoTongue(300);
    HighENoTongue(400);
    HighDNoTongue(20000);
    
    HighDNoTongue(300);
    HighENoTongue(300);
    HighF_SharpNoTongue(300);
    HighGNoTongue(300);
    HighF_SharpNoTongue(20000);
    
    HighDNoTongue(1000);
    HighEbNoTongue(300);
    HighENoTongue(400);
    HighEbNoTongue(300);
    HighENoTongue(400);
    HighDNoTongue(20000);
    
    HighDNoTongue(300);
    HighENoTongue(300);
    HighF_SharpNoTongue(300);
    HighGNoTongue(300);
    HighF_SharpNoTongue(20000);
    //End of Besame Mucho
}