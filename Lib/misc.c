


#include "derivative.h"
#include <hidef.h>
#include "misc.h"
#include "SWL_LED.h"
#include "sci.h"
#include "stdlib.h"

int GetRandom( int iHighEx)
{
    int value = rand() % (iHighEx);

    return value;
}

int IsVowel(unsigned char *c)
{
    
    unsigned char ch = *c;

    switch (ch)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return 1; // It's a vowel
        default:
            return 0; // Not a vowel
    }
}
char getVowel(int capital)
{
    char vowel;
    static const char lowercaseVowels[] = "aeiou";
    static const char uppercaseVowels[] = "AEIOU";

    int index = rand() % 5;

    if (capital)
    {
        vowel = uppercaseVowels[index];
    }
    else
    {
        vowel = lowercaseVowels[index];
    }

    return vowel;
}

 

void transmit20Vowels(void)
{ char letter;
    int i=0;
    
    SWL_OFF(SWL_RED);

    for ( i = 0; i < 20; i++)
    {
        SWL_ON(SWL_RED);

        

        // Check if button is pushed for capital letters or not

        letter = getVowel(SWL_Pushed(SWL_CTR));

        sci0_txByte(letter);
    }
    SWL_OFF(SWL_RED);
}
/*
void transmit20VowelsWithSum(void)
{
    int sum = 0;

    SWL_OFF(SWL_RED);

    for (int i = 0; i < 20; i++)
    {
        SWL_ON(SWL_RED);

        char letter;

        // Check if button is pushed for capital letters or not
        letter = getRandomVowel(SWL_Pushed(SWL_CTR));

        sum += (int)letter;

        sci0_txByte(letter);
    }

    // Transmit space, followed by padded sum as a four-digit decimal number
    sci0_txByte(' ');

    char buffer[5];
    sprintf(buffer, "%04d", sum); // Format integer 'sum' as a zero-padded string

    for (int j = 0; j < 4; j++)
    {
        sci0_txByte(buffer[j]);
    }
    SWL_OFF(SWL_RED);
}

void transmit20VowelsWithSumColors(void)
{

    Console.Clear();
    int sum = 0;
    int NameDisplayed = 0;
    SWL_OFF(SWL_RED);
    Console.ForegroundColor = ConsoleColor.Orange;
    if (!NameDisplayed)
    {
        print("Marc Hannah");
        NameDisplayed = 1;
    }
    Console.ResetColor();

    for (int i = 0; i < 20; i++)
    {
        SWL_ON(SWL_RED);

        Console.SetCursorPosition(0, 2);
        Console.ForegroundColor = ConsoleColor.Green;
        char letter;

        // Check if button is pushed for capital letters or not

        letter = getVowel(SWL_Pushed(SWL_CTR)>0);

        sci0_txByte(letter);
        Console.ResetColor();
    }
    Console.SetCursorPosition(0, 4);
    Console.ForegroundColor = ConsoleColor.Green;
    // Transmit space, followed by padded sum as a four-digit decimal number
    sci0_txByte(' ');
    sprintf(sum);
    Console.ResetColor();
    SWL_OFF(SWL_RED);
    sum++;
}   */
