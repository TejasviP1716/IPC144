/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Tejasvi parmar
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

    const double GRAMS_IN_LBS = 453.5924;

    // Variable Declaration

    int wgtCoffee1, wgtCoffee2, wgtcoffee3;

    //tcoffee = type of coffee

    char tcoffee1, tcoffee2, tcoffee3, coffeeCream1, coffeeCream2, coffeeCream3, custcream, custcoffee;
    int everydayservings;


    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");

    printf("\nEnter the coffee product information being sold today...\n");

    // Coffee - 1 details.....

    printf("\nCOFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &tcoffee1);
    printf("Bag weight (g): ");
    scanf("%d", &wgtCoffee1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream1);

    // Coffee - 2 details.....

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &tcoffee2);
    printf("Bag weight (g): ");
    scanf("%d", &wgtCoffee2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream2);

    // Coffee - 3 details......

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &tcoffee3);
    printf("Bag weight (g): ");
    scanf("%d", &wgtcoffee3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffeeCream3);




    /*

     Provided formatting parts for printf statements:

     As described in step-7
     ======================
     printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

     As described in step-10
     =======================
     printf(" 1|       %d         |      %d      |   %d   |\n",

   */


   // Tabular formation .....01

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

        (tcoffee1 == 'l' || tcoffee1 == 'L'),
        (tcoffee1 == 'm' || tcoffee1 == 'M'),
        (tcoffee1 == 'r' || tcoffee1 == 'R'),
        wgtCoffee1,
        wgtCoffee1 / GRAMS_IN_LBS,
        (coffeeCream1 == 'y' || coffeeCream1 == 'Y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

        (tcoffee2 == 'l' || tcoffee2 == 'L'),
        (tcoffee2 == 'm' || tcoffee2 == 'M'),
        (tcoffee2 == 'r' || tcoffee2 == 'R'),
        wgtCoffee2,
        wgtCoffee2 / GRAMS_IN_LBS,
        (coffeeCream2 == 'y' || coffeeCream2 == 'Y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

        (tcoffee3 == 'l' || tcoffee3 == 'L'),
        (tcoffee3 == 'm' || tcoffee3 == 'M'),
        (tcoffee3 == 'r' || tcoffee3 == 'R'),
        wgtcoffee3,
        wgtcoffee3 / GRAMS_IN_LBS,
        (coffeeCream3 == 'y' || coffeeCream2 == 'Y'));


    printf("\nEnter how you like your coffee...\n");

    // Taste of coffee.....

    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &custcoffee);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &custcream);
    printf("Typical number of daily servings: ");
    scanf("%d", &everydayservings);

    printf("\nThe below table shows how your preferences align to the available products:\n");

    // Tabular formation.....02 

    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",

        ((custcoffee == 'l' || custcoffee == 'L') && (tcoffee1 == 'l' || tcoffee1 == 'L')) || ((custcoffee == 'm' || custcoffee == 'M') && (tcoffee2 == 'm' || tcoffee2 == 'M')) || ((custcoffee == 'r' || custcoffee == 'R') && (tcoffee2 == 'r' || tcoffee2 == 'R')),

        (everydayservings > 1 && everydayservings < 5),

        ((custcream == 'y' || custcream == 'Y') && (coffeeCream1 == 'y' || coffeeCream1 == 'Y')) || ((custcream == 'n' || custcream == 'N') && (coffeeCream1 == 'n' || coffeeCream1 == 'N')));



    printf(" 2|       %d         |      %d      |   %d   |\n",

        ((custcoffee == 'l' || custcoffee == 'L') && (tcoffee2 == 'l' || tcoffee2 == 'L')) || ((custcoffee == 'm' || custcoffee == 'M') && (tcoffee2 == 'm' || tcoffee2 == 'M')) || ((custcoffee == 'r' || custcoffee == 'R') && (tcoffee2 == 'r' || tcoffee2 == 'R')),

        (everydayservings >= 5 && everydayservings < 10),

        ((custcream == 'y' || custcream == 'Y') && (coffeeCream2 == 'y' || coffeeCream2 == 'Y')) || ((custcream == 'n' || custcream == 'N') && (coffeeCream2 == 'n' || coffeeCream2 == 'N')));

    printf(" 3|       %d         |      %d      |   %d   |\n",

        ((custcoffee == 'l' || custcoffee == 'L') && (tcoffee3 == 'l' || tcoffee3 == 'L')) || ((custcoffee == 'm' || custcoffee == 'M') && (tcoffee3 == 'm' || tcoffee3 == 'M')) || ((custcoffee == 'r' || custcoffee == 'R') && (tcoffee3 == 'r' || tcoffee3 == 'R')),

        (everydayservings >= 10),

        ((custcream == 'y' || custcream == 'Y') && (coffeeCream3 == 'y' || coffeeCream3 == 'Y')) || ((custcream == 'n' || custcream == 'N') && (coffeeCream3 == 'n' || coffeeCream3 == 'N')));


    printf("\nEnter how you like your coffee...\n");

    // Taste of coffee.....

    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &custcoffee);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &custcream);
    printf("Typical number of daily servings: ");
    scanf("%d", &everydayservings);

    printf("\nThe below table shows how your preferences align to the available products:\n");

    // Tabular formation......03

    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",

        ((custcoffee == 'l' || custcoffee == 'L') && (tcoffee1 == 'l' || tcoffee1 == 'L')) || ((custcoffee == 'r' || custcoffee == 'R') && (tcoffee1 == 'r' || tcoffee1 == 'R')) || ((custcoffee == 'm' || custcoffee == 'M') && (tcoffee1 == 'm' || tcoffee1 == 'M')),

        (everydayservings > 1 && everydayservings < 5),

        ((custcream == 'y' || custcream == 'Y') && (coffeeCream1 == 'y' || coffeeCream1 == 'Y')) || ((custcream == 'n' || custcream == 'N') && (coffeeCream1 == 'n' || coffeeCream1 == 'N')));


    printf(" 2|       %d         |      %d      |   %d   |\n",

        ((custcoffee == 'l' || custcoffee == 'L') && (tcoffee2 == 'l' || tcoffee2 == 'L')) || ((custcoffee == 'r' || custcoffee == 'R') && (tcoffee2 == 'r' || tcoffee2 == 'R')) || ((custcoffee == 'm' || custcoffee == 'M') && (tcoffee2 == 'm' || tcoffee2 == 'M')),

        (everydayservings >= 5 && everydayservings < 10),

        ((custcream == 'y' || custcream == 'Y') && (coffeeCream2 == 'y' || coffeeCream2 == 'Y')) || ((custcream == 'n' || custcream == 'N') && (coffeeCream2 == 'n' || coffeeCream2 == 'N')));

    printf(" 3|       %d         |      %d      |   %d   |\n",

        ((custcoffee == 'l' || custcoffee == 'L') && (tcoffee3 == 'l' || tcoffee3 == 'L')) || ((custcoffee == 'r' || custcoffee == 'R') && (tcoffee3 == 'r' || tcoffee3 == 'R')) || ((custcoffee == 'm' || custcoffee == 'M') && (tcoffee3 == 'm' || tcoffee3 == 'M')),

        (everydayservings >= 10),

        ((custcream == 'y' || custcream == 'Y') && (coffeeCream3 == 'y' || coffeeCream3 == 'Y')) || ((custcream == 'n' || custcream == 'N') && (coffeeCream3 == 'n' || coffeeCream3 == 'N')));


    printf("\nHope you found a product that suits your likes!\n");



    // End of Program.....


    return 0;
}
