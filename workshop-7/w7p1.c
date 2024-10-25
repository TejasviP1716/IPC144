/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//define macro's
#define MAX_LIVE 10
#define MIN_LIVE 1
#define PATH_DIVISION 5
#define MINIMUM_MOVE 3
#define MAX_PATH_LENGHT 70
#define MIN_PATH_LENGTH 10

//taking the structure of PlayerInfo
struct PlayerInfo
{
    int live;
    int moves;
    char symbol;
    int history[MAX_PATH_LENGHT];
};

//taking the structure of GameInfo
struct GameInfo
{
    int move;
    int length;
    int bombLocation[MAX_PATH_LENGHT];
    int treasureLocation[MAX_PATH_LENGHT];
};

int main(void)
{
    struct PlayerInfo playerInfo = { 0 };
    struct GameInfo gameInfo = { 0 };
    int looping, i;
    int valid = 0, j; // loop for bomb's location

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    //player configuration starts from here
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%c", &playerInfo.symbol);

    //loop start for live's.....
    do
    {
        looping = 1;
        printf("Set the number of lives: ");
        scanf("%d", &playerInfo.live);

        if (playerInfo.live < MIN_LIVE || playerInfo.live > MAX_LIVE)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVE, MAX_LIVE);
        }
        else
        {
            looping = 0;
        }

    } while (looping);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    //loop start for the length's
    do
    {
        looping = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ", PATH_DIVISION, MIN_PATH_LENGTH, MAX_PATH_LENGHT);
        scanf("%d", &gameInfo.length);

        if (gameInfo.length < MIN_PATH_LENGTH || gameInfo.length > MAX_PATH_LENGHT || gameInfo.length % 5 != 0)
        {
            printf("     Must be a multiple of %d and between %2d-%2d!!!\n", PATH_DIVISION, MIN_PATH_LENGTH, MAX_PATH_LENGHT);
        }
        else
        {
            looping = 0;
        }
    } while (looping);

    //loop start for the move's
    do
    {
        looping = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameInfo.move);

        if (gameInfo.move < MINIMUM_MOVE || gameInfo.move >(int) ((gameInfo.length * 0.75) + 0.5))
        {
            printf("    Value must be between %d and %d\n", MINIMUM_MOVE, (int)((gameInfo.length * 0.75) + 0.5));
        }
        else
        {
            looping = 0;
        }
    } while (looping);

    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of %d where a value\n", PATH_DIVISION);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.length);

    //location of bomb's

    for (i = 0; i < gameInfo.length / PATH_DIVISION; i++)
    {
        printf("   Positions [%2d-%2d]: ", valid + 1, valid + PATH_DIVISION);

        for (j = 0; j < PATH_DIVISION; j++)
        {
            scanf("%d", &gameInfo.bombLocation[valid]);
            valid++;
        }
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");

    printf("Enter the treasure placements in sets of %d where a value\n", PATH_DIVISION);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.length);

    //location for treasure's
    valid = 0;
    for (i = 0; i < gameInfo.length / PATH_DIVISION; i++)
    {
        printf("   Positions [%2d-%2d]: ", valid + 1, valid + PATH_DIVISION);
        for (j = 0; j < PATH_DIVISION; j++)
        {
            scanf("%d", &gameInfo.treasureLocation[valid]);
            valid++;
        }
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    //information of players.....
    printf("Player:\n");
    printf("   Symbol     : %c\n", playerInfo.symbol);
    printf("   Lives      : %d\n", playerInfo.live);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", gameInfo.length);
    printf("   Bombs      : ");

    //display the locations of bomb's
    for (i = 0; i < gameInfo.length; i++)
    {
        printf("%d", gameInfo.bombLocation[i]);
    }
    printf("\n");
    printf("   Treasure   : ");

    //display the locations of treasure's
    for (i = 0; i < gameInfo.length; i++)
    {
        printf("%d", gameInfo.treasureLocation[i]);
    }

    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    return 0;
} 
