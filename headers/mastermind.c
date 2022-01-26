#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "mastermind.h"

int chosenColors[4];
int sequenceGuess[4];
int attempts = 10;
int rightColors = 0;
int rightPlace = 0;
int lastAttempts[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

void ChooseColors(){
    srand(time(NULL));
    int randomColor = (rand() % (4)) + 3;
    for(int i=0; i<4; i++){
        switch(i){
            case 0:
                while(CheckChosenColor(randomColor) == 1){
                    randomColor = (rand() % (4)) + 3;
                }
                chosenColors[0] = randomColor;
                break;
            case 1:
                while(CheckChosenColor(randomColor) == 1){
                    randomColor = (rand() % (4)) + 3;
                }
                chosenColors[1] = randomColor;
                break;
            case 2:
                while(CheckChosenColor(randomColor) == 1){
                    randomColor = (rand() % (4)) + 3;
                }
                chosenColors[2] = randomColor;
                break;
            case 3:
                while(CheckChosenColor(randomColor) == 1){
                    randomColor = (rand() % (4)) + 3;
                }
                chosenColors[3] = randomColor;
                break;
        }
    }
}

void CheckSequence(){
    for(int i=0;i<4; i++){
        for(int j=0;j<4;j++){
            if(sequenceGuess[i] == chosenColors[j]-2){
                rightColors++;
                if(i == j){
                    rightPlace++;
                }
                break;
            }
        }
    }

    if(rightColors != 4 || rightPlace != 4){
        if(attempts == 0){
            system("cls");
            printf("You Lost!!\n");
            ScoreboardAdd(7, -5);
            PostGameMenu(7);
        }else{
            attempts--;
            rightColors = 0;
            lastAttempts[attempts] = rightPlace;
            rightPlace = 0;
            SlotMenu();
        }
    }else{
        system("cls");
        printf("You Win!!\n");
        ScoreboardAdd(7, 20);
        PostGameMenu(7);
    }
}

void GuessSequence(){
    DrawStuffMasterMind();

    for(int i=0;i<4;i++){
        printf("\nEnter guess for slot %d\n", i);
        scanf(" %d", &sequenceGuess[i]);
        if(sequenceGuess[i] != 1 && sequenceGuess[i] != 2 && sequenceGuess[i] != 3 && sequenceGuess[i] != 4){
            attempts--;
            printf("Wrong Answer!\n");
            SlotMenu();
        }
    }

    CheckSequence();

}

int CheckChosenColor(int randomNum){
    for(int j=0;j<4;j++){
        if(chosenColors[j] == randomNum){
            return 1;
        }
    }
    return 0;
}

void SlotMenu(){
    for(int i=9;i>0;i--){
        if(lastAttempts[i] != 5){
            printf("Attempt %d - %d right place\n", i+1, lastAttempts[i]);
        }
    }
   printf("\n1 - %c | 2 - %c | 3 - %c | 4 - %c\n"
        "\nAttempts left: %d\n"
        "\nEnter 1 - Guess Sequence"
		"\nEnter 0 - Back\n", 3, 4, 5, 6, attempts, rightColors, rightPlace);

   int choice = GetChoice(0, 1);
   switch(choice){
      case 1:
         GuessSequence();
         break;
      case 0:
         GameSelect2();
         break;
    }
}

void DrawStuffMasterMind(){
    system("cls");
    for(int i=9;i>0;i--){
        if(lastAttempts[i] != 5){
            printf("Attempt %d - %d right place\n", i+1, lastAttempts[i]);
        }
    }
    printf("1 - %c | 2 - %c | 3 - %c | 4 - %c\n"
        "Colors in right place: %d\n", 3, 4, 5, 6, attempts, rightColors, rightPlace);

    //DEV PRINT
    // for(int i=0;i<4;i++){
    //     printf("%c ", chosenColors[i]);
    // }
    // printf("\n");
}

void ResetStuffMM(){
    for(int i=0;i<4;i++){
        chosenColors[i] = 0;
    }
    for(int i=0;i<10;i++){
        lastAttempts[i] = 5;
    }
    attempts = 10;
}

//add BotIsso
void MasterMind()
{
    ResetStuffMM();
    ChooseColors();
    SlotMenu();
}
