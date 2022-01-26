#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "menus.h"
#include "games.h"
#include "scoreboard.h"
#include "blackjack.h"

//"♠♥♣♦"
int draws = 1;
int Baralho[51];

/* void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    //printf("%d\n", a);
} */

void Blackjack()
{

    for (int l = 52; l > 0; l--)
    {
        Baralho[l] = l;
    }

    for (int i = 52; i > 0; i--)
    {

        int j = rand() % 52;
        //int j = GenerateRandomInt(0,51);
        //swap(Baralho[i], Baralho[j]);
        int temp = Baralho[i];
        Baralho[i] = Baralho[j];
        Baralho[j] = temp;

        // Baralho[i] = swap(Baralho[i], Baralho[j]);

        //printf("%d\n", Baralho[i]);
    }
    printf("\n Your Draw:");
    int CPUburst = 0, playerburst = 0;
    playerburst = draw();
    printf("\n Total: %d", playerburst);
    printf("\n Dealer Draw:");
    CPUburst = draw();
    continuedraw(playerburst, CPUburst);
}

void continuedraw(int p, int c)
{
    int answer;
    if (answer == 2)
    {
        cpudraw(p, c, answer);
    }

    printf("\n Draw?: 1-Yes 2-No");
    answer = GetChoice(1, 2);

    switch (answer)
    {
    case 1:
        playerdraw(p, c, answer);
        cpudraw(p, c, answer);
        break;

    case 2:

        cpudraw(p, c, answer);
        break;
    default:
        printf("\n Invalid Input");
        printf("\n Draw?: 1-Yes 2-No");
        continuedraw(p, c);
        break;
    }

    printf("\n", answer);
}
void playerdraw(int p, int c, int a)
{
    int temp = 0;
    temp = draw();
    p = p + temp;
    printf("\n Total: %d\t Carta:%d", p, temp);

    if (p > 21)
    {
        printf("\n %d", p);
        printf("\n You Burst, CPU wins\n ");
        draws=1;
        ScoreboardAdd(3, -1);
        PostGameMenu(3);
    }
    else if (p == 21)
    {
        printf("\n 21 ,You Win\n ");
        draws=1;
        ScoreboardAdd(3, 1);
        PostGameMenu(3);
    }
    else
    {
        cpudraw(p, c, a);
    }
}
void cpudraw(int p, int c, int a)
{

    int i = Baralho[draws];

    draws++;

    switch (i)
    {
        //♥
    case 1:
    case 14:
    case 27:
    case 40:

        c = c + 1;
        break;

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:

        c = c + i;
        break;

    case 11:
    case 12:
    case 13:
    case 24:
    case 25:
    case 26:
    case 37:
    case 38:
    case 39:
    case 50:
    case 51:
    case 52:

        c = c + 10;

        //♣

    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
        c = c + i - 13;
        break;

        //♦
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:

        c = c + i - 26;
        break;

        //♠
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:

        c = c + i - 39;
        break;

    default:
        break;
    }
    if (c > 21)
    {
        printf("\n Dealer Burst, You Win \n ");
        draws=1;
        ScoreboardAdd(3, 1);
        PostGameMenu(3);
    }
    else if (c == 21)
    {
        printf("\n 21 ,Dealer Wins \n");
        draws=1;
        ScoreboardAdd(3, -1);
        PostGameMenu(3);
    }
    else if (c > p)
    {
        printf("\n%d", c);
        printf("\n Dealer Wins \n");
        draws=1;
        ScoreboardAdd(3, -1);
        PostGameMenu(3);
    }
    else if (a == 2)
    {
        cpudraw(p, c, a);
    }
    else
    {
        continuedraw(p, c);
    }
}

