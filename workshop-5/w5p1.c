/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  :Tejasvi Parmar
Section    :ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012     
#define MAX_YEAR 2022      
#define LOG_DAYS 1

int main(void)
{
    //variable declaration.....
    const int JAN = 1, DEC = 12;
    int months, year, i, validation = 1;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        validation = 1;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &months);

        if (year <MIN_YEAR || year >MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            validation = 0;
        }

        if (months < JAN || months > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            validation = 0;
        }
    } while (validation == 0);

    printf("\n*** Log date set! ***\n\n");

    // using a 'for' loop for log days.....
    for (i = 1; i <= LOG_DAYS; i++)
    {
        printf("Log starting date: %d", year);
        printf("-");

        //using switch case for months.........
        switch (months)   
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APR");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        }
        if (i < 9)
        {
            printf("-0%d\n", i);
        }
        else
        {
            printf("-0%d\n", i);
        }
    }
    return 0;
}
