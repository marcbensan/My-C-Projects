/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Denyl Marc Bensan
Student ID#: 171309222
Email      : mbensan@myseneca.ca
Section    : IPC144NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int applesPick, orangesPick, pearsPick, tomatoesPick, cabbagesPick;
    int i;
    int shopAgain = 0;

    printf("Grocery Shopping\n");
    printf("================\n");

    do {
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);

        if (apples < 0)
            printf("ERROR: Value must be 0 or more.\n");

    } while (apples < 0);
    printf("\n");

    do {
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);

        if (oranges < 0)
            printf("ERROR: Value must be 0 or more.\n");

    } while (oranges < 0);
    printf("\n");

    do {
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);

        if (pears < 0)
            printf("ERROR: Value must be 0 or more.\n");

    } while (pears < 0);
    printf("\n");

    do {
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);

        if (tomatoes < 0)
            printf("ERROR: Value must be 0 or more.\n");

    } while (tomatoes < 0);
    printf("\n");

    do {
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages);

        if (cabbages < 0)
            printf("ERROR: Value must be 0 or more.\n");

    } while (cabbages < 0);
    printf("\n");

    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    do {
        applesPick = 0;
        printf("Pick some APPLES... how many did you pick? : ");
        scanf("%d", &applesPick);
        
        if (applesPick <= 0)
            printf("ERROR: You must pick at least 1!\n");
        else if (applesPick > apples)
            printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
        else {
            apples -= applesPick;

            if (apples == 0)
                printf("Great, that's the apples done!\n\n");
            else
                printf("Looks like we still need some APPLES...\n");
        }

    } while (apples > 0);

    do {
        pearsPick = 0;
        printf("Pick some PEARS... how many did you pick? : ");
        scanf("%d", &pearsPick);

        if (pearsPick <= 0)
            printf("ERROR: You must pick at least 1!\n");
        else if (pearsPick > pears)
            printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
        else {
            pears -= pearsPick;

            if (pears == 0)
                printf("Great, that's the pears done!\n\n");
            else
                printf("Looks like we still need some PEARS...\n");
        }

    } while (pears > 0);

    do {
        cabbagesPick = 0;
        printf("Pick some CABBAGES... how many did you pick? : ");
        scanf("%d", &cabbagesPick);

        if (cabbagesPick <= 0)
            printf("ERROR: You must pick at least 1!\n");
        else if (cabbagesPick > cabbages)
            printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
        else {
            cabbages -= cabbagesPick;

            if (cabbages == 0)
                printf("Great, that's the cabbages done!\n\n");
            else
                printf("Looks like we still need some CABBAGES...\n");
        }

    } while (cabbages > 0);

    printf("All the items are picked!\n\n");
    printf("Do another shopping? (0=NO): ");
    scanf("%d", &shopAgain);
    
    while (shopAgain == 1) {
        printf("\nGrocery Shopping\n");
        printf("================\n");
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        printf("\nHow many ORANGES do you need? : ");
        scanf("%d", &oranges);
        printf("\nHow many PEARS do you need? : ");
        scanf("%d", &pears);
        printf("\nHow many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        printf("\nHow many CABBAGES do you need? : ");
        scanf("%d", &cabbages);

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        do {
            orangesPick = 0;
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangesPick);

            if (orangesPick <= 0)
                printf("ERROR: You must pick at least 1!\n");
            else if (orangesPick > oranges)
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            else {
                oranges -= orangesPick;

                if (oranges == 0)
                    printf("Great, that's the oranges done!\n\n");
                else
                    printf("Looks like we still need some ORANGES...\n");
            }
        } while (oranges > 0);

        do {
            tomatoesPick = 0;
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoesPick);

            if (tomatoesPick <= 0)
                printf("ERROR: You must pick at least 1!\n");
            else if (tomatoesPick > tomatoes)
                printf("You picked too many... only %d more TOMATOE(S) are needed.\n", tomatoes);
            else {
                tomatoes -= tomatoesPick;

                if (tomatoes == 0)
                    printf("Great, that's the tomatoes done!\n\n");
                else
                    printf("Looks like we still need some TOMATOES...\n");
            }
        } while (tomatoes > 0);

        printf("All items are picked!\n\n");

        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shopAgain);
        printf("\n");
    }


        printf("Your tasks are done for today - enjoy your free time!");
    

    return 0;
}