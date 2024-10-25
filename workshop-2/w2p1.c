/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

	//Variable declarations
    double smallPrice, mediumPrice, largePrice;
    int subTotal, taxes, totalShirt, total;

	//user enter the all three different shirt price's
	printf("Set Shirt Prices\n");
	printf("================\n");

	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &smallPrice);
	
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &mediumPrice);
	
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &largePrice);
	printf("\n");
	

	// Display the shirt price's
	printf("Shirt Store Price List\n");
	printf("======================\n");

	printf("SMALL  : $%.2lf", smallPrice); //for small shirt 
	printf("\n");
	printf("MEDIUM : $%.2lf", mediumPrice); //for medium shirt
	printf("\n");
	printf("LARGE  : $%.2lf", largePrice); //for large shirt
	printf("\n\n");

	//total number of buying shirts
	printf("Patty's shirt size is '%c'", patSize);
	printf("\n");
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &totalShirt);
	printf("\n");

	// calculation of subtotal,totalShirt,&tax
	subTotal = (int) (((smallPrice * totalShirt) + 0.005 ) * 100 );
	taxes = (int) ((subTotal * TAX) + 0.5);
	total = (int)(subTotal + taxes);

	//information of patty shopping cart 
	printf("Patty's shopping cart...\n");
	printf("Contains : %d shirts\n", totalShirt);
	printf("Sub-total: $%8.4lf\n", subTotal / 100.0);
	printf("Taxes    : $%8.4lf\n", taxes / 100.0);
	printf("Total    : $%8.4lf\n", total / 100.0);
	
    return 0;
}
