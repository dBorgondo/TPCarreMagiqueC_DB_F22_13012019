extern void init(int Carre[TAILLE][TAILLE]);
extern int IsEmpty(tJeton *Jeton, int Carre[TAILLE][TAILLE]);
extern void corriger(tJeton *Jeton);
extern void avancerdroite(tJeton *Jeton);
extern void avancergauche(tJeton *Jeton);
extern void avancer(tJeton *Jeton, int Carre[TAILLE][TAILLE]);
extern void placer(tJeton Jeton, int Carre[TAILLE][TAILLE], int nSteps);
