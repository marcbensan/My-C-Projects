/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_PATH_LENGTH 10
#define MULTIPLE 5

#include <stdio.h>

//declaring structs
struct playerInfo {
    int numLives;
    char charSymbol;
    int numTreasure;
    int positions[MAXIMUM_PATH_LENGTH];
};

struct gameInfo {
    int maxNumMove;
    int pathLength;
    int bombs[MAXIMUM_PATH_LENGTH];
    int treasures[MAXIMUM_PATH_LENGTH];
};

// main function
int main(void)
{
    // declaring variables
    int movesLeft, livesLeft, movePosition = MAXIMUM_PATH_LENGTH + 1, i, j;
    char currentPosition[MAXIMUM_PATH_LENGTH];
    char positionItem[MAXIMUM_PATH_LENGTH];

    // declaring structs as variables
    struct playerInfo player;
    struct gameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
  
    // player config
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.charSymbol);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.numLives);

        if (player.numLives < MINIMUM_LIVES || player.numLives > MAXIMUM_LIVES)
        {
            printf("     Must be between %d and %d!\n", MINIMUM_LIVES, MAXIMUM_LIVES);
        }
    } while (player.numLives < MINIMUM_LIVES || player.numLives > MAXIMUM_LIVES);

    printf("Player configuration set-up is complete\n\n");

    // game config
    printf("GAME Configuration\n");
    printf("------------------\n");

    // Path Length
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
        scanf("%d", &game.pathLength);

        if ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH) || (game.pathLength % MULTIPLE != 0))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
        }
    } while ((game.pathLength < MINIMUM_PATH_LENGTH || game.pathLength > MAXIMUM_PATH_LENGTH) || (game.pathLength % MULTIPLE != 0));

    // num of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxNumMove);

        if (game.maxNumMove < player.numLives || game.maxNumMove >(int) (0.75 * game.pathLength))
        {
            printf("    Value must be between %d and %d\n", player.numLives, (int)(0.75 * game.pathLength));
        }
    } while (game.maxNumMove < player.numLives || game.maxNumMove >(int) (0.75 * game.pathLength));


    // bomb placements
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.bombs[j]);
        }
    }

    printf("BOMB placement set\n\n");

    // trasure placements
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    // Prompting for treasure placement
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        
        for (j = i; j < i + 5; j++)
        {
            scanf("%d", &game.treasures[j]);
        }
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    // display treasure hunt config
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    // player details
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.charSymbol);
    printf("   Lives      : %d\n", player.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    // game details
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);

    // bombs
    printf("   Bombs      : ");

    // displaying bombs
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");

    // treasures
    printf("   Treasure   : ");

    // displaying treasures
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    // assigning values to variables
    movesLeft = game.maxNumMove;
    livesLeft = player.numLives;
    player.numTreasure = 0;
    int symCount = 0;

    //first line
    for (i = 0; i < game.pathLength; i++)
    {
        player.positions[i] = 0;
    }

    for (i = 0; i < game.pathLength; i++)
    {
        positionItem[i] = '-';
    }

    for (i = 0; i < game.pathLength; i++)
    {
        currentPosition[i] = ' ';
    }

    // table

    //position tracker
    do {
        for (i = 0; i < game.pathLength; i++)
        {
            if (currentPosition[i] == player.charSymbol)
            {
                symCount++;
            }
        }
        if (symCount == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (i = 0; i < game.pathLength; i++)
            {
                if (currentPosition[i] == player.charSymbol)
                {
                    printf("%c\n", currentPosition[i]);
                    break;
                }
                else
                {
                    printf("%c", currentPosition[i]);
                }
            }
        }

        for (i = 0; i < game.pathLength; i++)
        {
            currentPosition[i] = ' ';
        }

        //second line
        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%c", positionItem[i]);
        }
        printf("\n");

        //third line
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        //fourth line
        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");

        // display current stats
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesLeft, player.numTreasure, movesLeft);
        printf("+---------------------------------------------------+\n");

        // exit loop if 0
        if (livesLeft == 0)
        {
            break;
        }

        if (movesLeft == 0)
        {
            break;
        }

        // asking user for next movement
        do {
            printf("Next Move [1-20]: ");
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > game.pathLength);
        printf("\n");

        if (player.positions[movePosition - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = player.charSymbol;
            movesLeft++;
        }

        else if (game.bombs[movePosition - 1] == 1 && game.treasures[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = player.charSymbol;
            livesLeft--;
            player.numTreasure++;
        }

        else if (game.bombs[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = player.charSymbol;
            livesLeft--;
        }

        else if (game.treasures[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = player.charSymbol;
            player.numTreasure++;
        }

        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = player.charSymbol;
        }

        // keeping the position
        player.positions[movePosition - 1] = 1;

        // decrement moves after each move
        movesLeft--;

        if (livesLeft == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
        if (movesLeft == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

    } while (movesLeft >= 0 && livesLeft >= 0);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}