#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"

int i, ii, cancel = 0, scoreboard[11][10];
char name, name2, nameboard[10][10];
FILE *scorefile;

// Scoreboard Functions
void ScoreboardRead()
{
    scorefile = fopen("scoreboard.txt", "r");
    for (i = 0; i < 10; i++)
    {
        for (ii = 0; ii < 10; ii++)
        {
            fscanf(scorefile, "%d\n", &scoreboard[ii][i]);
            scoreboard[ii][0] = 0;
        }
        fscanf(scorefile, "\n");

        for (ii = 0; ii < 10; ii++)
        {
            fscanf(scorefile, "%d\n", &nameboard[ii][i]);
            nameboard[ii][0] = ' ';
        }
        fscanf(scorefile, "\n");
    }
    fclose(scorefile);
}

void ScoreboardWrite(int points)
{
    scorefile = fopen("scoreboard.txt", "w");
    for (i = 0; i < 10; i++)
    {
        for (ii = 0; ii < 10; ii++)
        {
            fprintf(scorefile, "%d\n", scoreboard[ii][i]);
        }
        fprintf(scorefile, "\n");

        for (ii = 0; ii < 10; ii++)
        {
            fprintf(scorefile, "%d\n", nameboard[ii][i]);
        }
        fprintf(scorefile, "\n");
    }
    fclose(scorefile);
}

void ScoreboardReturn(int game, int reset)
{
    printf("\n\tPress any key to go back");
    getch();
    system("cls");
    if (reset == 0)
    {
        if (game > 4)
        {
            ScoreSelect2();
        }
        else if (game > 0)
        {
            ScoreSelect1();
        }
        else
        {
            ScoreSelect();
        }
    }
    else
    {
        if (game > 4)
        {
            ScoreSelect5();
        }
        else if (game > 0)
        {
            ScoreSelect4();
        }
        else
        {
            ScoreSelect3();
        }
    }
}

// Scoreboard Operations
void ScoreboardReset(int game)
{
    printf("\n\t Scoreboard reset");
    ScoreboardRead();
    if (game > 0)
    {
        for (ii = 0; ii < 10; ii++)
        {
            scoreboard[ii][game] = 0;
        }
    }
    else if (game == 0)
    {
        for (game = 1; game < 10; game++)
        {
            for (ii = 0; ii < 10; ii++)
            {
                scoreboard[ii][game] = 0;
            }
        }
    }
    ScoreboardWrite(0);
    ScoreboardReturn(game, 1);
    fclose(scorefile);
}

void ScoreboardAdd(int game, int points)
{
    ScoreboardRead();
    for (i = 0; i < 10; i++)
    {
        if (points > scoreboard[i][game])
        {
            for (ii = 10; ii > i; ii--)
            {
                scoreboard[ii][game] = scoreboard[ii - 1][game];
                nameboard[ii][game] = nameboard[ii - 1][game];
            }
            scoreboard[i][game] = points;
            if (nameboard[i][game] != name)
            {
                nameboard[i][game] = name;
            }
            break;
        }
    }
    ScoreboardWrite(points);
}

void ScoreboardAdd2(int game, int points)
{
    ScoreboardRead();
    for (i = 0; i < 10; i++)
    {
        if (points > scoreboard[i][game])
        {
            for (ii = 10; ii > i; ii--)
            {
                scoreboard[ii][game] = scoreboard[ii - 1][game];
                nameboard[ii][game] = nameboard[ii - 1][game];
            }
            scoreboard[i][game] = points;
            if (nameboard[i][game] != name2)
            {
                nameboard[i][game] = name2;
            }
            break;
        }
    }
    ScoreboardWrite(points);
}

void GetName()
{
    printf("Player 1 : ");
    scanf(" %c", &name);
    printf("Player 2 : ");
    scanf(" %c", &name2);
}

void ScoreboardPrint(int game, int k)
{
    int temp = 0, temp2 = 0;
    ScoreboardRead();
    printf("Score || Name\n");
    for (i = 0; i < 10; i++)
    {
        for (ii = 10; ii > 0; ii--)
        {
            if (nameboard[ii][i] == name)
            {
                temp += scoreboard[ii][i];
            }
            if (nameboard[ii][i] == name2)
            {
                temp2 += scoreboard[ii][i];
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (temp > scoreboard[i][0])
        {
            for (ii = 10; ii > i; ii--)
            {
                scoreboard[ii][0] = scoreboard[ii - 1][0];
                nameboard[ii][0] = nameboard[ii - 1][0];
            }
            scoreboard[i][0] = temp;
            break;
        }
        if (temp2 > scoreboard[i][0])
        {
            for (ii = 10; ii > i; ii--)
            {
                scoreboard[ii][0] = scoreboard[ii - 1][0];
                nameboard[ii][0] = nameboard[ii - 1][0];
            }
            scoreboard[i][0] = temp2;
            break;
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (ii = 10; ii > 0; ii--)
        {
            scoreboard[i][0] += scoreboard[i][ii];
        }
        printf("\n> %d \t- ", scoreboard[i][game]);
        printf(" %c", nameboard[i][game]);
    }
    ScoreboardReturn(game, 0);
}
