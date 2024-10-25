/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P2)
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
#define MAXIMUM_ITEMS 3
#define MINIMUM_ITEMS 1

int main(void)
{
	// Minimum and max incomes and minimum cost......
	const double MIN_INCOME = 500.00, MAX_INCOME = 400000.00, MIN_COST = 100.00;

	// Variable declarations.....
	double income = 0, costItem[ITEM_LIST] = { 0 }, total = 0;
	int i, looping = 0, listItems = 0, IMPROTANT_ITEM[ITEM_LIST] = { 0 }, selectItem, primarySelect, SELECTION = 0; // looping is the flag variable.....
	char  financeItem[ITEM_LIST] = { 0 };

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	// Input for month income.....
	do
	{
		printf("\n");
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);
		if (income > MIN_INCOME && income < MAX_INCOME)
		{
			looping = 1;
		}
		else if (income < MIN_INCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
		}
		else
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);
		}
	} while (looping != 1);

	// Enter number of items......
	looping = 0;
	do
	{
		printf("\n");
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &listItems);
		if (listItems > MINIMUM_ITEMS && listItems < ITEM_LIST)
		{
			looping = 1;
		}
		else
		{
			printf("ERROR: List is restricted to between %d and %d items.\n", MINIMUM_ITEMS, ITEM_LIST);
		}
	} while (looping != 1);

	for (i = 0; i < listItems; i++)
	{
		printf("\n");
		printf("Item-%d Details:\n", i + 1);
		looping = 0;
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &costItem[i]);
			if (costItem[i] > 100)
			{
				looping = 1;
			}
			else
			{
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
			}
		} while (looping != 1);

		looping = 0;
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &IMPROTANT_ITEM[i]);
			if (IMPROTANT_ITEM[i] == 1 || IMPROTANT_ITEM[i] == 2 || IMPROTANT_ITEM[i] == 3)
			{
				looping = 1;
			}
			else
			{
				printf("      ERROR: Value must be between %d and %d\n", MINIMUM_ITEMS, MAXIMUM_ITEMS);
			}
		} while (looping != 1);

		looping = 0;
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &financeItem[i]);
			if (financeItem[i] == 'y' || financeItem[i] == 'n')
			{
				looping = 1;
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (looping != 1);
	}

	// Summary calcution of total income.....
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < listItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, IMPROTANT_ITEM[i], financeItem[i], costItem[i]);
		total += costItem[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total);

	looping = 0;

	// Wish your list forecast calculation starts.....
	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selectItem);
		printf("\n");
		switch (selectItem)
		{
		case 0:
			looping = 1;
			break;

		case 1:
			total = 0;
			SELECTION = 0;
			for (i = 0; i < listItems; i++)
			{
				total += costItem[i];
				if (financeItem[i] == 'y')
				{
					SELECTION = 1;
				}
			}
			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total);
			printf("Forecast: %d years, %d months\n", (int)(total / income / 12), (int)(((total / income / 12) - (int)(total / income / 12) + 0.05) * 12 + 0.5));
			if (SELECTION == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}printf("====================================================\n\n");
			break;

		case 2:
			printf("What priority do you want to filter by? [1-3]: ");
			scanf("%d", &primarySelect);
			printf("\n");
			total = 0;
			SELECTION = 0;
			for (i = 0; i < listItems; i++)
			{
				if (IMPROTANT_ITEM[i] == primarySelect)
				{
					total += costItem[i];

					if (financeItem[i] == 'y')
					{
						SELECTION = 1;
					}
				}
			}
			printf("====================================================\n");
			printf("Filter:   by priority (%d)\n", primarySelect);
			printf("Amount:   $%.2lf\n", total);
			printf("Forecast: %d years, %d months\n", (int)(total / income / 12), (int)(((total / income / 12) - (int)(total / income / 12) + 0.05) * 12 + 0.5));

			if (SELECTION == 1)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
			break;
		default:
			printf("ERROR: Invalid menu selection.\n\n");
			break;
		}

	} while (looping != 1);

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}
