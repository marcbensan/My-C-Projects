/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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
#define MAXIMUM_PATH 70
#define MINIMUM_PATH 10
#define MAX_NUM_LIVES 10
#define MIN_NUM_LIVES 1

struct PlayerInfo
{
    int numLives;
    char charSymbol;
    int numTreasure;
    int positions[MAXIMUM_PATH];

};

struct GameInfo
{
    int maxNumMove;
    int pathLength;
    int bombs[MAXIMUM_PATH];
    int treasure[MAXIMUM_PATH];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;

    int i;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    //getting symbol
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.charSymbol);

    //getting num of lives
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.numLives);

        if (player.numLives < MIN_NUM_LIVES || player.numLives > MAX_NUM_LIVES) {
            printf("     Must be between %d and %d!\n", MIN_NUM_LIVES, MAX_NUM_LIVES);
        }

    } while (player.numLives < MIN_NUM_LIVES || player.numLives > MAX_NUM_LIVES);

    player.numTreasure = 0;

    for (i = 0; i < MAXIMUM_PATH; i++)
    {
        player.positions[i] = 0;
    }
    

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    //getting path length
    do {
        printf("Set the path length (a multiple of 5 between %d-%d): ", MINIMUM_PATH, MAXIMUM_PATH);
        scanf("%d", &game.pathLength);
        if (game.pathLength < MINIMUM_PATH || game.pathLength > MAXIMUM_PATH || game.pathLength % 5 != 0) {
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", MINIMUM_PATH, MAXIMUM_PATH);
        }
    } while (game.pathLength < MINIMUM_PATH || game.pathLength > MAXIMUM_PATH || game.pathLength % 5 != 0);

    //getting move numbers
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxNumMove);
        if (game.maxNumMove < player.numLives || game.maxNumMove > (int)(.75 * game.pathLength)) {
            printf("    Value must be between %d and %d\n", player.numLives, (int)(.75 * game.pathLength));
        }

    } while (game.maxNumMove < player.numLives || game.maxNumMove > (int)(.75 * game.pathLength));

    printf("\n");
    //doing the bombs
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB.Space - delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < game.pathLength; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        int j;
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.bombs[j]);
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the bomb positions in sets of 5 where a value of\n");
    printf("1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        int j;
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.treasure[j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.charSymbol);
    printf("   Lives      : %d\n", player.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}
