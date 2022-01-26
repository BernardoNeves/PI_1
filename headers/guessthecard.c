#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "guessthecard.h"

void GuessTheCard()
{
    int points = 0, tries = -1, choice = -1, choiceNum = 0, choiceSuit = 0;
    int RandomIntNum = GenerateRandomInt(1, 13);
    int RandomIntSuit = GenerateRandomInt(1, 4);
    printf("\t--- GUESS THE CARD ---\n");
    while (RandomIntNum != choiceNum || RandomIntSuit != choiceSuit)
    {
        if (RandomIntNum != choiceNum)
        {
            if (RandomIntNum > choiceNum && choiceNum != 0)
            {
                printf("\n\t- The Number Is Higher than that -\n\n");
            }
            else if (choiceNum != 0)
            {
                printf("\n\t- The Number Is Lower than that -\n\n");
            }
            printf("\n\tNum:");
            choiceNum = GetChoice(1, 13);
            printf("\t--- GUESS THE CARD ---\n");
            if (RandomIntNum == choiceNum && RandomIntSuit == choiceSuit)
            {
                printf("\n\t- Correct Number -\n\n");
            }
        }

        if (RandomIntSuit != choiceSuit)
        {
            printf("\n\tSuit:");
            choiceSuit = GetChoice(1, 4);
            printf("\t--- GUESS THE CARD ---\n");
            if (RandomIntSuit != choiceSuit)
            {
                printf("\n\t- Wrong Suit -\n\n");
            }
            else
            {
                printf("\n\t- Correct Suit -\n\n");
            }
        }
        tries++;
    }
    system("cls");
    printf("\t--- GUESS THE CARD ---\n");
    printf("\n\t- Correct Card -\n\n");
    points = 6 - tries;
    if (points < 0)
    {
        points = 0;
    }
    ScoreboardAdd(2, points);
    choice = PostGameMenu(2);
}
