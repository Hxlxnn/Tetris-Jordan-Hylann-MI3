#include "header.h"

unsigned long  getTimeMicrosec() 
{
   struct timeval tv;
  gettimeofday(&tv,NULL);
  return (1000000 * tv.tv_sec) + tv.tv_usec;

}
void buffer()//
{
  while(getc(stdin)!='\n')
    {
      
    }
}
void affiche_piece(char *tab[])// Affiche UNE pièce de jeu
{
  int i, j;
  for (i = 3; i >= 0; i--) 
  {
    printf("%s\n", tab[i]);
  }
}

void creer_plateau(char tabPlateau[10][10])// Crée le plateau de jeu
{
  int i, j;
  for (i=0; i < 10; i++)
  {
    for (j=0; j < 10; j++) 
    {
      tabPlateau[i][j] = ' ';
    }
  }
}
void affiche_plateau(char tabPlateau[10][10])//Affiche le tabeau de jeu
{
  printf("\n  1   2   3   4   5   6   7   8   9   10  \n");
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("| %c ", tabPlateau[i][j]);
    }
    printf("|\n");
  }
}

int largeurPiece(char *piece[7][4][4],int nbPieceF, int orientationF) //Définit la largeur nécessaire pour placer une pièce
{
    int largeur=0, larg, i, j, ligne;
    for(j=0;j<4;j++)
    {   larg=0;
        for(i=0;i<4;i++){
          
           
            if (piece[nbPieceF][orientationF][j][i]=='*')
                {
                larg=larg+1;
                }
          }
      
            if(larg>largeur)
            {
                largeur=larg;
            }
        }
        
    
    
    return largeur;
}
    
int maxligne(char tabPlateau[10][10], int colonne_ml, int largeur, char* piece[4])//Définit la hauteur à laquelle peut être placé la prochaine pièce
{  
    int i=0,j=0, hauteur=9, h=0;
  
    for(j=colonne_ml; j<colonne_ml+largeur; j++)
    {
      int i=0;
      int h=0;
      while(tabPlateau[i][j]!='*' && i<10)
      {
        i++;
      }
      i--;
      while(piece[h][j-colonne_ml]==' ')
      {
          h++;
      }

      i=i+h;
      if(i<hauteur){
          hauteur=i;
      }
     
    }
    return hauteur;

}

int Occuper(char tabPlateau[10][10], char *piece[7][4][4], int nbPiece_O, int orientation_O, int ligne_O, int colonne_O) //Elle permet d
{
    int largeur,max, i;
    largeur=largeurPiece(piece, nbPiece_O,  orientation_O);
    max=maxligne(tabPlateau, colonne_O, largeur, piece[nbPiece_O][orientation_O]);
    return max;
  
}


int verif_place(int colonnevp, char *piece[7][4][4],int nbPieceF, int orientationF){//Il vérifie si il y reste assez de place dans le tableau pour y mettre toute la pièce
    int nb=0, place;
    place=10-colonnevp+1;
    for (int ligne=0;ligne<4;ligne++){
        for (int i=0;i<4;i++){
            if(piece[nbPieceF][orientationF][ligne][i]=='*'){
                nb=nb+1;
                }
            else{
                if(piece[nbPieceF][orientationF][ligne][i+1]=='*'){
                    nb=nb+1;
                }
            }
        }
        if(nb>place){
                return 1;
            }
            nb=0;
     }
    return 0;
}


