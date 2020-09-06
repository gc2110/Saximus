//
//  Saximus.h
//
//
//  Created by Giancarlo Lezama on 1/9/15.
//
//

#ifndef ____Saximus__
#define ____Saximus__

#include "Servo.h"
#include "Arduino.h"

class Saximus
{
    
public:
    
    Saximus(int OctaveKeyPin, int Upper1stKeyPin, int Upper2ndKeyPin, int Upper3rdKeyPin, int Lower1stKeyPin, int Lower2ndKeyPin, int Lower3rdKeyPin, int Altissimo_D_Keypin, int EbKeyPin, int A_SharpKeyPin, int G_SharpKeyPin, int Tongue_Motor, int Tempo);
    
    void ResetAllSolenoids(); //Resets all solenoids
    
    //All Types of Rests
    void Whole_Note_Rest();
    void Half_Note_Rest();
    void Quarter_Rest();
    void Dotted_Quarter_Rest();
    void Eighth_Rest();
    void Dotted_Eighth_Rest();
    void Sixteenth_Rest();
    
    //All notes to be played on the saxophone
    void LowDRegularTongue(int NoteLength);
    void LowERegularTongue(int NoteLength);
    void LowEbRegularTongue(int NoteLength);
    void LowFRegularTongue(int NoteLength);
    void LowF_SharpRegularTongue(int NoteLength);
    void LowGRegularTongue(int NoteLength);
    void LowG_SharpRegularTongue(int NoteLength);
    void LowARegularTongue(int NoteLength);
    void LowA_SharpRegularTongue(int NoteLength);
    void LowBRegularTongue(int NoteLength);
    void LowCRegularTongue(int NoteLength);
    void LowC_SharpRegularTongue(int Notelength);
    void HighDRegularTongue(int NoteLength);
    void HighEbRegularTongue(int NoteLength);
    void HighERegularTongue(int NoteLength);
    void HighFRegularTongue(int NoteLength);
    void HighF_SharpRegularTongue(int NoteLength);
    void HighGRegularTongue(int NoteLength);
    void HighG_SharpRegularTongue(int NoteLength);
    void HighARegularTongue(int NoteLength);
    void HighA_SharpRegularTongue(int NoteLength);
    void HighBRegularTongue(int NoteLength);
    void HighCRegularTongue(int NoteLength);
    void HighC_SharpRegularTongue(int NoteLength);
    void AltissimoDRegularTongue(int Notelength);
    
    void LowDNoTongue(int Notelength);
    void LowENoTongue(int NoteLength);
    void LowEbNoTongue(int NoteLength);
    void LowFNoTongue(int NoteLength);
    void LowF_SharpNoTongue(int NoteLength);
    void LowGNoTongue(int NoteLength);
    void LowG_SharpNoTongue(int NoteLength);
    void LowANoTongue(int NoteLength);
    void LowA_SharpNoTongue(int NoteLength);
    void LowBNoTongue(int NoteLength);
    void LowCNoTongue(int NoteLength);
    void LowC_SharpNoTongue(int Notelength);
    void HighDNoTongue(int NoteLength);
    void HighEbNoTongue(int NoteLength);
    void HighENoTongue(int NoteLength);
    void HighFNoTongue(int NoteLength);
    void HighF_SharpNoTongue(int NoteLength);
    void HighGNoTongue(int NoteLength);
    void HighG_SharpNoTongue(int NoteLength);
    void HighANoTongue(int NoteLength);
    void HighA_SharpNoTongue(int NoteLength);
    void HighBNoTongue(int NoteLength);
    void HighCNoTongue(int NoteLength);
    void HighC_SharpNoTongue(int NoteLength);
    void AltissimoDNoTongue(int Notelength);
    
    //Tests Low G to tune the Saximus
    void TunerNote();
    
    //Tests the Eb Concert Scale on the alto saxophone
    void Blues_Scale();
    
    // Plays Hey Jude
    // Link to the Song:
    // cloud.freehandmusic.netdna-cdn.com/preview/530x4/sony/snylmhyjudls.png
    void Hey_Jude();
    
    // Plays Mary Had a Little Lamb
    // Link to the Song:
    // www.youtube.com/watch?v=_8vu1brDtEA
    void MHALL();
    
    // The Pink Panther
    // Here's the link to the sheet music:
    // www.musicnotes.com/images/productimages/mtd/MN0026912.gif
    void Pink_Panther();
    
    // Baker Street
    void Baker_Street();
    
    // Careless Whisper
    void Careless_Whisper();
    
    // Oh, Pretty Woman-Roy Orbison
    void Pretty_Woman();
    
    // The Final Countdown
    void The_Final_Countdown();
    
    // Livin' on a Prayer
    void Livin_On_A_Prayer();
    
    // Sweet Dreams-Eurythomics
    void Sweet_Dreams();
    
    // ABC-The Jackson 5
    void ABC();
    
    //Legend of Zelda
    void Zelda();
    
    //Spiderman Theme
    void Spiderman_Theme();
    
    //Tequila
    void Tequila();
    
    //Legend of Zelda
    void Zelda_Woods();
    
    //Summertime 
    void Summertime();
    
    //HeartandSoul
    void HeartandSoul();
    
    //Pokemon Medley
    void Pokemon_Medley();
    
    //Besame Mucho
    void Besame_Mucho();
    
private:

    int _OctaveKeyPin; // Octave Key
    int _Upper1stKeyPin;// Upper 1st Key
    int _Upper2ndKeyPin;// Upper 2nd Key
    int _Upper3rdKeyPin;// Upper 3rd Key
    int _Lower1stKeyPin;// Lower 1st Key
    int _Lower2ndKeyPin;// Lower 2nd Key
    int _Lower3rdKeyPin;// Lower 3rd Key
    int _Altissimo_D_Keypin;// High D Key
    int _EbKeyPin;// Eb Key
    int _A_SharpKeyPin;// A_Sharp/Bb Key Above Eb Key
    int _G_SharpKeyPin;// G_Sharp Key
    
    int _Tongue_Motor; // Pin for Servo for Tongue
    
    int _Tempo; //Song Tempo in BPM
    int _Whole_Note_Delay; // Delay Time for a Whole Note Using the Tempo
    int _Half_Note_Delay; // Delay Time for a Half Note Using the Tempo
    int _Quarter_Delay; // Delay Time for a Quarter Note Using the Tempo
    int _Dotted_Quarter_Delay; // Delay Time for a Dotted Quarter Note Using the Tempo
    int _8th_Delay; // Delay Time for an Eighth Note Using the Tempo
    int _Dotted_8th_Delay; // Delay Time for a Dotted Eighth Note Using the Tempo
    int _16th_Delay; // Delay Time for a Sixteenth Note Using the Tempo
    int _32nd_Delay; // Delay Time for a 32nd Note Using the Tempo
};


#endif /* defined(____Saximus__) */