int draw()
{
    int i = Baralho[draws];

    //printf("\n%d", Baralho[draws]);

    draws++;

    switch (i)
    {
        //♥
    case 1:
        printf("\n _______\n");
        printf("|A      |\n");
        printf("|       |\n");
        printf("| HEART |\n");
        printf("|       |\n");
        printf("|      A|\n");
        printf("|_______|\n");
        return 1;
        break;

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        printf("\n _______\n");
        printf("|%d      |\n",i);
        printf("|       |\n");
        printf("| HEART |\n");
        printf("|  (S)  |\n");
        printf("|      %d|\n",i);
        printf("|_______|\n");
        return i;
        break;

    case 11:
        printf("\n _______\n");
        printf("|J      |\n");
        printf("|  }:   |\n");
        printf("| HEART |\n");
        printf("|   :{  |\n");
        printf("|      J|\n");
        printf("|_______|\n");
        return 10;
        break;

    case 12:
        printf("\n _______\n");
        printf("|Q      |\n");
        printf("|  ._.  |\n");
        printf("| HEART |\n");
        printf("|  .-.  |\n");
        printf("|      Q|\n");
        printf("|_______|\n");
        return 10;

    case 13:
        printf("\n _______\n");
        printf("|K      |\n");
        printf("|  [:   |\n");
        printf("| HEART |\n");
        printf("|   :]  |\n");
        printf("|      K|\n");
        printf("|_______|\n");
        return 10;

        //♣

    case 14:
        printf("\n _______\n");
        printf("|A      |\n");
        printf("|       |\n");
        printf("| CLUBS |\n");
        printf("|       |\n");
        printf("|      A|\n");
        printf("|_______|\n");
        return 1;
        break;

    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
        i = i - 13;
        printf("\n _______\n");
        printf("|%d      |\n",i);
        printf("|       |\n");
        printf("| CLUBS |\n");
        printf("|       |\n");
        printf("|      %d|\n",i);
        printf("|_______|\n");
        return i;
        break;

    case 24:
        printf("\n _______\n");
        printf("|J      |\n");
        printf("|  ):   |\n");
        printf("| CLUBS |\n");
        printf("|   :(  |\n");
        printf("|      J|\n");
        printf("|_______|\n");
        return 10;
        break;

    case 25:
        printf("\n _______\n");
        printf("|Q      |\n");
        printf("|  I:   |\n");
        printf("| CLUBS |\n");
        printf("|   :I  |\n");
        printf("|      Q|\n");
        printf("|_______|\n");
        return 10;

    case 26:
        printf("\n _______\n");
        printf("|K      |\n");
        printf("|  |:<  |\n");
        printf("| CLUBS |\n");
        printf("|  >:|  |\n");
        printf("|      K|\n");
        printf("|_______|\n");
        return 10;

        //♦

    case 27:
        printf("\n _______\n");
        printf("|A      |\n");
        printf("|       |\n");
        printf("| OUROS |\n");
        printf("|       |\n");
        printf("|      A|\n");
        printf("|_______|\n");
        return 1;
        break;

    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
        i = i - 26;
        printf("\n _______\n");
        printf("|%d      |\n",i);
        printf("|       |\n");
        printf("| OUROS |\n");
        printf("|       |\n");
        printf("|      %d|\n",i);
        printf("|_______|\n");
        return i;
        break;

    case 37:
        printf("\n _______\n");
        printf("|J      |\n");
        printf("|  E:   |\n");
        printf("| OUROS |\n");
        printf("|   :3  |\n");
        printf("|      J|\n");
        printf("|_______|\n");
        return 10;
        break;

    case 38:
        printf("\n _______\n");
        printf("|Q      |\n");
        printf("|  L:   |\n");
        printf("| OUROS |\n");
        printf("|   :7  |\n");
        printf("|      Q|\n");
        printf("|_______|\n");
        return 10;

    case 39:
        printf("\n _______\n");
        printf("|K      |\n");
        printf("|  ]:>  |\n");
        printf("| OUROS |\n");
        printf("|  <:[  |\n");
        printf("|      K|\n");
        printf("|_______|\n");
        return 10;

        //♠

    case 40:
        printf("\n _______\n");
        printf("|A      |\n");
        printf("|       |\n");
        printf("| SPADE |\n");
        printf("|       |\n");
        printf("|      A|\n");
        printf("|_______|\n");
        return 1;
        break;

    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
        i = i - 39;
        printf("\n _______\n");
        printf("|%d      |\n",i);
        printf("|       |\n");
        printf("| SPADE |\n");
        printf("|       |\n");
        printf("|      %d|\n",i);
        printf("|_______|\n");
        return i;
        break;

    case 50:
        printf("\n _______\n");
        printf("|J      |\n");
        printf("|  ):>  |\n");
        printf("| SPADE |\n");
        printf("|  <:(  |\n");
        printf("|      J|\n");
        printf("|_______|\n");
        return 10;
        break;

    case 51:
        printf("\n _______\n");
        printf("|Q      |\n");
        printf("|  |:>  |\n");
        printf("| SPADE |\n");
        printf("|  <:|  |\n");
        printf("|      Q|\n");
        printf("|_______|\n");
        return 10;

    case 52:
        printf("\n _______\n");
        printf("|K      |\n");
        printf("|  7:>  |\n");
        printf("| SPADE |\n");
        printf("|  <:L   |\n");
        printf("|      K|\n");
        printf("|_______|\n");
        return 10;

    default:
        break;
    }
}