int Suppligne(char tabPlateau[10][10], int score)// Supprime une ligne lorsqu'elle est remplie
{ 
  int j, l,k, supp=0, ligne_Sp=9;
  int compt=0;
  while(ligne_Sp>0)
  {
    supp=0;
    for(j=0; j<10; j++)
    {
      if(tabPlateau[ligne_Sp][j]=='*')
      {
        supp++;
      }
      
    }
    
    if(supp==10)
    { 
      compt++;
      for(l=ligne_Sp; l>0; l--)
      {
        for(k=0; k<10; k++)
          {
            tabPlateau[l][k]=tabPlateau[l-1][k];
          }
      }
    }
    if (supp!=10){
        ligne_Sp--;
        }
  }
  if(compt==1)
  {
    score=score+40;
  }
  if(compt==2)
  {
    score=score+100;
  }
  if(compt==3)
  {
    score=score+300;
  }
  if(compt==4)
  {
    score=score+1200;
  }
  printf("%c",tabPlateau[ligne_Sp][k]);
  printf("score=%d", score);
  return score;
 
}


int placerPiece(char tabPlateau[10][10], char *piece[7][4][4],int nbPieceF, int orientationF, int score)//place une pièce dans le tableau
{
    int colonnepP, j, ligne=0, verif, max, supp, a, b;
    srand(time(NULL));
    unsigned long t1=getTimeMicrosec();
    a=t1;
    do
      {
         printf("Dans quelle colonne voulez-vous jouer?");
        scanf("%d",&colonnepP);
        buffer();
       unsigned long t2=getTimeMicrosec();
        b=t2;
      } while(colonnepP<1 || colonnepP>10);
      
     if (b-a>(15*1000000))
     {
        printf("Vous avez mis trop de temps\n");
        colonnepP=rand()%10;
    
      }
 
    
    verif=verif_place(colonnepP,piece , nbPieceF, orientationF);
    while(verif==1)
    {
      printf("\nVous ne pouvez pas jouer dans cette colonne\n");
      unsigned long t1=getTimeMicrosec();
      printf("\nDans quelle colonne voulez-vous jouer?\n"); 
      scanf("%d",&colonnepP);
      buffer();
      unsigned long t2=getTimeMicrosec();
      if (t2-t1>(15*1000000))
      {
        printf("Vous avez mis trop de temps\n");
        colonnepP=rand()%10;
    
      }
      verif=verif_place(colonnepP, piece, nbPieceF, orientationF);
    }
    colonnepP--;
    max=Occuper(tabPlateau, piece, nbPieceF, orientationF, ligne, colonnepP);
    for(j=max;j>max-4;j--)
    {
        for(int k=0; k<4; k++)
        {    
            if(piece[nbPieceF][orientationF][ligne][k]=='*')
            {
                tabPlateau[j][colonnepP]=piece[nbPieceF][orientationF][ligne][k];
            }
           colonnepP++;
        }
        ligne++;
        colonnepP=colonnepP-4;
            
    }
    score=score+10;
    score=Suppligne(tabPlateau, score);
    printf("%c", tabPlateau[j][colonnepP]);
    return score;
    
}


void jeu(char tabPlateau[10][10], char *tabPiece[7][4][4], int score)//Permet de continuer la partie
{
  int scoreF=0;
  do 
    {
      int nbPiece, orientation, i, a, b;
      srand(time(NULL));
      nbPiece = rand() % 7;
      for(i=0; i<4 ; i++)
        {
          printf("\n%d\n",i+1);
          affiche_piece(tabPiece[nbPiece][i]);
        }
      unsigned long t1=getTimeMicrosec();
      a=t1;  
      do
        {
        printf("\nChoisissez l'orientation de la pièce: ");
        scanf("%d", &orientation);
        buffer();
        unsigned long t2=getTimeMicrosec();
         b=t2;
        }while(orientation<1 || orientation>4 );
      if (b-a>(15*1000000))
        {
          printf("Vous avez mis trop de temps\n");
          orientation=rand()%4;
        }
      orientation=orientation-1;
      score=placerPiece(tabPlateau, tabPiece, nbPiece, orientation, score);
      affiche_plateau(tabPlateau);
      for(i=0; i<10;i++)
        {
          if(tabPlateau[0][i]=='*')
            {
              scoreF++;
            }
        }
    }
    while(scoreF<1); 
    affiche_plateau(tabPlateau);
  
}
