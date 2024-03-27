

#include "derivative.h"
#include <hidef.h>
#include "misc.h"
#include "SWL_LED.h"
#include "sci.h"
#include "stdlib.h"

int GetRandom(int iHighEx)
{
    int value = rand() % (iHighEx);

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
    int sum = 0;
    char letter;
    int i = 0;
    char vowelstring[22] = "";
    char buffer[10] = "";

    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));

        vowelstring[i] = letter; 
        sum+=letter;
    }

    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);

    sci0_txByte(' ');
    sprintf(buffer, "%04d", sum);
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

        ;
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
