/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries

#include <stdio.h>

// User-Defined Libraries

#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* num)
{
	int val;

	do {
		scanf("%d", &val);

		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
	{
		*num = val;
	}

	return val;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* num)
{
	double val;

	do {
		scanf("%lf", &val);

		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
	{
		*num = val;
	}
	return val;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int productNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", productNum);
	printf("NOTE: A 'serving' is %dg\n", GRAM_NUM);
	return;
}


// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
	struct CatFoodInfo food = { 0 };

	printf("\nCat Food Product #%d\n", sequenceNum + 1);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&food.sku);

	printf("PRICE         : $");
	getDoublePositive(&food.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);


	return food;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\n\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	return;
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* lbs, double* lbsToKg)
{
	double val = (*lbs) / LBS;

	if (lbsToKg != NULL)
	{
		*lbsToKg = val;
	}

	return val;
}


// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* lbs, int* lbsToG)
{
	int val = ((*lbs) / LBS) * G;

	if (lbsToG != NULL)
	{
		*lbsToG = val;
	}

	return val;
}

// 10. convert lbs: kg and g

void convertLbs(const double* lbs, double* lbsToKg, int* lbsToG)
{
	convertLbsKg(lbs, lbsToKg);
	convertLbsG(lbs, lbsToG);
}

// 11. calculate: servings based on gPerServ

double calculateServings(const int gramServings, const int totalGrams, double* numOfServings)
{
	double servings = ((double)totalGrams) / gramServings;

	if (numOfServings != NULL)
	{
		*numOfServings = servings;
	}

	return servings;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* productPrice, const double* numOfServings, double* costPerServing)
{
	double servingCost = (*productPrice) / (*numOfServings);

	if (costPerServing != NULL)
	{
		*costPerServing = servingCost;
	}

	return servingCost;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* productPrice, const double* totalCals, double* costPerCal)
{
	double calCost = (*productPrice) / (*totalCals);

	if (costPerCal != NULL)
	{
		*costPerCal = calCost;
	}

	return calCost;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(struct CatFoodInfo food)
{
	struct ReportData report;

	report.sku = food.sku;
	report.price = food.price;
	report.lbsWeight = food.weight;
	report.cals = food.calories;

	report.kgWeight = convertLbsKg(&report.lbsWeight, &report.kgWeight);
	report.gWeight = convertLbsG(&report.lbsWeight, &report.gWeight);
	report.totalServings = calculateServings(GRAM_NUM, report.gWeight, &report.totalServings);

	double totalCalories = report.cals * report.totalServings;

	report.costPerServing = calculateCostPerServing(&report.price, &report.totalServings, &report.costPerServing);
	report.calsPerServing = calculateCostPerCal(&report.price, &totalCalories, &report.calsPerServing);

	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAM_NUM);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData report, const int cheapestProduct)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.sku, report.price, report.lbsWeight, report.kgWeight, report.gWeight, report.cals, report.totalServings, report.costPerServing, report.calsPerServing);
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo food)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n\n", food.sku, food.price);

	printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point

void start(void)
{
	struct ReportData report[MAX_PRODUCT] = { {0} };
	struct CatFoodInfo food[MAX_PRODUCT] = { {0} };

	int i, cheapestI = 0;

	openingMessage(MAX_PRODUCT);

	for (i = 0; i < MAX_PRODUCT; i++) {
		food[i] = getCatFoodInfo(i);
		report[i] = calculateReportData(food[i]);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT; i++) {
		displayCatFoodData(food[i].sku, &food[i].price, food[i].calories, &food[i].weight);
	}

	double cheapestProductPrice = report[0].costPerServing;
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		if (report[i].costPerServing <= cheapestProductPrice)
		{
			cheapestProductPrice = report[i].costPerServing;
			cheapestI = i;
		}
	}

	printf("\n");
	displayReportHeader();

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayReportData(report[i], cheapestI);

		if (cheapestI == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < MAX_PRODUCT; i++)
	{
		if (i == cheapestI)
		{
			displayFinalAnalysis(food[i]);
		}
	}
}