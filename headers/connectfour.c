#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "connectfour.h"

#define ROWS 6
#define COLS 8
#define FOUR 4
char scores[ROWS][COLS];
int player = 1, bin = 0, cancel2 = 0;
char mark = 'X';

int ConnectFour()
{
    int choice = PlayMenu();
    if (choice == 1)
    {
        ConnectFourPvP();
    }
    else
    {
        ConnectFourPvCPU();
    }
}

int ConnectFourPvP()
{
    int level, points = 0, choice = -1, cancel = 0, i, j;
    printf("\t--- CONNECT FOUR ---\n\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 1; j < COLS; j++)
        {
            scores[i][j] = ' ';
        }
    }

    while (1)
    {
        board(); // draw board
        player = (player % 2) ? 1 : 2;
        if (cancel2 == 1)
        {
            printf("\nInvalid move\n");
            player--;
            cancel2 = 0;
        }
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %c, your turn!\n", mark);
        bin = GetChoice(1, 7);

        printf("\t--- CONNECT FOUR ---");
        printf("\n\n   Player 1 (X)  -  Player 2 (O)\n\n");
        for (level = ROWS - 1; level >= 0; level--)
        {
            if (scores[level][bin] == ' ')
            {
                scores[level][bin] = mark;
                break;
            }
            else if (scores[1][bin] == mark || scores[0][bin] == mark)
            {
                cancel2 = 1;
            }
        }
        if (check('X'))
        {
            printf("\n\nPlayer 1 wins!\n\n");
            points += 4;
            ScoreboardAdd(6, points);
            break;
        }
        if (check('O'))
        {
            printf("\n\nPlayer 2 wins!\n\n");
            points -= 4;
            if (points < 0)
            {
                points = 0;
            }
            ScoreboardAdd2(6, points);
            break;
        }
        player++;
        // board();
    }
    PostGameMenu(6);
    return 0;
}

int ConnectFourPvCPU()
{
    int level, points = 0, choice = -1, i, j;
    printf("\t--- CONNECT FOUR ---\n\n");

    for (i = 0; i < ROWS; i++)
    {
        for (j = 1; j < COLS; j++)
        {
            scores[i][j] = ' ';
        }
    }
    board(); // draw board

    while (1)
    {
        player = (player % 2) ? 1 : 2;
        if (cancel2 == 1)
        {
            printf("\nInvalid move\n");
            player--;
            cancel2 = 0;
        }
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %c, your turn!\n", mark);
        bin = (player == 1) ? GetChoice(1, 7) : BotIsso(1, 7);

        printf("\t--- CONNECT FOUR ---");
        printf("\n\n   Player 1 (X)  -  Player 2 (O)\n\n");
        for (level = ROWS - 1; level >= 0; level--)
        {
            if (scores[level][bin] == ' ')
            {
                scores[level][bin] = mark;
                break;
            }
            else if (scores[1][bin] == mark || scores[0][bin] == mark)
            {
                cancel2 = 1;
            }
        }
        board();
        if (check('X'))
        {
            printf("\n\nPlayer wins!\n\n");
            points += 4;
            ScoreboardAdd(6, points);
            break;
        }
        if (check('O'))
        {
            printf("\n\nCPU wins!\n\n");
            break;
        }
        player++;
    }
    PostGameMenu(6);
    return 0;
}

void board()
{
    char header[] = "  1   2   3   4   5   6   7  ";
    char horbar[] = "|---|---|---|---|---|---|---|";
    printf("\n\n%s\n", header);
    printf("%s\n", horbar);

    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 1; j < COLS; j++)
        {
            printf("| %c ", scores[i][j]);
        }
        printf("|\n");
        printf("%s\n", horbar);
    }
}

int check(char mark)
{
    // checks for 4-mark rows

    int i, j, k;
    int count;
    int ways = 4;

    for (i = 0; i < ROWS; ++i) // Goes down 1 by 1 in a colum
    {
        for (j = 0; j < ways; ++j) // Checks all 4 types (xxxxooo, oxxxxoo, ooxxxxo, oooxxxx)
        {
            count = 0;
            for (k = 0; k < 4; ++k)
            {
                if (scores[i][j + k] == mark)
                    count++; // checks if it's occupied and adds 1
            }
            if (count == 4)
                return 1; // if all 4 are there returns win
        }
    }

    // check for 4-mark columns
    for (j = 0; j < COLS; ++j)
    {
        for (i = 0; i < ways - 1; ++i)
        {
            count = 0;
            for (k = 0; k < 4; ++k)
            {
                if (scores[i + k][j] == mark)
                    count++;
            }
            if (count == 4)
                return 1;
        }
    }

    // check for 4-mark diagonals
    int ii, jj;
    for (i = 1; i < ROWS - 1; i++)
    {
        for (j = 1; j < COLS - 1; j++)
        {

            /* left-tilted diagonals */
            count = 0;
            // left-upwards:
            for (ii = i, jj = j; (ii >= 0) || (jj >= 0); ii--, jj--)
            {
                if (scores[ii][jj] == mark)
                {
                    count++;
                    if (count == 4)
                        return 1;
                }
                else
                    break;
            }
            // right-downwards:
            for (ii = i + 1, jj = j + 1; (ii <= ROWS - 1) || (jj <= COLS - 1); ii++, jj++)
            {
                if (scores[ii][jj] == mark)
                {
                    count++;
                    if (count == 4)
                        return 1;
                }
                else
                    break;
            }

            /* right-tilted diagonals */
            count = 0;
            // left-downwards:
            for (ii = i, jj = j; (ii <= ROWS - 1) || (jj >= 0); ii++, jj--)
            {
                if (scores[ii][jj] == mark)
                {
                    count++;
                    if (count == 4)
                        return 1;
                }
                else
                {
                    break;
                }
            }
            // right-upwards:
            for (ii = i - 1, jj = j + 1; (ii >= 0) || (jj <= COLS - 1); ii--, j++)
            {
                if (scores[ii][jj] == mark)
                {
                    count++;
                    if (count == 4)
                        return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return 0;
}
