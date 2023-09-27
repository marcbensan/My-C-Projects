/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define MIN_NUM_ITEMS 1
#define MAX_NUM_ITEMS 10
#define YEAR 12

#include <stdio.h>


int main(void)
{
    //declare CONST
    const double MIN_INCOME = 500.00, MAX_INCOME = 400000.00, MIN_COST = 100.00;
    const int MIN_PRIORITY = 1, MAX_PRIORITY = 3;
    const char YES = 'y', NO = 'n';

    //declare variables
    int wishListItems, years, months, priorityFilter, forecastWL, i, valid = 1, hasFinancing = 0;
    double monthlyIncome, totalCost = 0.0, priorityAmount = 0.0;
    
    //declare arrays
    double itemCost[MAX_NUM_ITEMS];
    int priority[MAX_NUM_ITEMS];
    char financing[MAX_NUM_ITEMS];
    //int hasFinance[MAX_NUM_ITEMS];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    //get monthly income

    do {
        valid = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyIncome);

        if (monthlyIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            valid = 0;
        }
        if (monthlyIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            valid = 0;
        }
        printf("\n");
    } while (!valid);

    //get wishlist

    do {
        valid = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wishListItems);

        if (wishListItems < MIN_NUM_ITEMS || wishListItems > MAX_NUM_ITEMS)
        {
            valid = 0;
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        printf("\n");
    } while (!valid);


    //Item detail loop
    for (i = 0; i < wishListItems; i++)
    {
        printf("Item-%d Details:\n", i + 1);

        //get item cost
        do
        {
            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);

            if (itemCost[i] < MIN_COST)
            {
                valid = 0;
                printf("       ERROR: Cost must be at least $100.00\n");
            }
        } while (!valid);

        //get priority
        do
        {
            valid = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY)
            {
                valid = 0;
                printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
            }
        } while (!valid);

        //get finance

        do
        {
            valid = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);

            if (financing[i] != YES && financing[i] != NO)
            {
                valid = 0;
                printf("      ERROR: Must be a lowercase \'%c\' or \'%c\'\n", YES, NO);
            }
        } while (!valid);
        printf("\n");
    }
    
    //Printing tthe table
    
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < wishListItems; i++)
    {
        printf("  %d      %d        %c    %11.2lf\n", i+1, priority[i], financing[i], itemCost[i]);
        totalCost += itemCost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n\n", totalCost);
    
    //forecast wishlist
    do
    {
        priorityAmount = 0.0;

        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &forecastWL);

        if (forecastWL == 1)
        {
            //printing all filters
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");

            //year and month calculations
            years = totalCost / (monthlyIncome * YEAR);
            months = ((int)totalCost % ((int)monthlyIncome * YEAR) / monthlyIncome);
            //check whether the month is valid to be a year/vice versa
            if ((int)totalCost % ((int)monthlyIncome * YEAR) % (int)monthlyIncome > 0) {
                months++;
            }
            if (months == YEAR) 
            {
                years++;
                months = 0;
            }

            printf("Amount:   $%.2lf\n", totalCost);
            printf("Forecast: %d years, %d months\n", years, months);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }

        else if (forecastWL == 2)
        {
            //filter by priority
            printf("\n");
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);

            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityFilter);

            for (i = 0; i < wishListItems; i++)
            {
                if (priority[i] == priorityFilter)
                {
                    priorityAmount += itemCost[i];

                    if (financing[i] == 'y')
                    {
                        hasFinancing = 1;
                    }
                }
            }
            years = priorityAmount / (monthlyIncome * YEAR);
            months = ((int)priorityAmount % ((int)monthlyIncome * YEAR) / monthlyIncome);
            //same checker
            if ((int)priorityAmount % ((int)monthlyIncome * YEAR) % (int)monthlyIncome > 0) {
                months++;
            }
            if (months == YEAR)
            {
                years++;
                months = 0;
            }
            printf("Amount:   $%.2lf\n", priorityAmount);
            printf("Forecast: %d years, %d months\n", years, months);

            if (hasFinancing == 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }
        else if (forecastWL != 0)
        {
            printf("\nERROR: Invalid menu selection.\n\n");
        }
        hasFinancing = 0;
    } while (forecastWL != 0);

    printf("\n");
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}