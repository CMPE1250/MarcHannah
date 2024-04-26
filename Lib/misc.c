

#include "derivative.h"
#include <hidef.h>
#include "misc.h"
#include "SWL_LED.h"
#include "sci.h"
#include "stdlib.h"
#include "stdio.h"
#include <math.h>
#include "segs.h"
#include "lcd.h"



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



void Lab1Init()
{

    char myName[] = "Marc Hannah";
    char labTitle[] = "Simple Binary Calculator";
    char opA[] = "Op A: 0x0000";
    char opB[] = "OP B: 0x0000";
    char line[] = "----------------";
    char binA[]= "000000000000000";
    char binB[]= "000000000000000";
    char result[]="000000000000000";


   sci0_txStrXY (1,1,myName);

    sci0_txStrXY(1, 2, labTitle);

    sci0_txStrXY(5, 5, opA);

    sci0_txStrXY(5, 6, opB);

    sci0_txStrXY(11,8,binA);
    sci0_txStrXY(11,9,binB);
    sci0_txStrXY(11, 10, line);
    sci0_txByteXY(9,9,'&');
    sci0_txStrXY(11,11,result);



    sci0_GotoXY(13,5);
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
    int i;
    int exp=0;

    for (i = 3; i>= 0; i--)
    {

       
       result+=ToDigitVal(pArray[i])*Power(16,exp);
        exp++;


    }

    return result;
}

int Power(int base, unsigned int exp)
{
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}


void Lab3SegsInit(void)
{

    PORTA |= 0x03;
    DDRA |= 0x03;
    DDRB |= 0xFF;

    Segs_Clear();


    Segs_16D(0,Segs_LineTop);
    Segs_16D(0,Segs_LineBottom);
    Segs_Normal(0,0,Segs_DP_ON);



}

void testInit(void)
{   
    lcd_AddrXY(2,3);
    lcd_String("0000000000000000");

     lcd_AddrXY(0,1);
    lcd_String("DEC: 00000");
    lcd_AddrXY(0,2);
    lcd_String("Hex: 0000");
    lcd_AddrXY(20,3);

}