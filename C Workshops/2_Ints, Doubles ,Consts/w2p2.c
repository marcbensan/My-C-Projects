/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    //declaring variables

    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double s;
    double m;
    double l;
    int pattyAmountOfPurchase;
    int tomAmountOfPurchase;
    int salAmountofPurchase;
    int pattySubTotal, pattyTotalTax, pattyTotal;
    int tomSubTotal, tomTotalTax, tomTotal;
    int salSubTotal, salTotalTax, salTotal;
    int sumSubTotal, sumTotalTax, sumTotal;
    int sumQty;
    int tQ, lQ, qQ, dQ, nQ, pQ;
    double avgCost;
    double tB, lB, qB, dB, nB, pB;

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
    scanf("%d", &pattyAmountOfPurchase);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomAmountOfPurchase);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salAmountofPurchase);

    //calculations to get the appropriate values

    pattySubTotal = s * pattyAmountOfPurchase * 100 + 0.5;
    pattyTotalTax = pattySubTotal * TAX + 0.5;
    pattyTotal = pattySubTotal + pattyTotalTax;

    salSubTotal = m * salAmountofPurchase * 100 + 0.5;
    salTotalTax = salSubTotal * TAX + 0.5;
    salTotal = salSubTotal + salTotalTax;

    tomSubTotal = l * tomAmountOfPurchase * 100 + 0.5;
    tomTotalTax = tomSubTotal * TAX + 0.5;
    tomTotal = tomSubTotal + tomTotalTax;


    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, s, pattyAmountOfPurchase, (double)pattySubTotal/100, (double)pattyTotalTax/100, (double)pattyTotal/100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, m, salAmountofPurchase, (double)salSubTotal/100, (double)salTotalTax/100, (double)salTotal/100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, l, tomAmountOfPurchase, (double)tomSubTotal/100 , (double)tomTotalTax/100, (double)tomTotal/100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    //summing up the important variables

    sumSubTotal = pattySubTotal + salSubTotal + tomSubTotal;
    sumTotalTax = pattyTotalTax + salTotalTax + tomTotalTax;
    sumTotal = pattyTotal + salTotal + tomTotal;
    sumQty = pattyAmountOfPurchase + salAmountofPurchase + tomAmountOfPurchase;
    avgCost = ((double)sumSubTotal / 100)/ sumQty;

    printf("                        %9.4lf %9.4lf %9.4lf\n\n", (double)sumSubTotal/100, (double)sumTotalTax/100, (double)sumTotal/100);
    printf("Daily retail sales represented by coins\n=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n-------- --- ---------\n             %9.4lf\n", (double)sumSubTotal/100);

    //calcukating for the amount of coins and modulus.
    printf("sumsubtotal = %d\n", sumSubTotal);

    tQ = sumSubTotal / 200;
    tB = sumSubTotal % 200;
    sumSubTotal %= 200;

    lQ = sumSubTotal / 100;
    lB = sumSubTotal % 100;
    sumSubTotal %= 100;

    qQ = sumSubTotal / 25;
    qB = sumSubTotal % 25;
    sumSubTotal %= 25;

    dQ = sumSubTotal / 10;
    dB = sumSubTotal % 10; 
    sumSubTotal %= 10;

    nQ = sumSubTotal / 5;
    nB = sumSubTotal % 5;
    sumSubTotal %= 5;

    pQ = sumSubTotal / 1;
    pB = sumSubTotal % 1;
    sumSubTotal %= 1;

    printf("Toonies  %d %9.4lf\n", tQ, tB / 100 );
    printf("Loonies    %d %9.4lf\n", lQ, lB / 100);
    printf("Quarters   %d %9.4lf\n", qQ, qB / 100);
    printf("Dimes      %d %9.4lf\n", dQ, dB / 100);
    printf("Nickels    %d %9.4lf\n", nQ, nB / 100);
    printf("Pennies    %d %9.4lf\n\n", pQ, pB / 100);

    printf("Average cost/shirt: $%7.4lf\n\n", avgCost);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n-------- --- ---------\n             %9.4lf\n", (double)sumTotal / 100);

    //reusing to get new avgCost value and coins including taxes.

    avgCost = ((double)sumTotal / 100) / sumQty;
    tQ = sumTotal / 200;
    tB = sumTotal % 200;
    sumTotal %= 200;

    lQ = sumTotal / 100;
    lB = sumTotal % 100;
    sumTotal %= 100;

    qQ = sumTotal / 25;
    qB = sumTotal % 25;
    sumTotal %= 25;

    dQ = sumTotal / 10;
    dB = sumTotal % 10;
    sumTotal %= 10;

    nQ = sumTotal / 5;
    nB = sumTotal % 5;
    sumTotal %= 5;

    pQ = sumTotal / 1;
    pB = sumTotal % 1;
    sumTotal %= 1;

    printf("Toonies  %d %9.4lf\n", tQ, tB / 100);
    printf("Loonies    %d %9.4lf\n", lQ, lB / 100);
    printf("Quarters   %d %9.4lf\n", qQ, qB / 100);
    printf("Dimes      %d %9.4lf\n", dQ, dB / 100);
    printf("Nickels    %d %9.4lf\n", nQ, nB / 100);
    printf("Pennies    %d %9.4lf\n\n", pQ, pB / 100);
    printf("Average cost/shirt: $%7.4lf\n", avgCost);

    return 0;
}
