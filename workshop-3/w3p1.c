/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Tejasvi parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    int    productID1 = 111, productID2 = 222, productID3 = 111;
    double productprice1 = 111.49, productprice2 = 222.99, productprice3 = 334.49, avgtotal;
    char   productTax1 = 'Y', productTax2 = 'N', productTax3 = 'N';

    // Got the direct integer value

    printf("Product Information\n");
    printf("===================\n");

    printf("Product-1 (ID:%d)\n", productID1);
    printf("  Taxed: %c\n", productTax1);
    printf("  Price: $%.4lf\n", productprice1);
    printf("\n");

    printf("Product-2 (ID:%d)\n", productID2);
    printf("  Taxed: %c\n", productTax2);
    printf("  Price: $%.4lf\n", productprice2);
    printf("\n");


    printf("Product-3 (ID:%d)\n", productID3);
    printf("  Taxed: %c\n", productTax3);
    printf("  Price: $%.4lf\n", productprice3);
    printf("\n");

    avgtotal = (productprice1 + productprice2 + productprice3) / 3;
    printf("The average of all prices is: $%.4lf\n", avgtotal);
    printf("\n");

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");

    // Get the value in form of 0 or 1

    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n", productTax1 == 'Y');
    printf("\n");

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", productTax2 == 'N' && productTax3 == 'N');
    printf("\n");

    printf("3. Is product 3 less than testValue ($%.2lf)? -> ", testValue);
    printf("%d\n", productprice3 <= testValue);
    printf("\n");

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", productprice3 > (productprice1 + productprice2));
    printf("\n");

    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? -> % d", productprice1 == (productprice3 <= productprice2));

    printf(" (price difference: $%.2lf)\n", productprice1 + .01);
    printf("\n");

    printf("6. Is the price of product 2 equal to or more than the average price? -> ");
    printf("%d\n", productprice2 >= avgtotal);
    printf("\n");

    printf("7. Based on product ID, product 1 is unique -> ");
    printf("%d\n", productID1 == 'Y');
    printf("\n");

    printf("8. Based on product ID, product 2 is unique -> ");
    printf("%d\n", productID2 != 'Y');
    printf("\n");

    printf("9. Based on product ID, product 3 is unique -> ");
    printf("%d\n", productID3 == 'N');

    return 0;
}
