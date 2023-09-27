/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Denyl Marc Bensan
Student ID#: 171309222
Email      : mbensan@myseneca.ca
Section    : IPC144NCC

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

    double s;
    double m;
    double l;
    int amountOfPurchase;
    double subTotal;
    double totalTax;
    double roundedTotalTax;
    double total;

    printf("Set Shirt Prices\n================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &s);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &m);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &l);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2lf\nMEDIUM : $%.2lf\nLARGE  : $%.2lf", s, m, l);

    printf("\n\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &amountOfPurchase);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", amountOfPurchase);

    subTotal = s * amountOfPurchase;

    printf("Sub-total: $%.4lf\n", subTotal);

    totalTax = subTotal * TAX;

    printf("Taxes    : $ %.2lf00\n", totalTax);

    total = subTotal + totalTax;

    printf("Total    : $%.2lf00\n", total);

    return 0;
}