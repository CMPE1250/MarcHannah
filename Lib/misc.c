

#include "derivative.h"
#include <hidef.h>
#include "misc.h"
#include "SWL_LED.h"
#include "sci.h"
#include "stdlib.h"
#include "stdio.h"




int GetRandom(int iHighEx)
{
    int value = rand() % (iHighEx);

    return value;
}

int GetRandomMin(int min, int exMax)
{
    int range = exMax - min + 1;
    int value = rand() % range + min;

    return value;
}


int IsVowel(unsigned char c)
{

    if (c == 'a' || c == 'A')
    {
        return 1;
    }
    else if (c == 'e' || c == 'E')
    {
        return 1;
    }
    else if (c == 'i' || c == 'I')
    {
        return 1;
    }
    else if (c == 'o' || c == 'O')
    {
        return 1;
    }
    else if (c == 'u' || c == 'U')
    {
        return 1;
    }
    else
        return 0;
}

char getVowel(int capital)
{
    char lowercaseVowels[] = "aeiou";
    char uppercaseVowels[] = "AEIOU";

  
    char *vowels = capital ? uppercaseVowels : lowercaseVowels;


    int numVowels = GetRandom(5);

    char vowel = vowels[numVowels];

    return vowel;
}

 char getLetter()
 {
   
    char letter;
    int letterIndex;
    char alphabet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    

   
        letterIndex = GetRandom(52);

        letter = alphabet[letterIndex];
        return letter;
  
            
    

}



int ToDigitVal(char digit) {
    if (digit >= '0' && digit <= '9') {
        return digit - '0';
    }
     else if (digit >= 'a' && digit <= 'f') {
        return 10 + (digit - 'a');
    }
     else if (digit >= 'A' && digit <= 'F') {
        return 10 + (digit - 'A');
    }
     else {
        
        return 0;
    }
}



unsigned int HexArrayToUInt16(char *pArray) {
    unsigned int result = 0;
    int i=0;
   
   
   
    for ( i = 0; i < 4; i++) {
        
        int digitValue = ToDigitVal(pArray[i]);
        
        // Update the result by shifting previous values to the left by multiplying with 16 and adding current digit value
        result+=digitValue;
    }
    
    return result;
}





void Lab1Init()
{
   
   
   
    char myName[]="Marc Hannah";
    char labTitle[]="Simple Binary Calculator";
    char opA[]="Op A:";
    char opB[]="OP B:";
    char line[]="----------";






    
    sci0_txStr(myName);
   
    sci0_txStrXY(1,2,labTitle);

    sci0_txStrXY(5,5,opA);
   
    sci0_txStrXY(5,6,opB);
   
    sci0_txStrXY(11,10,line);

}





void Parseinput( unsigned char input)
{
    
    int flip;


 if (input == '|')
    { 
        sci0_txByteXY(11,10,'|');
     
    }

 if (input == '&')
    { 
        sci0_txByteXY(11,12,'|');
   
    }

 if (input == '\x09')
    { 
            if(flip)
        {
            sci0_GotoXY(10,10);
            flip=0;
            }
        else
        {
            sci0_GotoXY(10,9);
            flip=1;
        }
       
    }

if(IsHexLetter(input))
{
    sci0_txByte(input);
}



}



int IsHexLetter(unsigned char c)
{

    if (c == 'a' || c == 'A')
    {
        return 1;
    }
    else if (c == 'b' || c == 'B')
    {
        return 1;
    }
    else if (c == 'c' || c == 'C')
    {
        return 1;
    }
    else if (c == 'd' || c == 'D')
    {
        return 1;
    }
    else if (c == 'E' || c == 'E')
    {
        return 1;
    }
    else if (c == 'f' || c == 'F')
    {
        return 1;
    }
    if (c == '1' || c == '2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
    {
        return 1;
    }
    else
        return 0;
}














void transmit20Vowels(void)
{
    char letter;
    int i = 0;
    char vowelstring[22] = "";
    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));
        vowelstring[i] = letter;
    }

    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);
    SWL_OFF(SWL_RED);
}

void transmit20VowelsWithSum(void)
{
    int sum=0;
    char letter;
    int i = 0;
    char vowelstring[22];
    char buffer[10];

    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));

        vowelstring[i] = letter; 

        sum+=letter;
    }
   
    sprintf(buffer, "   %04d  ",sum );
  
  
  
    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);

    sci0_txByte(' ');
  
    
  
    sci0_txStr(buffer);
    sci0_txByte(' ');
    SWL_OFF(SWL_RED);
}

int NameDisplayed = 0;

void transmit20VowelsWithSumColors(void)
{
    int sum = 0;
    char letter;
    int i = 0;
    char vowelstring[22] = "";
    char buffer[10] = "";
    char myName[20] = "Marc Hannah";

    SWL_OFF(SWL_RED);

    if (!NameDisplayed)
    {
        sci0_txStr("\x1b[31m");
        sci0_txStr(myName);
        NameDisplayed += 1;

        
    }

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));
        sum+=letter;
        vowelstring[i] = letter; 
    }

    SWL_ON(SWL_RED);

    sci0_txStr("\x1b[0;2H");
    sci0_txStr("\x1b[31m");
    sci0_txStr(vowelstring);
    sci0_txStr("\x1b[37m");

    sci0_txByte(' ');
    sprintf(buffer, "%04d", sum);
    sci0_txStr("\x1b[33m");
    sci0_txStr(buffer);
    sci0_txStr("\x1b[37m");
    sci0_txByte(' ');
   
   sci0_txStr("\x1b[0;4H");
   
   
    SWL_OFF(SWL_RED);

    sci0_txStr("\x1b[2J");
}
