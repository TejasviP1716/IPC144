/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Tejasvi Nitinkumar Parmar
Student ID#: 151236239
Email      : tnparmar2@myseneca.ca
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012     
#define MAX_YEAR 2022      
#define LOG_DAYS 3         

int main(void)
{
    //variable declartion.....
    const int JAN = 1, DEC = 12;
    int months, year, i, carryon = 1;
    double morningRating, eveningRating, morningTotal = 0, eveningTotal = 0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        carryon = 1;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &months);

        if (year <MIN_YEAR || year >MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            carryon = 0;
        }

        if (months < JAN || months > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
            carryon = 0;
        }
    } while (carryon == 0);

    printf("\n*** Log date set! ***\n\n");

    // using a 'for' loop for log days.....
    for (i = 1; i <= LOG_DAYS; i++)
    {
        printf("%d", year);
        printf("-");
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
        // morning rates calculation ......
        printf("   Morning rating (0.0-5.0): ");
        scanf("%lf", &morningRating);

        while (!(morningRating >= 0.0 && morningRating <= 5.0))
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
        }
        // evening rates calculation.....
        printf("   Evening rating (0.0-5.0): ");
        scanf("%lf", &eveningRating);

        while (!(eveningRating >= 0.0 && eveningRating <= 5.0))
        {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
        }

        morningTotal = morningTotal + morningRating;
        eveningTotal = eveningTotal + eveningRating;
        printf("\n");
        carryon = 0;

    }

    printf("Summary\n");
    printf("=======\n");

    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating:  %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningTotal + eveningTotal);


    printf("Average morning rating:  %.1lf\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n\n", ((morningTotal / LOG_DAYS) + (eveningTotal / LOG_DAYS)) / 2);



    return 0;

}
