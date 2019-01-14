#include "values.h"
#include "Vues.h"

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

