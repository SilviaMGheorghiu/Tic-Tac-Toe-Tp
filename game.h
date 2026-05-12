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
extern char tabla[MAX][MAX];
extern int dimensiune;
int verificaCastigator();
int remiza();
void mutare(char jucator);
void textInstructiuni(int dim);
void afiseazaInstructiuni(int dim);
void joacaMeci(int mod, int dim);
char joacaRunda(int mod);

//AI
extern int nivelAI;

#endif //X_SI_0_GAME_H