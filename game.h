//
// Created by User on 3/29/2026.
//

#ifndef X_SI_0_GAME_H
#define X_SI_0_GAME_H

#define MAX 4

extern char tabla[MAX][MAX];
extern int dimensiune;

void initTabla(int dim);
void afiseazaTabla();
int verificaCastigator();
int remiza();
void mutare(char jucator);
void afiseazaInstructiuni(int dim);

#endif //X_SI_0_GAME_H