#include "values.h"
#include "Logique.h"

/*
BUT : Initaliser le carre
ENTREES : Carre
SORTIES : Carre Initialis�e
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
BUT : Corriger les coordonn�es du jeton si elles sortent du tableau
ENTREES : Jeton
SORTIES : Jeton avec coordon�es corriger
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
BUT : Avancer les coordon�e d'un jeton en haut � droite
ENTREES : Jeton
SORTIES : Jeton avec coordon�es avanc�e en haut � droite
*/

void avancerdroite(tJeton *Jeton){
    Jeton->nX-=1;
    Jeton->nY+=1;
}

/*
BUT : Avancer les coordon�e d'un jeton en haut � gauche
ENTREES : Jeton
SORTIES : Jeton avec coordon�es avanc�e en haut � gauche
*/

void avancergauche(tJeton *Jeton){
    Jeton->nX-=1;
    Jeton->nY-=1;
}

/*
BUT : Avancer les coordon�e d'un jeton
ENTREES : Jeton, Carre
SORTIES : Jeton avec coordon�es avanc�e
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
BUT : Placer le nombre(step) correspondant � la case du jeton
ENTREES : Jeton, Step
SORTIES : Tableau avec une cellule remplie en plus
*/

void placer(tJeton Jeton, int Carre[TAILLE][TAILLE], int nSteps){
    Carre[Jeton.nX][Jeton.nY]=nSteps;
}

