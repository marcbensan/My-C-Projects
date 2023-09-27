/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
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

#define MAX_NUMBER_OF_ITEMS 10
#define MIN_NUMBER_OF_ITEMS 1

int main(void)
{
	//const declarations
	const double MAX_INCOME = 400000.00;
	const double MIN_INCOME = 500.00;
	const double MIN_COST = 100.00;
	const int MIN_PRIORITY = 1, MAX_PRIORITY = 3;
	const char YES = 'y', NO = 'n';



	//variable declarations
	double income;
	double totalCost = 0;
	int numOfItems, i, valid;

	//arrays
	double cost[MAX_NUMBER_OF_ITEMS];
	int priority[MAX_NUMBER_OF_ITEMS];
	char finance[MAX_NUMBER_OF_ITEMS];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	//get the income
	do
	{
		valid = 1;
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);
		

		//condition statements
		if (income < MIN_INCOME) {
			valid = 0;
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
		}
		if (income > MAX_INCOME) {
			valid = 0;
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);
		}
	} while (!valid);
	printf("\n");
	//get number of items
	do
	{
		valid = 1;
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &numOfItems);

		if (numOfItems < MIN_NUMBER_OF_ITEMS || numOfItems > MAX_NUMBER_OF_ITEMS) {
			valid = 0;
			printf("ERROR: List is restricted to between %d and %d items.\n\n", MIN_NUMBER_OF_ITEMS, MAX_NUMBER_OF_ITEMS);
		}

	} while (!valid);
	

	for (i = 0; i < numOfItems; i++) 
	{
		printf("\n");
		printf("Item-%d Details:\n", i + 1);

		//get the cost
		do
		{
			valid = 1;
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			if (cost[i] < MIN_COST)
			{
				valid = 0;
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
			}
		} while (!valid);

		//get the priority
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

		//get the finance
		do
		{
			valid = 1;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);

			if (finance[i] != YES && finance[i] != NO)
			{
				valid = 0;
				printf("      ERROR: Must be a lowercase \'%c\' or \'%c\'\n", YES, NO);
			}
		} while (!valid);

	}

	//table
	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < numOfItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
		totalCost += cost[i];
	}

	//printing tbe total cost
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}

/*
	HELPER: printf formatting statements....
	=========================================

	Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");

		printf("%3d  %5d    %5c    %11.2lf\n", ...


	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/