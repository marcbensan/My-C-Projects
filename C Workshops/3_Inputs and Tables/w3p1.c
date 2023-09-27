/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Denyl Marc Bensan
Student ID#: 171309222
Email      : mbensan@myseneca.ca
Section    : IPC144NCC

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
    const int PRODUCT1ID = 111, PRODUCT2ID = 222, PRODUCT3ID = 111;
    const double PRODUCT1PRICE = 111.49, PRODUCT2PRICE = 222.99, PRODUCT3PRICE = 334.49;
    const char PRODUCT1TAX = 'Y', PRODUCT2TAX = 'N', PRODUCT3TAX = 'N';

    double avgPrice = (PRODUCT1PRICE + PRODUCT2PRICE + PRODUCT3PRICE) / 3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", PRODUCT1ID);
    printf("  Taxed: %c\n", PRODUCT1TAX);
    printf("  Price: $%.4lf\n\n", PRODUCT1PRICE);

    printf("Product-1 (ID:%d)\n", PRODUCT2ID);
    printf("  Taxed: %c\n", PRODUCT2TAX);
    printf("  Price: $%.4lf\n\n", PRODUCT2PRICE);

    printf("Product-1 (ID:%d)\n", PRODUCT3ID);
    printf("  Taxed: %c\n", PRODUCT3TAX);
    printf("  Price: $%.4lf\n\n", PRODUCT3PRICE);

    printf("The average of all prices is : $%.4lf\n\n", avgPrice);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("Is product 2 taxable? -> %d\n\n", PRODUCT1TAX == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable(N) ? -> %d\n\n", PRODUCT2TAX && PRODUCT3TAX == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf) ? -> %d\n\n", testValue, PRODUCT3PRICE < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined ? -> %d\n\n", PRODUCT3PRICE > PRODUCT1PRICE + PRODUCT2PRICE);
    printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2 ? ->  %d (price difference : $%.2lf\n\n", PRODUCT1PRICE >= PRODUCT3PRICE - PRODUCT2PRICE, PRODUCT3PRICE - PRODUCT2PRICE);
    printf("6. Is the price of product 2 equal to or more than the average price ? -> %d\n\n", PRODUCT2PRICE >= avgPrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", PRODUCT1ID == PRODUCT2ID && PRODUCT3ID);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", PRODUCT2ID != PRODUCT1ID || PRODUCT3ID);
    printf("9. Based on product ID, product 3 is unique -> %d\n", PRODUCT3ID != PRODUCT1ID && PRODUCT2ID);


    return 0;
}