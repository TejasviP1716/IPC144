/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    //Variable declarations
    double smallPrice, mediumPrice, largePrice;
    int patShirt,tomShirt, salShirt, overallSubtotal, overallTax, overallTotal;
    int patSubTotal, patTax, patTotal, tomSubTotal, tomTax, tomTotal,
        salSubTotal, salTax, salTotal;

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
    scanf("%d", &patShirt);
    printf("\n");

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomShirt);
    printf("\n");

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salShirt);
    printf("\n");

    patSubTotal = (int)(((patShirt * smallPrice) + 0.005) * 100);
    patTax = (int)((patSubTotal * TAX) + 0.5);
    patTotal = (int)(patSubTotal + patTax);

    tomSubTotal = (int)(((tomShirt * largePrice) + 0.005) * 100);
    tomTax = (int)((tomSubTotal * TAX) + 0.5);
    tomTotal = (int)(tomSubTotal + tomTax);

    salSubTotal = (int)(((salShirt * mediumPrice) + 0.005) * 100);
    salTax = (int)((salSubTotal * TAX) + 0.5);
    salTotal = (int)(salSubTotal + salTax);

    overallSubtotal = patSubTotal + tomSubTotal + salSubTotal;
    overallTax = patTax + tomTax + salTax;
    overallTotal = patTotal + tomShirt + salTotal;


    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2f %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallPrice, patShirt, patSubTotal / 100.0, patTax / 100.0, patTotal / 100.0);

    printf("Sally    %-4c %5.2f %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumPrice, salShirt, salSubTotal / 100.0, salTax / 100.0, salTotal / 100.0);

    printf("Tommy    %-4c %5.2f %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largePrice, tomShirt, tomSubTotal / 100.0, tomTax / 100.0, tomTotal / 100.0);


    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", overallSubtotal / 100.0, overallTax / 100.0, overallTotal / 100.0);


    int tooniesQty, looniesQty, quartersQty, dimesQty, nickelsQty, penniesQty;
    double balance, averageShirtCost, averageShirtTotalCost;


    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)overallSubtotal / 100);
    tooniesQty = overallSubtotal / 200;
    balance = overallSubtotal % 200;

    printf("Toonies  %3d %9.4lf\n", tooniesQty, (double)balance / 100);
    looniesQty = balance / 100;
    balance = (int)balance % 100;

    printf("Loonies  %3d %9.4lf\n", looniesQty, balance / 100.0);
    quartersQty = balance / 25;
    balance = (int)balance % 25;

    printf("Quarters %3d %9.4lf\n", quartersQty, balance / 100.0);
    dimesQty = balance / 10;
    balance = (int)balance % 10;

    printf("Dimes    %3d %9.4lf\n", dimesQty, balance / 100.0);
    nickelsQty = balance / 5;
    balance = (int)balance % 5;

    printf("Nickels  %3d %9.4lf\n", nickelsQty, balance / 100.0);
    penniesQty = balance / 1;
    balance = (int)balance % 1;

    printf("Pennies  %3d %9.4lf\n\n", penniesQty, balance / 100.0);
    averageShirtCost = (int)  (overallSubtotal / (patShirt + salShirt + tomShirt)) ;
    printf("Average cost/shirt: $%.4lf\n\n", averageShirtCost / 100.0);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)overallTotal / 100.0);
    tooniesQty = overallTotal / 200;
    balance = overallTotal % 200;

    printf("Toonies  %3d %9.4lf\n", tooniesQty, (double)balance / 100);
    looniesQty = balance / 100;

    balance = (int)balance % 100;
    printf("Loonies  %3d %9.4lf\n", looniesQty, balance / 100.0);
    quartersQty = balance / 25;
    balance = (int)balance % 25;

    printf("Quarters %3d %9.4lf\n", quartersQty,balance / 100.0);
    dimesQty = balance / 10;
    balance = (int)balance % 10;

    printf("Dimes    %3d %9.4lf\n", dimesQty, balance / 100.0);
    nickelsQty = balance / 5;
    balance = (int)balance % 5;

    printf("Nickels  %3d %9.4lf\n", nickelsQty, balance / 100.0);
    penniesQty = balance / 1;
    balance = (int)balance % 1;

    printf("Pennies  %3d %9.4lf\n", penniesQty, balance / 100.0);
    printf("\n");

    averageShirtTotalCost = (int)(overallTotal / (patShirt + patShirt + patShirt));
    printf("Average cost/shirt: $%.4lf\n", averageShirtTotalCost/ 100.0);

    return 0;

}
