/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#include <ctype.h>

// User Libraries
#include "core.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// This function get the integer value followed by newline char.
int inputInt(void)
{
    int rate, loop;
    char lineN;
    do
    {
        loop = 1;
        scanf("%d%c", &rate, &lineN);

        if (lineN != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
            loop = 0;
        }

    } while (!loop);

    return rate;
}

//This function get the positive integer as a value.
int inputIntPositive(void)
{
    int numberPvt;
    int loop; // flag

    do {
        loop = 1;
        numberPvt = inputInt();
        if (numberPvt <= 0)
        {
            printf("ERROR! Value must be > 0: ");
            loop = 0;
        }
    } while (!loop);

    return numberPvt;;
}

//This function get the positive integer as a value within the boundaries of upper and lower limits.
int inputIntRange(int lowerLmt, int upperLmt)
{
    int number;
    int loop; //flag

    do {
        loop = 1;
        number = inputInt();
        if (number < lowerLmt || number > upperLmt)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ",
                lowerLmt, upperLmt);
            loop = 0;
        }
    } while (!loop);
    return number;;
}

// This function get the input of a character out of a specific range.
char inputCharOption(const char* charList)
{
    char enter;
    int i, looping = 0;

    do
    {
        i = 0;
        enter = getchar();
        do
        {
            if (enter == *(charList + i))
                looping = 1;
            i++;
        } while (looping != 1 && *(charList + i) != '\0');

        if (looping == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", charList);
        }

    } while (looping == 0);

    return enter;
}

// This function get the input of some string of a certain length. 
void inputCString(char* cString, int lengthMin, int lengthMax)
{
    int i;
    char example[100] = { '\0' };
    do
    {
        clearInputBuffer();
        i = 0;
        scanf("%[^\n]s", example);

        while (example[i] != '\0')
        {
            i++;
        }

        if (i < lengthMin || i > lengthMax)
        {
            if (lengthMin == lengthMax)
            {
                printf("ERROR: String length must be exactly %d chars: ", lengthMin);
            }
            else
            {
                if (i > lengthMax)
                {
                    printf("ERROR: String length must be no more than %d chars: ", lengthMax);
                }
                else if (i < lengthMin)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", lengthMin, lengthMax);
                }
            }
        }

    } while (i < lengthMin || i > lengthMax);

    for (i = i - 1; i > -1; i--)
    {
        cString[i] = example[i];
    }
}

//This function display the array of ten digits as a formatted phone number
void displayFormattedPhone(const char* phoneNum)
{
    int length = 0;
    int count = 0;


    while (phoneNum != NULL && phoneNum[length] && isdigit(phoneNum[length]))
    {
        length++;
    }

    if (length == 10)
    {
        putchar('(');
        while (count < 3)
        {
            printf("%c", phoneNum[count]);
            count++;
        }
        putchar(')');
        while (count < 6)
        {
            printf("%c", phoneNum[count]);
            count++;
        }
        putchar('-');
        while (count < 10)
        {
            printf("%c", phoneNum[count]);
            count++;
        }
    }
    else if (length == 11)
    {

        printf("(___)___-____");
    }
    else
    {

        printf("(___)___-____");
    }

    if (phoneNum != 0)
    {
        for (count = 0; phoneNum[count] != '\0'; count++)
            length++;
    }
}
