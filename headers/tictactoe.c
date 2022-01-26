#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "tictactoe.h"

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void boardTicTacToe();

void TicTacToe() 
{
    int choice = PlayMenu();
    if (choice == 1)
    {
        TicTacToePvP();
    }
    else
    {
        TicTacToePvCPU();
    }
}

int TicTacToePvP()
{
    int i, player = 1, points = 0, choice = -1, cancel = 0;
    char mark = 'X';
    for (int i = 0; i < 10; i++)
    {
        square[i] = '0' + i;
    }
    do
    {
        boardTicTacToe();
        player = (player % 2) ? 1 : 2;
        if (cancel == 1)
        {
            printf("\nInvalid move\n");
            player--;
            cancel = 0;
            getch();
        }
        mark = (player == 1) ? 'X' : 'O';
        printf("   Player %c, enter a number:  ", mark);
        choice = GetChoice(1, 9);

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cancel = 1;
        }
        i = checkwin();
        player ++;
    } while (i == -1);
    boardTicTacToe();
    if (i == 1)
    {
        printf("==>\aPlayer %d wins\n", --player);
        if (player == 1)
        {
            ScoreboardAdd(4,1);
            ScoreboardAdd2(4,-1);
        }
        else
        {
            ScoreboardAdd(4,-2);
            ScoreboardAdd2(4,2);
        }
        choice = PostGameMenu(4);
    }
    else
    {
        printf("   ==>\aGame draw\n");
        choice = PostGameMenu(4);
    }
    return 0;
}

int TicTacToePvCPU()
{
    int i, player = 1, points = 0, choice = -1, cancel = 0;
    char mark = 'X';
    for (int i = 0; i < 10; i++)
    {
        square[i] = '0' + i;
    }
    do
    {
        boardTicTacToe();
        player = (player % 2) ? 1 : 2;
        if (cancel == 1)
        {
            printf("\nInvalid move\n");
            player--;
            cancel = 0;
            getch();
        }
        mark = (player == 1) ? 'X' : 'O';
        printf("   Player %c, enter a number:  ", mark);
        choice = (player == 1) ? GetChoice(1, 9) : BotIsso(1, 9);

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cancel = 1;
        }
        i = checkwin();
        player ++;
    } while (i == -1);
    boardTicTacToe();
    if (i == 1)
    {
        --player;
        printf((player == 1) ? "==>\aPlayer wins\n" : "==>\aCPU wins\n" );
        if (player == 1)
        {
            ScoreboardAdd(4,points);
        }
        choice = PostGameMenu(4);
    }
    else
    {
        printf("   ==>\aGame draw\n");
        choice = PostGameMenu(4);
    }
    return 0;
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3]) // horizontal
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7]) // vertical
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9]) //diagonal
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void boardTicTacToe()
{

    system("cls");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t   Tic Tac Toe");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");

    printf("   Player 1 (X)  -  Player 2 (O)\n\n");

    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t|     |     |     |\n");
    printf("\t|  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);

    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");

    printf("\t|  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);

    printf("\t|_____|_____|_____|\n");
    printf("\t|     |     |     |\n");

    printf("\t|  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);

    printf("\t|     |     |     |\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
}
