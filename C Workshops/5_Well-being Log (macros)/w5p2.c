/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MINYEAR 2012
#define MAXYEAR 2022
#define LOGDAYS 3

#include <stdio.h>

int main(void)
{
    const char* monthNames[] = { "Invalid", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
    const int JAN = 1, DEC =12;
    int year, month;
    int keepLooping = 1, i = 0;
    double morningResult, eveningResult;
    double sumMorning = 0.0, sumEvening = 0.0, sumTotal;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MINYEAR || year > MAXYEAR)
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");

        if (month < JAN || month > DEC)
            printf("   ERROR: Jan.(1) - Dec.(12)\n");

        if (year < MINYEAR || year > MAXYEAR || month < JAN || month > DEC) 
            continue;

        keepLooping = 0;
        printf("\n");
 
    } while (keepLooping == 1);
    
    const char* nameMonth = monthNames[month];

    printf("*** Log date set! ***\n\n");

    for (i = 0; i < LOGDAYS; i++) {
        printf("%d-%s-0%d\n", year, nameMonth, i + 1);

        printf("   Morning rating (0.0-5.0): ");
        scanf("%lf", &morningResult);

        while (morningResult < 0.0 || morningResult > 5.0) {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningResult);
        } 

        printf("   Evening rating (0.0-5.0): ");
        scanf("%lf", &eveningResult);

        while (eveningResult < 0.0 || eveningResult > 5.0) {
            printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningResult);
        } 

        printf("\n");
        sumMorning += morningResult;
        sumEvening += eveningResult;

    }
    sumTotal = sumMorning + sumEvening;

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %6.3lf\n", sumMorning);
    printf("Evening total rating: %6.3lf\n", sumEvening);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", sumTotal);
    printf("Average morning rating: %4.1lf\n", sumMorning / LOGDAYS);
    printf("Average evening rating: %4.1lf\n", sumEvening / LOGDAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", sumTotal / (LOGDAYS + LOGDAYS));
 
    return 0;
}