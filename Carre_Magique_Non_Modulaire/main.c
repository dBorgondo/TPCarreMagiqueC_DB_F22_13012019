#include <stdio.h>
#include <stdlib.h>
#define TAILLE 6
#define INIX 2
#define INIY 3

typedef struct tJeton
{
    int nX;
    int nY;
}tJeton;

void init(int Carre[TAILLE][TAILLE]);
int IsEmpty(tJeton *Jeton, int Carre[TAILLE][TAILLE]);
void corriger(tJeton *Jeton);
void avancerdroite(tJeton *Jeton);
void avancergauche(tJeton *Jeton);
void avancer(tJeton *Jeton, int Carre[TAILLE][TAILLE]);
void placer(tJeton Jeton, int Carre[TAILLE][TAILLE], int nSteps);
void affichage(int Carre[TAILLE][TAILLE]);

int main()
{
    tJeton Jeton={INIX,INIY};
    int Carre[TAILLE][TAILLE];
    int nSteps=2; //On commence le compte à 2 car le 1 déjà créé lors de l'initialisation
    init(Carre);
    affichage(Carre);
    while (nSteps<=((TAILLE-1)*(TAILLE-1))){
        avancer(&Jeton,Carre);
        placer(Jeton,Carre,nSteps);
        nSteps++;
        affichage(Carre);
    }
    return 0;
}
/*
BUT : Initaliser le carre
ENTREES : Carre
SORTIES : Carre Initialisée
*/
void init(int Carre[TAILLE][TAILLE]){
    int nCptx=0;
    int nCpty=0;
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            Carre[nCptx][nCpty]=0;
        }
    }
    Carre[INIX][INIY]=1;
}

/*
BUT : Detecter si une case est vide
ENTREES : Jeton, Carre
SORTIES : 1 si case vide, 0 si case remplie
*/
int IsEmpty(tJeton *Jeton, int Carre[TAILLE][TAILLE]){
    if (Carre[Jeton->nX][Jeton->nY]==0){
        return 1;
    }
    else return 0;
}

/*
BUT : Corriger les coordonnées du jeton si elles sortent du tableau
ENTREES : Jeton
SORTIES : Jeton avec coordonées corriger
*/

void corriger(tJeton *Jeton){
    if (Jeton->nX>(TAILLE-1)){
        Jeton->nX-=(TAILLE-1);
    }
    else if (Jeton->nX<1){
                Jeton->nX+=(TAILLE-1);
            }

    if (Jeton->nY>(TAILLE-1)){
        Jeton->nY-=(TAILLE-1);
    }
    else if (Jeton->nY<1){
                Jeton->nY+=(TAILLE-1);
            }
}

/*
BUT : Avancer les coordonée d'un jeton en haut à droite
ENTREES : Jeton
SORTIES : Jeton avec coordonées avancée en haut à droite
*/

void avancerdroite(tJeton *Jeton){
    Jeton->nX-=1;
    Jeton->nY+=1;
}

/*
BUT : Avancer les coordonée d'un jeton en haut à gauche
ENTREES : Jeton
SORTIES : Jeton avec coordonées avancée en haut à gauche
*/

void avancergauche(tJeton *Jeton){
    Jeton->nX-=1;
    Jeton->nY-=1;
}

/*
BUT : Avancer les coordonée d'un jeton
ENTREES : Jeton, Carre
SORTIES : Jeton avec coordonées avancée
*/

void avancer(tJeton *Jeton, int Carre[TAILLE][TAILLE]){
    avancerdroite(Jeton);
    corriger(Jeton);
    if(IsEmpty(Jeton,Carre)==0)
    {
        avancergauche(Jeton);
        corriger(Jeton);
    }
}

/*
BUT : Placer le nombre(step) correspondant à la case du jeton
ENTREES : Jeton, Step
SORTIES : Tableau avec une cellule remplie en plus
*/

void placer(tJeton Jeton, int Carre[TAILLE][TAILLE], int nSteps){
    Carre[Jeton.nX][Jeton.nY]=nSteps;
}

/*
BUT : Afficher le Carre
ENTREES : Carre
SORTIES : Affichage Carre
*/

void affichage(int Carre[TAILLE][TAILLE]){
    int nCptx;
    int nCpty;
    for(nCptx=1;nCptx<TAILLE;nCptx++){
        for(nCpty=1;nCpty<TAILLE;nCpty++){
                printf("|%d|",Carre[nCptx][nCpty]);
            }
        printf("\n");
        }
    printf("\n");
}
