/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <ctype.h>
#include <string.h>

#include "core.h"

#define MAXIMUM_NUMBER 2000

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

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

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//


// This function get the integer value followed by newline char
int inputInt(void)
{
    int put, loop = 1;
    char character;

    do
    {
        scanf("%d%c", &put, &character);
        if (character == '\n')
        {
            loop = 0;
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (loop == 1);
    return put;
}

//This function get the positive integer as a value
int inputIntPositive(void)
{
    int put, loop = 1;
    char character;

    do
    {
        scanf(" %d%c", &put, &character);
        if (character == '\n')
        {
            if (put > 0)
            {
                loop = 0;
            }
            else
            {
                printf("ERROR! Value must be > 0: ");
            }
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (loop == 1);
    return put;
}

//This function get the positive integer as a value within the boundaries of upper and lower limits
int inputIntRange(int lowRange, int highRange)
{
    int put, loop = 1;
    char character;

    do
    {
        scanf(" %d%c", &put, &character);
        if (character == '\n')
        {
            if (put >= lowRange && put <= highRange)
            {
                loop = 0;
            }
            else
            {
                printf("ERROR! Value must be between %d and %d inclusive: ", lowRange, highRange);
            }
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (loop == 1);
    return put;
}

// This function get the input of a character out of a specific range
char inputCharOption(const char* string)
{

    char Character, newCharacter, * rate;
    int loop = 1;

    do
    {
        scanf("%c%c", &Character, &newCharacter);
        if (newCharacter == '\n')
        {
            loop = 1;
            rate = strchr(string, Character);
            if (rate != NULL)
            {
                loop = 0;
            }
        }
        else
        {
            clearInputBuffer();
            loop = 1;
        }

        if (loop)
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (loop);
    return Character;
}

// This function get the input of some string of a certain length
void inputCString(char* string, int minimumChar, int maximumChar)
{
    char character[MAXIMUM_NUMBER] = { 0 };
    int charaterNum, loop = 1;

    do
    {
        loop = 1;
        charaterNum = 0;
        scanf("%[^\n]", character);

        charaterNum = strlen(character);
        if (maximumChar != charaterNum && minimumChar == maximumChar)
        {
            printf("ERROR: String length must be exactly %d chars: ", maximumChar);
            loop = 0;
        }
        else if (minimumChar > charaterNum)
        {
            printf("ERROR: String length must be between %d and %d chars: ", minimumChar, maximumChar);
            loop = 0;
        }
        else if (maximumChar < charaterNum)
        {
            printf("ERROR: String length must be no more than %d chars: ", maximumChar);
            loop = 0;
        }
        clearInputBuffer();
    } while (!loop);


    strcpy(string, character);
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////


//This function display the array of ten digits as a formatted phone number
void displayFormattedPhone(const char* string)
{
    int characterNum = 0, length;
    int loop = 1;

    if (string != NULL)
    {
        length = strlen(string);
        if (length != 10)
        {
            loop = 0;
        }
        for (characterNum = 0; characterNum < length; characterNum++)
        {
            if (string[characterNum] < '0' || string[characterNum] > '9')
            {
                loop = 0;
            }
        }
    }
    if (loop != 1 || characterNum != 10)
    {
        printf("(___)___-____");
    }
    else
    {
        printf("(%3.3s)%3.3s-%4.4s", string, &string[3], &string[6]);
    }
}
