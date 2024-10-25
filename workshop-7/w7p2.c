/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MAX_LIVE 10
#define MIN_LIVE 1
#define PATH_DIVISION 5

struct PlayerInfo
{
    int live;
    char moves;
    int symbol;
    int history[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int move;
    int pathLength;
    int bombLocation[MAX_PATH_LENGTH];
    int treasureLocation[MAX_PATH_LENGTH];
};


int main(void)
{
    int looping, count, i;
    int valid = 0, ongoingGame = 1;
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.moves);

    do {
        looping = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.live);

        if (player.live < MIN_LIVE || player.live > MAX_LIVE)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVE, MAX_LIVE);
            looping = 0;
        }
        else
        {
            looping = 1;
        }
    } while (!looping);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", PATH_DIVISION, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);

        looping = 1;

        if (game.pathLength<MIN_PATH_LENGTH || game.pathLength>MAX_PATH_LENGTH || game.pathLength % PATH_DIVISION != 0)
        {
            looping = 0;
            printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_DIVISION, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (!looping);

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.move);

        looping = 1;

        if (game.move < player.live || game.move >(int)(0.75 * game.pathLength))
        {
            looping = 0;
            printf("    Value must be between %d and %d\n", player.live, (int)(0.75 * game.pathLength));
        }
    } while (!looping);

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", PATH_DIVISION);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    count = 0;


    do {
        printf("   Positions [%2d-%2d]: ", count + 1, count + PATH_DIVISION);
        for (i = count; i < count + PATH_DIVISION; i++)
        {
            scanf("%d", &game.bombLocation[i]);
        }
        count += PATH_DIVISION;
        if (count < game.pathLength)
        {
            looping = 0;
        }
        else
        {
            looping = 1;
        }
    } while (!looping);

    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", PATH_DIVISION);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    count = 0;


    do {
        printf("   Positions [%2d-%2d]: ", count + 1, count + PATH_DIVISION);
        for (i = count; i < count + PATH_DIVISION; i++)
        {
            scanf("%d", &game.treasureLocation[i]);
        }
        count += PATH_DIVISION;
        if (count < game.pathLength)
        {
            looping = 0;
        }
        else
        {
            looping = 1;
        }
    } while (!looping);
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.moves);
    printf("   Lives      : %d\n", player.live);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombLocation[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasureLocation[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");


    ongoingGame = 1;
    do {
        if (valid)
        {
            printf(" ");
            for (i = 0; i < valid - 1; i++)
            {
                printf(" ");
            }
            printf(" %c\n", player.moves);
        }
        else
        {
            printf("\n");
        }
        printf("  ");

        ongoingGame = 1;
        for (i = 0; i < game.pathLength; i++)
        {
            if (player.history[i] == 1)
            {
                if (game.bombLocation[i] == 0 && game.treasureLocation[i] == 0)
                {
                    printf(".");
                }
                else if (game.bombLocation[i] == 1 && game.treasureLocation[i] == 1)
                {
                    printf("&");
                }
                else if (game.treasureLocation[i] == 1)
                {
                    printf("$");
                }
                else if (game.bombLocation[i] == 1)
                {
                    printf("!");
                }
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
        printf("  ");

        ongoingGame = 1;
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("%d", (i + 1) / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");
        printf("  ");

        ongoingGame = 1;
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", (i + 1) % 10);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.live, player.symbol, game.move);
        printf("+---------------------------------------------------+\n");

        if (player.live <= 0 || game.move <= 0)
        {
            ongoingGame = 0;
        }
        else
        {
            ongoingGame = 1;
            printf("Next Move [%d-%d]: ", 1, game.pathLength);
            scanf("%d", &valid);
            looping = 1;
            while (valid > game.pathLength || valid < 1)
            {
                if (valid < 1 || valid > game.pathLength)
                {
                    printf("  Out of Range!!!\n");
                    printf("Next Move [%d-%d]: ", 1, game.pathLength);
                    scanf("%d", &valid);

                }
            }
            printf("\n");
            if (player.history[valid - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n\n");
            }
            else
            {
                game.move--;
                player.history[valid - 1] = 1;
                if (game.bombLocation[valid - 1] == 1 && game.treasureLocation[valid - 1] == 1)
                {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                    player.symbol++;
                    player.live--;

                }
                else if (game.bombLocation[valid - 1] == 1)
                {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                    player.live--;
                }
                else if (game.treasureLocation[valid - 1] == 1)
                {
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                    player.symbol++;
                }
                else
                {
                    printf("===============> [.] ...Nothing found here... [.]\n");
                }
                if (player.live <= 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                }
                if (game.move <= 0)
                {
                    printf("\nNo more MOVES remaining!\n");
                }
                printf("\n");


            }
        }
    } while (ongoingGame || (player.live > 0 && game.move > 0));
    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");
    return 0;
}
