#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "hangman.h"

char words[10][25] = {
    "help",
    "clean the house",
    "ear",
    "mountain",
    "money",
    "diamond ring",
    "potato",
    "polar bear",
    "nose",
    "guard"};

char selected_word[25];
char guess_word[25];
char already_used[26];
int already_usedIndex = 0;

int points = 0;
int errors = 0;

int DrawHangMan(int errors)
{
    printf("\n\n-------------------");
    printf("\n|/\t\t  |");

    switch (errors)
    {
    case 1:
        printf("\n|\t\t  O");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        break;

    case 2:
        printf("\n|\t\t  O");
        printf("\n|\t\t  ^");
        printf("\n|\t\t  |");
        printf("\n|\t\t  ^");
        printf("\n|");
        break;

    case 3:
        printf("\n|\t\t  O");
        printf("\n|\t\t  ^");
        printf("\n|\t\t  |");
        printf("\n|\t\t  ^");
        printf("\n|\t\t /");
        break;

    case 4:
        printf("\n|\t\t  O");
        printf("\n|\t\t  ^");
        printf("\n|\t\t  |");
        printf("\n|\t\t  ^");
        printf("\n|\t\t / \\");
        break;

    case 5:
        printf("\n|\t\t  O");
        printf("\n|\t\t  ^");
        printf("\n|\t\t /|");
        printf("\n|\t\t  ^");
        printf("\n|\t\t / \\");
        break;

    case 6:
        printf("\n|\t\t  O");
        printf("\n|\t\t  ^");
        printf("\n|\t\t /|\\");
        printf("\n|\t\t  ^");
        printf("\n|\t\t / \\");
        printf("\n\n\t      You Lost!\n");
        int choice = PostGameMenu(5);
        break;

    default:
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        printf("\n|");
        break;
    }
}

void ChooseWord()
{
    int rand = GenerateRandomInt(0, 9);
    strcpy(selected_word, words[rand]);

    for (int i = 0; i < strlen(selected_word); i++)
    {
        if (selected_word[i] != ' ')
        {
            guess_word[i] = '1';
        }
        else
        {
            guess_word[i] = '0';
        }
    }
}

void ShowWord()
{
    printf("\nWord: ");
    for (int i = 0; i < strlen(guess_word); i++)
    {
        if (guess_word[i] == '0')
        {
            printf(" ");
        }
        else if (guess_word[i] == '1')
        {
            printf(" _");
        }
        else
        {
            printf(" %c", guess_word[i]);
        }
    }
}

void CharGuess(char answer)
{
    DrawStuff();

    int foundCount = 0;

    for (int i = 0; i < strlen(selected_word); i++)
    {
        if (selected_word[i] == answer && guess_word[i] != answer)
        {
            foundCount++;
            guess_word[i] = selected_word[i];
        }
    }

    if (foundCount == 0)
    {
        errors++;
        if (points > 0)
        {
            points--;
        }
    }
    else
    {
        points++;
    }

    DrawStuff();

    int win = 1;

    for (int i = 0; i < strlen(selected_word); i++)
    {
        if (selected_word[i] != guess_word[i] && selected_word[i] != ' ')
        {
            win = 0;
        }
    }

    if (win == 1)
    {
        GameWin();
    }
    else
    {
        PlayingMenu();
    }
}

void FullGuess()
{
    DrawStuff();

    int foundCount = 0;
    char answer[25];

    printf("\nFull Guess!!!\n"
           "Guess: ");
    fgets(answer, 25, stdin);

    if (strcmp(answer, selected_word))
    {
        for (int i = 0; i < strlen(answer); i++)
        {
            if (selected_word[i] == answer[i] && guess_word[i] != answer[i])
            {
                foundCount++;
                guess_word[i] = selected_word[i];
            }
        }
    }

    if (foundCount == 0)
    {
        errors = 6;
    }
    else
    {
        points += foundCount;
    }

    DrawStuff();

    int win = 1;

    for (int i = 0; i < strlen(selected_word); i++)
    {
        if (selected_word[i] != guess_word[i] && selected_word[i] != ' ')
        {
            win = 0;
        }
    }

    if (win == 1)
    {
        GameWin();
    }
    else
    {
        PlayingMenu();
    }
}

void SetAlreadyUsed(char answer)
{
    for (int i = 0; i < strlen(already_used); i++)
    {
        if (already_used[i] == answer)
            return;
    }
    already_used[already_usedIndex] = answer;
    already_usedIndex++;
}

void ShowAlreadyUsed()
{
    printf("\nAlready tried: ");
    for (int i = 0; i < strlen(already_used); i++)
    {
        printf(" %c", already_used[i]);
    }
}

void PlayingMenu()
{
    printf("\n\nEnter 1 - Full Guess"
           "\nEnter 0 - Back\n"
           "\nCharacter to guess: ");

    char choice = GetChoiceChar();
    switch (choice)
    {
    case '1':
        FullGuess();
        break;
    case '0':
        GameSelect2();
        break;
    default:
        SetAlreadyUsed(choice);
        CharGuess(choice);
        break;
    }
}

void GameWin()
{
    printf("\nYou Win!!\nPoints: %d\n", points);
    ScoreboardAdd(3, points);
    PostGameMenu(5);
}

void DrawStuff()
{
    system("cls");
    // printf("%d, %d", errors, points); //Test printf
    ShowAlreadyUsed();
    DrawHangMan(errors);
    ShowWord();
}

void ResetGame()
{
    errors = 0;
    points = 0;
    already_usedIndex = 0;
    for (int i = 0; i < 25; i++)
    {
        selected_word[i] = ' ';
        guess_word[i] = ' ';
        already_used[i] = ' ';
    }
    ChooseWord();
}

void HangMan()
{
    ResetGame();
    DrawStuff();
    PlayingMenu();
}