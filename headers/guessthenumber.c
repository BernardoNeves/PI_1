#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "guessthenumber.h"

void GuessTheNumber()
{
    int points = 0, tries = 0, choice = -1;
    tries = 0;
    printf("\t--- GUESS THE NUMBER ---\n\n");
    printf("\t--- SELECT RANGE ---\n"
           "\t Enter 1 - 0-10\n"
           "\t Enter 2 - 0-100\n"
           "\t Enter 3 - 0-1000\n"
           "\t Enter 4 - 0-X\n"
           "\n\t Enter 0 - Back\n");
    int max;
    choice = GetChoice(0, 4);
    switch (choice)
    {
    case 1:
        max = 10;
        break;
    case 2:
        max = 100;
        break;
    case 3:
        max = 1000;
        break;
    case 4:
        printf("\t--- GUESS THE NUMBER ---\n\n");
        printf("\t--- SELECT RANGE ---\n");
        printf("Max (0 - 99999999999999999)=  ");
        max = GetChoice(0, 99999999999999999);
        break;
    case 0:
        GameSelect1();
        break;
    default:
        printf("\n\t//Invalid Option//\n\n");
        GuessTheNumber();
        break;
    }

    int RandomInt = GenerateRandomInt(0, max);
    printf("\t--- GUESS THE NUMBER ---\n\t\t (0-%d)\n", max);
    // printf("%d\n", RandomInt); // Test Number
    choice = GetChoice(0, max);

    while (RandomInt != choice)
    {
        tries++;
        printf("\t--- GUESS THE NUMBER ---\n\t\t (0-%d)\n", max);
        if (RandomInt > choice && choice != 0)
        {
            printf("\n\t- The Number Is Higher than %d -\n\n", choice);
        }
        else if (choice != 0)
        {
            printf("\n\t- The Number Is Lower than %d -\n\n", choice);
        }
        choice = GetChoice(0, max);
    }

    points = 10 - tries;
    if (points < 0)
    {
        points = 0;
    }
    printf("\t--- GUESS THE NUMBER ---\n\t\t (0-%d)\n", max);
    printf("\n\t- %d is Correct -\n\n", choice);
    printf("\n\t- %d points -\n\n", points);
    ScoreboardAdd(1, points);
    choice = PostGameMenu(1);
}
