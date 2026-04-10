//
// Created by User on 3/29/2026.
//

#include <stdio.h>
#include "game.h"

char tabla[MAX][MAX];
int dimensiune;

// Initializare tabla
void initTabla(int dim) {
    dimensiune = dim;
    char c = '1';

    for(int i = 0; i < dimensiune; i++) {
        for(int j = 0; j < dimensiune; j++) {
            tabla[i][j] = c++;
        }
    }
}

// Afisare tabla
void afiseazaTabla() {
    printf("\n");

    for(int i = 0; i < dimensiune; i++) {
        for(int j = 0; j < dimensiune; j++) {
            if(tabla[i][j] == 'X')
                printf("\033[31m %c \033[0m", tabla[i][j]); // rosu
            else if(tabla[i][j] == 'O')
                printf("\033[34m %c \033[0m", tabla[i][j]); // albastru
            else
                printf("   ");
            if(j < dimensiune - 1) printf("|");
        }
        printf("\n");

        if(i < dimensiune - 1) {
            for(int k = 0; k < dimensiune; k++) {
                printf("---");
                if(k < dimensiune - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Verifica castigator
int verificaCastigator() {
    // linii
    for(int i = 0; i < dimensiune; i++) {
        int ok = 1;
        for(int j = 1; j < dimensiune; j++) {
            if(tabla[i][j] != tabla[i][0])
                ok = 0;
        }
        if(ok) return 1;
    }

    // coloane
    for(int j = 0; j < dimensiune; j++) {
        int ok = 1;
        for(int i = 1; i < dimensiune; i++) {
            if(tabla[i][j] != tabla[0][j])
                ok = 0;
        }
        if(ok) return 1;
    }

    // diagonala principala
    int ok = 1;
    for(int i = 1; i < dimensiune; i++) {
        if(tabla[i][i] != tabla[0][0])
            ok = 0;
    }
    if(ok) return 1;

    // diagonala secundara
    ok = 1;
    for(int i = 1; i < dimensiune; i++) {
        if(tabla[i][dimensiune - i - 1] != tabla[0][dimensiune - 1])
            ok = 0;
    }
    if(ok) return 1;

    return 0;
}

// Remiza
int remiza() {
    for(int i = 0; i < dimensiune; i++)
        for(int j = 0; j < dimensiune; j++)
            if(tabla[i][j] != 'X' && tabla[i][j] != 'O')
                return 0;
    return 1;
}

// Mutare
void mutare(char jucator) {
    int poz;
    int rezultat;

    if (jucator == 'X')
        printf("Jucator \033[31m%c\033[0m , alege o pozitie (1-%d): ", jucator, dimensiune * dimensiune);
    else if (jucator == 'O')
        printf("Jucator \033[34m%c\033[0m , alege o pozitie (1-%d): ", jucator, dimensiune * dimensiune);

    rezultat = scanf("%d", &poz);

    // daca NU a citit un numar
    if (rezultat != 1) {
        printf("Input invalid! Introdu un numar.\n");

        // curata bufferul
        while(getchar() != '\n');

        mutare(jucator);
        return;
    }

    if(poz < 1 || poz > dimensiune * dimensiune) {
        printf("Pozitie invalida!\n");
        mutare(jucator);
        return;
    }

    int linie = (poz - 1) / dimensiune;
    int coloana = (poz - 1) % dimensiune;

    if(tabla[linie][coloana] != 'X' && tabla[linie][coloana] != 'O') {
        tabla[linie][coloana] = jucator;
    } else {
        printf("Pozitie ocupata!\n");
        mutare(jucator);
    }
}

// Guide pt 4x4
void afiseazaInstructiuni(int dim) {
    printf("\n--------------- Istructiunii ----------------");
    printf("\n 1. Fiecare loc gol este o pozitie (1-%d)", dim*dim);
    printf("\n 2. Pentru a juca se introduce pozitia (1-%d)", dim*dim);
    printf("\n---------------------------------------------\n\n");
}