//
// Created by User on 3/29/2026.
//

#include <stdio.h>
#include "game.h"

char tabla[3][3];

// Initializare tabla
void initTabla() {
    char c = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tabla[i][j] = c++;
        }
    }
}

// Afisare tabla
void afiseazaTabla() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tabla[i][0], tabla[i][1], tabla[i][2]);
        if(i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Verifica castigator
int verificaCastigator() {
    for(int i = 0; i < 3; i++) {
        if(tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2])
            return 1;
        if(tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i])
            return 1;
    }

    if(tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2])
        return 1;
    if(tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0])
        return 1;

    return 0;
}

// Verifica remiza
int remiza() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(tabla[i][j] != 'X' && tabla[i][j] != 'O')
                return 0;
    return 1;
}

// Mutare jucator
void mutare(char jucator) {
    int poz;
    printf("Jucator %c, alege o pozitie (1-9): ", jucator);
    scanf("%d", &poz);

    int linie = (poz - 1) / 3;
    int coloana = (poz - 1) % 3;

    if(poz < 1 || poz > 9) {
        printf("Pozitie invalida!\n");
        mutare(jucator);
        return;
    }

    if(tabla[linie][coloana] != 'X' && tabla[linie][coloana] != 'O') {
        tabla[linie][coloana] = jucator;
    } else {
        printf("Pozitie ocupata!\n");
        mutare(jucator);
    }
}