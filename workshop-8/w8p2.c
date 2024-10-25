/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
Full Name  :Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
void openingMessage(const int product)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", product);
	printf("NOTE: A 'serving' is %dg\n\n", SERVINGS_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProduct)
{
	struct CatFoodInfo catFood = { 0 };
	printf("Cat Food Product #%d\n", numProduct + 1);
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



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* equalKg)
{
	double kilograms;
	kilograms = (*pounds) / CONVERSION_FACTOR;
	if (equalKg != NULL)
	{
		*equalKg = kilograms;
	}
	return  kilograms;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* equalG)
{
	int grams;
	grams = convertLbsKg(pounds, 0) * 1000;
	if (equalG != NULL)
	{
		*equalG = grams;
	}
	return grams;
}
// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* equalKg, int* equalG)
{
	convertLbsKg(pounds, equalKg);
	convertLbsG(pounds, equalG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrams, double* serveResult)
{

	double servs = (double)totalGrams / servingSize;

	if (serveResult != NULL) {
		*serveResult = servs;
	}
	return servs;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* servings, double* costPerServing)
{

	double cost = *price / *servings;

	if (costPerServing != NULL)
	{
		*costPerServing = cost;
	}
	return cost;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalServing, double* costOfServing)
{

	double cost = *price / *totalServing;

	if (costOfServing != NULL)
	{
		*costOfServing = cost;
	}
	return cost;
}
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFood)
{

	struct ReportData reportInfo = { 0 };

	reportInfo.skuNum = catFood.skuNumber;
	reportInfo.prices = catFood.productPrice;
	reportInfo.serveCalorie = catFood.calories;
	reportInfo.lbsWgt = catFood.poundsWeight;

	reportInfo.kgWgt = convertLbsKg(&reportInfo.lbsWgt, &reportInfo.kgWgt);
	reportInfo.gramsWgt = convertLbsG(&reportInfo.lbsWgt, &reportInfo.gramsWgt);
	reportInfo.servingTotal = calculateServings(SERVINGS_GRAMS, reportInfo.gramsWgt, &reportInfo.servingTotal);
	reportInfo.servingCost = calculateCostPerServing(&reportInfo.prices, &reportInfo.servingTotal, &reportInfo.servingCost);

	double calories = reportInfo.serveCalorie * reportInfo.servingTotal;

	reportInfo.servingCostCalorie = calculateCostPerCal(&reportInfo.prices, &calories, &reportInfo.servingCostCalorie);

	return reportInfo;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SERVINGS_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportInfo, const int cheapProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportInfo.skuNum, reportInfo.prices, reportInfo.lbsWgt, reportInfo.kgWgt, reportInfo.gramsWgt, reportInfo.serveCalorie, reportInfo.servingTotal, reportInfo.servingCost, reportInfo.servingCostCalorie);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFood)
{

	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", catFood.skuNumber, catFood.productPrice);
	printf("\n");

	// last line of the code.......
	printf("Happy shopping!\n");
	printf("\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFood[MAXIMUM_PRODUCTS] = { { 0 } };
	struct ReportData reportInfo[MAXIMUM_PRODUCTS] = { { 0 } };

	openingMessage(MAXIMUM_PRODUCTS);

	int i, cheap = 0;
	double cheapPrice;

	//Loop to get cat food info for Maximum product.......
	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{
		catFood[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();

	//Loop to display cat food info.......
	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{
		displayCatFoodData(catFood[i].skuNumber, &catFood[i].productPrice, catFood[i].calories, &catFood[i].poundsWeight);
	}

	//Loop for the report data......
	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{
		reportInfo[i] = calculateReportData(catFood[i]);

	}

	//cheapest product by price per serving......
	cheapPrice = reportInfo[cheap].servingCost;
	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{
		if (reportInfo[i].servingCost <= cheapPrice)
		{
			cheapPrice = reportInfo[i].servingCost;
			cheap = i;
		}
	}

	displayReportHeader();

	//displaying the Report Data with ***......

	for (i = 0; i < MAXIMUM_PRODUCTS; i++)

	{
		displayReportData(reportInfo[i], i);
		if (cheap == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}

	//displaying the final analysis.....

	for (i = 0; i < MAXIMUM_PRODUCTS; i++)
	{
		if (i == cheap)
		{
			displayFinalAnalysis(catFood[i]);
		}
	}
}
