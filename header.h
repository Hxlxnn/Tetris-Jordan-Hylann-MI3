#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> 

unsigned long  getTimeMicrosec();
void buffer();
void affiche_piece(char *tab[]);
void creer_plateau(char tabPlateau[10][10]);
void affiche_plateau(char tabPlateau[10][10]);
int largeurPiece(char *piece[7][4][4],int nbPieceF, int orientationF);
int maxligne(char tabPlateau[10][10], int colonne_ml, int largeur, char* piece[4]);
int Occuper(char tabPlateau[10][10], char *piece[7][4][4], int nbPiece_O, int orientation_O, int ligne_O, int colonne_O);
int verif_place(int colonnevp, char *piece[7][4][4],int nbPieceF, int orientationF);
int Suppligne(char tabPlateau[10][10], int score);
int placerPiece(char tabPlateau[10][10], char *piece[7][4][4],int nbPieceF, int orientationF, int score);
void jeu(char tabPlateau[10][10], char *tabPiece[7][4][4], int score);