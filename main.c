#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
  char *tabPiece[7][4][4]; //[forme][orientation][étage][colonne]
  // Carré
  tabPiece[0][0][0] = "**  ";
  tabPiece[0][0][1] = "**  ";
  tabPiece[0][0][2] = "    ";
  tabPiece[0][0][3] = "    ";
  // orientation 1
  tabPiece[0][1][0] = "**  ";
  tabPiece[0][1][1] = "**  ";
  tabPiece[0][1][2] = "    ";
  tabPiece[0][1][3] = "    ";
  // orientation 2
  tabPiece[0][2][0] = "**  ";
  tabPiece[0][2][1] = "**  ";
  tabPiece[0][2][2] = "    ";
  tabPiece[0][2][3] = "    ";
  // orientation 3
  tabPiece[0][3][0] = "**  ";
  tabPiece[0][3][1] = "**  ";
  tabPiece[0][3][2] = "    ";
  tabPiece[0][3][3] = "    ";

  // I
  tabPiece[1][0][0] = "*   ";
  tabPiece[1][0][1] = "*   ";
  tabPiece[1][0][2] = "*   ";
  tabPiece[1][0][3] = "*   ";
  // orientation 1
  tabPiece[1][1][0] = "****";
  tabPiece[1][1][1] = "    ";
  tabPiece[1][1][2] = "    ";
  tabPiece[1][1][3] = "    ";
  // orientation 2
  tabPiece[1][2][0] = "*   ";
  tabPiece[1][2][1] = "*   ";
  tabPiece[1][2][2] = "*   ";
  tabPiece[1][2][3] = "*   ";
  // orientation 3
  tabPiece[1][3][0] = "****";
  tabPiece[1][3][1] = "    ";
  tabPiece[1][3][2] = "    ";
  tabPiece[1][3][3] = "    ";

  // S
  tabPiece[2][0][0] = "**  ";
  tabPiece[2][0][1] = " **";
  tabPiece[2][0][2] = "    ";
  tabPiece[2][0][3] = "    ";
  // orientation 1
  tabPiece[2][1][0] = " *  ";
  tabPiece[2][1][1] = "**  ";
  tabPiece[2][1][2] = "*   ";
  tabPiece[2][1][3] = "    ";
  // orientation2
  tabPiece[2][2][0] = "**  ";
  tabPiece[2][2][1] = " ** ";
  tabPiece[2][2][2] = "    ";
  tabPiece[2][2][3] = "    ";
  // orientation3
  tabPiece[2][3][0] = " *  ";
  tabPiece[2][3][1] = "**  ";
  tabPiece[2][3][2] = "*   ";
  tabPiece[2][3][3] = "    ";

  // Z
  tabPiece[3][0][0] = " ** ";
  tabPiece[3][0][1] = "**  ";
  tabPiece[3][0][2] = "    ";
  tabPiece[3][0][3] = "    ";
  // orientation1
  tabPiece[3][1][0] = "*   ";
  tabPiece[3][1][1] = "**  ";
  tabPiece[3][1][2] = " *  ";
  tabPiece[3][1][3] = "    ";
  // orientation2
  tabPiece[3][2][0] = " ** ";
  tabPiece[3][2][1] = "**  ";
  tabPiece[3][2][2] = "    ";
  tabPiece[3][2][3] = "    ";
  // orientation3
  tabPiece[3][3][0] = "*   ";
  tabPiece[3][3][1] = "**  ";
  tabPiece[3][3][2] = " *  ";
  tabPiece[3][3][3] = "    ";

  // L
  tabPiece[4][0][0] = "**  ";
  tabPiece[4][0][1] = "*   ";
  tabPiece[4][0][2] = "*   ";
  tabPiece[4][0][3] = "    ";
  // orientation1
  tabPiece[4][1][0] = "*   ";
  tabPiece[4][1][1] = "*** ";
  tabPiece[4][1][2] = "    ";
  tabPiece[4][1][3] = "    ";
  // orientation2
  tabPiece[4][2][0] = " *  ";
  tabPiece[4][2][1] = " *  ";
  tabPiece[4][2][2] = "**  ";
  tabPiece[4][2][3] = "    ";
  // orientation3
  tabPiece[4][3][0] = "*** ";
  tabPiece[4][3][1] = "  * ";
  tabPiece[4][3][2] = "    ";
  tabPiece[4][3][3] = "    ";

  // J
  tabPiece[5][0][0] = "**  ";
  tabPiece[5][0][1] = " *  ";
  tabPiece[5][0][2] = " *  ";
  tabPiece[5][0][3] = "    ";
  // orientation1
  tabPiece[5][1][0] = "  * ";
  tabPiece[5][1][1] = "*** ";
  tabPiece[5][1][2] = "    ";
  tabPiece[5][1][3] = "    ";
  // orientation2
  tabPiece[5][2][0] = "*   ";
  tabPiece[5][2][1] = "*   ";
  tabPiece[5][2][2] = "**  ";
  tabPiece[5][2][3] = "    ";
  // orientation3
  tabPiece[5][3][0] = "*** ";
  tabPiece[5][3][1] = "*   ";
  tabPiece[5][3][2] = "    ";
  tabPiece[5][3][3] = "    ";
  // T
  tabPiece[6][0][0] = " *  ";
  tabPiece[6][0][1] = "*** ";
  tabPiece[6][0][2] = "    ";
  tabPiece[6][0][3] = "    ";
  // orientation 1
  tabPiece[6][1][0] = "*   ";
  tabPiece[6][1][1] = "**  ";
  tabPiece[6][1][2] = "*   ";
  tabPiece[6][1][3] = "    ";
  // orientation 2
  tabPiece[6][2][0] = "*** ";
  tabPiece[6][2][1] = " *  ";
  tabPiece[6][2][2] = "    ";
  tabPiece[6][2][3] = "    ";
  // orientation 3
  tabPiece[6][3][0] = " *  ";
  tabPiece[6][3][1] = "**  ";
  tabPiece[6][3][2] = " *  ";
  tabPiece[6][3][3] = "    ";

  int nbPiece, orientation, i, score = 0, a, b;
  srand(time(NULL));
  nbPiece = rand() % 7;
  for(i = 0; i < 4 ; i++)
  {
    printf("\n%d\n", i + 1);
    affiche_piece(tabPiece[nbPiece][i]);
  }
  
  unsigned long t1 = getTimeMicrosec();// 
  a = t1;
  do
  {
    printf("\nChoisissez l'orientation de la pièce: ");
    scanf("%d", &orientation);
    buffer();
    unsigned long t2 = getTimeMicrosec();
    b = t2;
  } while(orientation < 1 || orientation > 4);
  
  if (b - a > (15*1000000))
  {
    printf("Vous avez mis trop de temps\n");
    orientation = rand() % 4;
  }
  
  orientation -= 1;
  char tabPlateau[10][10];
  creer_plateau(tabPlateau);
  affiche_plateau(tabPlateau);
  score=placerPiece(tabPlateau, tabPiece, nbPiece, orientation, score);
  affiche_plateau(tabPlateau);
  jeu(tabPlateau, tabPiece, score);
 
  return 0;
}




