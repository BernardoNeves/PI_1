#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "blackjack.h"
#include "connectfour.h"
#include "guessthenumber.h"
#include "guessthecard.h"
#include "hangman.h"
#include "mastermind.h"
#include "tictactoe.h"

// maybe improve with getch();
int GetChoice(int min, int max)
{
   int choiceInt = -1;
   char choiceChar;
   printf("\n Select - ");
   scanf(" %d", &choiceInt);
   scanf("%c", &choiceChar);
   while (choiceInt > max || choiceInt < min)
   {
      printf("\n\t//Invalid Option//\n\n");
      printf("\n Select - ");
      scanf(" %d", &choiceInt);
      scanf("%c", &choiceChar);
   }
   system("cls");
   return choiceInt;
}

char GetChoiceChar()
{
   char choiceChar;
   int ch;
   printf("\n Select - ");
   scanf(" %c", &choiceChar);
   while (choiceChar == '2' || choiceChar == '3' || choiceChar == '4' || choiceChar == '5' || choiceChar == '6' || choiceChar == '7' || choiceChar == '8' || choiceChar == '9')
   {
      printf("\n Select - ");
      scanf(" %c", &choiceChar);
   }

   while ((ch = getchar()) != '\n' && ch != EOF);
   system("cls");
   return choiceChar;
}

int GenerateRandomInt(int min, int max)
{
   srand((unsigned)time(NULL));
   return min + rand() % (max - min);
}

int BotIsso(int min, int max)
{
   system("cls");
   int play = GenerateRandomInt(min, max);
   return play;
}

int PlayMenu()
{
   printf("\t--- MAIN MENU ---\n"
          "\t Enter 1 - Player VS Player\n"
          "\t Enter 2 - Player VS CPU\n"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 2);
   switch (choice)
   {
   case 1:
      return 1;
      break;
   case 2:
      return 2;
      break;
   case 0:
      MainMenu();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      PlayMenu();
      break;
   }
}

int PostGameMenu(int game)
{
   printf("\t--- SELECT GAME ---\n"
          "\t Enter 1 - Play Again"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 1);
   switch (choice)
   {
   case 1:
      switch (game)
      {
      case 1:
         GuessTheNumber();
         break;
      case 2:
         GuessTheCard();
         break;
      case 3:
         Blackjack();
         break;
      case 4:
         TicTacToe();
         break;
      case 5:
         HangMan();
         break;
      case 6:
         ConnectFour();
         break;
      case 7:
         MasterMind();
         break;
      default:
         MainMenu();
         break;
      }
      break;
   case 0:
      if (game < 5)
      {
         GameSelect1();
      }
      else
      {
         GameSelect2();
      }

      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      PostGameMenu(0);
      break;
   }
}
