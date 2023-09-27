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


// ----------------------------------------------------------------------------
// defines/macros

#define MAX_PRODUCT 3
#define GRAM_NUM 64
#define LBS 2.20462
#define G 1000


// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    int calories;
    double price;
    double weight;
};

struct ReportData
{
    int sku;
    double price;
    int cals;
    double lbsWeight;
    double kgWeight;
    int gWeight;
    double totalServings;
    double costPerServing;
    double calsPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* num);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* num);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int productNum);


// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* lbs, double* lbsToKg);

// 9. convert lbs: g

int convertLbsG(const double* lbs, int* lbsToG);

// 10. convert lbs: kg / g

void convertLbs(const double* lbs, double* lbsToKg, int* lbsToG);

// 11. calculate: servings based on gPerServ

double calculateServings(const int gramServings, const int totalGrams, double* numOfServings);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* productPrice, const double* numOfServings, double* costPerServing);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* productPrice, const double* totalCals, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(struct CatFoodInfo food);


// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData report, const int cheapestProduct);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo food);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();

