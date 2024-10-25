/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ITEM_LIST 10
#define MAXIMUM_ITEM 3
#define	MINIMUM_ITEM 1



int main(void)
{

    //variable declared.....
    double income, total = 0;
    const double MINIMUM_INCOME = 500, MAXIMUM_INCOME = 400000.00, MINIMUM_PRICE = 100;
    double price[ITEM_LIST] = { 0 };
    char finance[ITEM_LIST] = { 0 };
    int list, i, IMPORTANT_ITEMS[ITEM_LIST] = { 0 };

    // flag variable.....
    int valid;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    // Input for monthly income.....
    valid = 1;
    do
    {
        valid = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < MINIMUM_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MINIMUM_INCOME);
        }
        else if (income > MAXIMUM_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAXIMUM_INCOME);
        }
        else
        {
            valid = 0;
        }
    } while (valid);

 
    do
    {
        valid = 1;
        printf("\n");
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &list);

        if (list < MINIMUM_ITEM || list > MAXIMUM_ITEM)
        {
            printf("ERROR: List is restricted to between %d and %d items.\n", MINIMUM_ITEM, ITEM_LIST);
        }
        else
        {
            valid = 0;
        }
    } while (valid);

    // item listing starts.....
    for (i = 0; i < list; i++)
    {
        printf("\n");
        printf("Item-%d Details:", i + 1);
        printf("\n");

        do
        {
            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &price[i]);

            if (price[i] < 100)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", MINIMUM_PRICE);
            }
            else
            {
                total = total + price[i];
                valid = 0;
            }
        } while (valid);

        do
        {
            valid = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &IMPORTANT_ITEMS[i]);

            if (IMPORTANT_ITEMS[i] < MINIMUM_ITEM || IMPORTANT_ITEMS[i] > MAXIMUM_ITEM)
            {
                printf("      ERROR: Value must be between %d and %d\n", MINIMUM_ITEM, MAXIMUM_ITEM);
            }
            else
            {
                valid = 0;
            }
        } while (valid);

        do
        {
            valid = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);

            if (!(finance[i] == 'n' || finance[i] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {
                valid = 0;
            }

        } while (valid);

    }
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < list; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, IMPORTANT_ITEMS[i], finance[i], price[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
/*
 HELPER: printf formatting statements....
 =========================================

 Step #7:
     printf("Item Priority Financed        Cost\n");
     printf("---- -------- -------- -----------\n");

     printf("%3d  %5d    %5c    %11.2lf\n", ...


 Step #8:
     printf("---- -------- -------- -----------\n");
     printf("                      $%11.2lf\n\n", ...

*/
