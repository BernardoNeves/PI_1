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

void MainMenu()
{
   printf("\t--- MAIN MENU ---\n"
          "\t Enter 1 - Select game\n"
          "\t Enter 2 - Scoreboard\n"
          "\t Enter 3 - Select Players\n"
          "\n\t Enter 0 - Quit\n");

   int choice = GetChoice(0, 3);
   switch (choice)
   {
   case 1:
      GameSelect1();
      break;
   case 2:
      ScoreSelect();
      break;
   case 3:
      printf("\t--- SELECT PLAYERS ---\n");
      GetName();
      system("cls");
      MainMenu();
      break;
   case 0:
      exit;
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      MainMenu();
      break;
   }
}

void GameSelect1()
{
   printf("\t--- SELECT GAME ---\n"
          "\t Enter 1 - Guess the number\n"
          "\t Enter 2 - Guess the card\n"
          "\t Enter 3 - Blackjack\n"
          "\t Enter 4 - Tic-Tac-Toe\n"
          "\n\t Enter 9 - Next"
          "\n\t Enter 0 - Back\n");
   int choice = GetChoice(0, 9);
   switch (choice)
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
   case 9:
      GameSelect2();
      break;
   case 0:
      MainMenu();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      GameSelect1();
      break;
   }
}

void GameSelect2()
{
   printf("\t--- SELECT GAME ---\n"
          "\t Enter 1 - Hangman\n"
          "\t Enter 2 - Connect Four\n"
          "\t Enter 3 - MasterMind\n"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 3);
   switch (choice)
   {
   case 1:
      HangMan();
      break;
   case 2:
      ConnectFour();
      break;
   case 3:
      MasterMind();
      break;
   case 0:
      GameSelect1();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      GameSelect2();
      break;
   }
}

void ScoreSelect()
{
   printf("\t--- SELECT SCOREBOARD ---\n"
          "\t Enter 1 - Global Scoreboard\n"
          "\t Enter 2 - Games ScoreBoard\n"
          "\t Enter 3 - Reset ScoreBoards\n"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(-1, 3);
   switch (choice)
   {
   case 1:
      ScoreboardPrint(0, 0);
      break;
   case 2:
      ScoreSelect1();
      break;
   case 3:
      ScoreSelect3();
      break;
   case 0:
      MainMenu();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      ScoreSelect();
      break;
   }
}

void ScoreSelect1()
{
   printf("\t--- SELECT SCOREBOARD ---\n"
          "\t Enter 1 - Guess the number\n"
          "\t Enter 2 - Guess the card\n"
          "\t Enter 3 - Blackjack\n"
          "\t Enter 4 - Tic-Tac-Toe\n"
          "\n\t Enter 9 - Next"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 9);
   switch (choice)
   {
   case 1:
      ScoreboardPrint(1, 0);
      // ScoreboardReturn(1);
      break;
   case 2:
      ScoreboardPrint(2, 0);
      // ScoreboardReturn(1);
      break;
   case 3:
      ScoreboardPrint(3, 0);
      // ScoreboardReturn(1);
      break;
   case 4:
      ScoreboardPrint(4, 0);
      // ScoreboardReturn(1);
      break;
   case 9:
      ScoreSelect2();
      break;
   case 0:
      ScoreSelect();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      ScoreSelect1();
      break;
   }
}

void ScoreSelect2()
{
   printf("\t--- SELECT SCOREBOARD ---\n"
          "\t Enter 1 - Hangman\n"
          "\t Enter 2 - Connect Four\n"
          "\t Enter 3 - MasterMind\n"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 3);
   switch (choice)
   {
   case 1:
      ScoreboardPrint(5, 0);
      // ScoreboardReturn(2);
      break;
   case 2:
      ScoreboardPrint(6, 0);
      // ScoreboardReturn(2);
      break;
   case 3:
      ScoreboardPrint(7, 0);
      // ScoreboardReturn(2);
      break;
      break;
   case 0:
      ScoreSelect1();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      ScoreSelect2();
      break;
   }
}

void ScoreSelect3()
{
   printf("\t--- RESET SCOREBOARD ---\n"
          "\t Enter 1 - Global Scoreboard\n"
          "\t Enter 2 - Games ScoreBoard\n"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(-1, 2);
   switch (choice)
   {
   case 1:
      ScoreboardReset(0);
      break;
   case 2:
      ScoreSelect4();
      break;
   case 0:
      ScoreSelect();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      ScoreSelect();
      break;
   }
}

void ScoreSelect4()
{
   printf("\t--- RESET SCOREBOARD ---\n"
          "\t Enter 1 - Guess the number\n"
          "\t Enter 2 - Guess the card\n"
          "\t Enter 3 - Blackjack\n"
          "\t Enter 4 - Tic-Tac-Toe\n"
          "\n\t Enter 9 - Next"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 9);
   switch (choice)
   {
   case 1:
      ScoreboardReset(1);
      break;
   case 2:
      ScoreboardReset(2);
      break;
   case 3:
      ScoreboardReset(3);
      break;
   case 4:
      ScoreboardReset(4);
      break;
   case 9:
      ScoreSelect5();
      break;
   case 0:
      ScoreSelect();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      ScoreSelect4();
      break;
   }
}

void ScoreSelect5()
{
   printf("\t--- RESET SCOREBOARD ---\n"
          "\t Enter 1 - Hangman\n"
          "\t Enter 2 - Connect Four\n"
          "\t Enter 3 - MasterMind\n"
          "\n\t Enter 0 - Back\n");

   int choice = GetChoice(0, 3);
   switch (choice)
   {
   case 1:
      ScoreboardReset(5);
      break;
   case 2:
      ScoreboardReset(6);
      break;
   case 3:
      ScoreboardReset(7);
      break;
   case 0:
      ScoreSelect4();
      break;
   default:
      printf("\n\t//Invalid Option//\n\n");
      ScoreSelect5();
      break;
   }
}
