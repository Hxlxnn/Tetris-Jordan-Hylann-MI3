#ifndef HEADER_H
#define HEADER_H

unsigned long  getTimeMicrosec();

void buffer();

// Affiche UNE pièce de jeu
void affiche_piece(char *tab[]);

// Crée le plateau de jeu
void creer_plateau(char tabPlateau[10][10]);

//Affiche le tabeau de jeu
void affiche_plateau(char tabPlateau[10][10]);

//Définit la largeur nécessaire pour placer une pièce
int largeurPiece(char *piece[7][4][4],int nbPieceF, int orientationF);

//Définit la hauteur à laquelle peut être placé la prochaine pièce
int maxligne(char tabPlateau[10][10], int colonne_ml, int largeur, char* piece[4]);

//Elle permet d
int Occuper(char tabPlateau[10][10], char *piece[7][4][4], int nbPiece_O, int orientation_O, int ligne_O, int colonne_O);

//Il vérifie si il y reste assez de place dans le tableau pour y mettre toute la pièce
int verif_place(int colonnevp, char *piece[7][4][4],int nbPieceF, int orientationF);
  
// Supprime une ligne lorsqu'elle est remplie
int Suppligne(char tabPlateau[10][10], int score);

//place une pièce dans le tableau
int placerPiece(char tabPlateau[10][10], char *piece[7][4][4],int nbPieceF, int orientationF, int score);

//Permet de continuer la partie
void jeu(char tabPlateau[10][10], char *tabPiece[7][4][4], int score);

#endif
