/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
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

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* numPositive)
{
	int put;
	do
	{
		scanf("%d", &put);
		if (put <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (put <= 0);
	if (numPositive != NULL)
	{
		*numPositive = put;
	}
	return put;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* numPositive)
{
	double put;
	do
	{
		scanf("%lf", &put);
		if (put <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (put <= 0);
	if (numPositive != NULL)
	{
		*numPositive = put;
	}
	return put;
}



// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numProduct)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAXIMUM_PRODUCT);
	printf("NOTE: A 'serving' is %dg\n\n", GRAMS_NUMBER);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProduct)
{
	struct CatFoodInfo catFood = { 0 };
	printf("Cat Food Product #%d\n", numProduct);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&catFood.skuNumber);

	printf("PRICE         : $");
	getDoublePositive(&catFood.productPrice);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&catFood.poundsWeight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&catFood.calories);

	printf("\n");

	return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* Price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *Price, *weight, calories);
}


// 7. Logic entry point

void start(void)
{
	int i;
	struct CatFoodInfo  CatFood[MAXIMUM_PRODUCT] = { {0} };
	openingMessage(MAXIMUM_PRODUCT);

	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		CatFood[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAXIMUM_PRODUCT; i++)
	{
		displayCatFoodData(CatFood[i].skuNumber, &CatFood[i].productPrice, CatFood[i].calories, &CatFood[i].poundsWeight);
	}

}
