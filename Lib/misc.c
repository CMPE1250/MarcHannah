

#include "derivative.h"
#include <hidef.h>
#include "misc.h"
#include "SWL_LED.h"
#include "sci.h"
#include "stdlib.h"
#include "stdio.h"
#include <math.h>

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
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    letterIndex = GetRandom(52);

    letter = alphabet[letterIndex];
    return letter;
}

int ToDigitVal(char digit)
{

    if (digit >= '0' && digit <= '9')
    {
       return digit-48;
   }

    if (digit =='A' || digit == 'a')
    {
        return 10;
    }

    if (digit == 'b' || digit == 'B')
    {
        return 11;
    }

    if (digit == 'c' || digit == 'C')
    {
        return 12;
    }

    if (digit == 'd' || digit == 'D')
    {
        return 13;
    }

    if (digit == 'e' || digit == 'E')
    {
        return 14;
    }
   
    if (digit == 'f' || digit == 'F')
        {
         return 15;
        }
}

unsigned int HexArrayToUInt16(char *pArray)
{
    unsigned int result = 0;
    int i = 0;
    int exp=1;

    for (i = 3; i > 0; i++)
    {

       
       result+=ToDigitVal(pArray[i])*Power(16,exp);
        exp++;


    }

    return result;
}

void Lab1Init()
{

    char myName[] = "Marc Hannah";
    char labTitle[] = "Simple Binary Calculator";
    char opA[] = "Op A:";
    char opB[] = "OP B:";
    char line[] = "----------";



   sci0_txStrXY (1,1,myName);

    sci0_txStrXY(1, 2, labTitle);

    sci0_txStrXY(5, 5, opA);

    sci0_txStrXY(5, 6, opB);

    sci0_txStrXY(11, 10, line);
}

void Parseinput(unsigned char input)
{

    int flip;

    if (input == '|')
    {
        sci0_txByteXY(11, 10, '|');
    }

    if (input == '&')
    {
        sci0_txByteXY(11, 12, '|');
    }

    if (input == '\x09')
    {
        if (flip)
        {
            sci0_GotoXY(10, 10);
            flip = 0;
        }
        else
        {
            sci0_GotoXY(10, 9);
            flip = 1;
        }
    }

    if (IsHexLetter(input))
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
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
    {
        return 1;
    }
    else
        return 0;
}

int Power(int base, unsigned int exp)
{
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}
