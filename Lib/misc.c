

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

    // Determine the set of vowels based on capital
    char * vowels = capital ? uppercaseVowels : lowercaseVowels;

    // Get a random index within the valid range
    int numVowels = GetRandom(5);

    // Retrieve the vowel at the selected index
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
        vowelstring[i] = letter; // Store the vowel in the array
    }

    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);
    SWL_OFF(SWL_RED);
}

void transmit20VowelsWithSum(void)
{

    char letter;
    int i = 0;
    char vowelstring[22] = "";
    SWL_OFF(SWL_RED);

    for (i = 0; i < 20; i++)
    {
        letter = getVowel(SWL_Pushed(SWL_CTR));
        vowelstring[i] = letter; // Store the vowel in the array
    }

    SWL_ON(SWL_RED);
    sci0_txStr(vowelstring);
    SWL_OFF(SWL_RED);

    sci0_txByte(' ');

    char buffer[10] = "";


}
  //  sprintf(buffer, "%04d", sum); // Format integer 'sum' as a zero-padded string

  //  sci0_txStr(buffer);

  //  SWL_OFF(SWL_RED);

/*
void transmit20VowelsWithSumColors(void)
{

    Console.Clear();
    int sum = 0;
    int NameDisplayed = 0;
    SWL_OFF(SWL_RED);
   
    if (!NameDisplayed)
    {
        print("Marc Hannah");
        NameDisplayed = 1;
    }
  

    for (int i = 0; i < 20; i++)
    {
        SWL_ON(SWL_RED);

       
    
        char letter;

        // Check if button is pushed for capital letters or not

        letter = getVowel(SWL_Pushed(SWL_CTR)>0);

        sci0_txByte(letter);
        Console.ResetColor();
    }
  
   
    // Transmit space, followed by padded sum as a four-digit decimal number
    sci0_txByte(' ');
    sprintf(sum);
    Console.ResetColor();
    SWL_OFF(SWL_RED);
    sum++;
}   */
