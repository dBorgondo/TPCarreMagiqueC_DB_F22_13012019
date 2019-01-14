#include <stdio.h>
#include <stdlib.h>
#include "values.h"
#include "Vues.h"
#include "Logique.h"


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
