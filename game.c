//
// Created by User on 3/29/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "ai.h"

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

// Guide
void textInstructiuni(int dim) {
    printf("\n--------------- Istructiunii ----------------");
    printf("\n 1. Fiecare loc gol este o pozitie (1-%d)", dim*dim);
    printf("\n 2. Pentru a juca se introduce pozitia (1-%d)", dim*dim);
    printf("\n 3. Pentru optiunea AI jucatorul va fi \033[31mX\033[0m");
    printf("\n---------------------------------------------\n\n");
}

void afiseazaInstructiuni(int dim){
    char raspuns;

    if(dim) {
        do {
            printf("Vrei sa vezi instructiuni? (Y/N): ");
            scanf(" %c", &raspuns);

            if(raspuns != 'Y' && raspuns != 'y' &&
                raspuns != 'N' && raspuns != 'n') {
                printf("Te rog introdu doar Y sau N!\n");
                }

        } while(raspuns != 'Y' && raspuns != 'y' &&
            raspuns != 'N' && raspuns != 'n');

        if(raspuns == 'Y' || raspuns == 'y') {
            textInstructiuni(dim);
        }
    }
}

char joacaRunda(int mod) {

    char jucator = 'X';

    while(1) {

        afiseazaTabla();

        if(mod == 2 && jucator == 'O')
            mutareAI();
        else
            mutare(jucator);

        if(verificaCastigator()) {
            afiseazaTabla();
            if (jucator == 'X')
                printf("Castigator: \033[31m%c\033[0m\n", jucator);
            else if (jucator == 'O')
                printf("Castigator: \033[34m%c\033[0m\n", jucator);

            return jucator;
        }

        if(remiza()) {
            afiseazaTabla();
            printf("Remiza!\n");
            return 'D';
        }

        jucator = (jucator == 'X') ? 'O' : 'X';
    }
}

void joacaMeci(int mod, int dim) {

    int scorX = 0;
    int scorO = 0;
    int runda = 1;

    while(1) {

        printf("\n=== RUNDA %d ===\n", runda);

        initTabla(dim);

        char rezultat = joacaRunda(mod);

        if(rezultat == 'X') scorX++;
        else if(rezultat == 'O') scorO++;

        printf("Scor: \033[31mX\033[0m = %d | \033[34mO\033[0m = %d\n", scorX, scorO);

        // conditie best of 3
        if(scorX == 2 || scorO == 2) {

            printf("\n=== MECI TERMINAT ===\n");

            if(scorX > scorO)
                printf("Castigator final: \033[31mX\033[0m\n");
            else
                printf("Castigator final: \033[31mO\033[0m\n");

            break;
        }

        runda++;
    }
}