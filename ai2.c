//
// Created by User on 5/5/2026.
//

#include "ai2.h"
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "powerUp.h"

// cauta mutare castigatoare
int cautaMutare(char simbol) {
    for(int i = 0; i < dimensiune; i++) {
        for(int j = 0; j < dimensiune; j++) {

            if(tabla[i][j] != 'X' && tabla[i][j] != 'O') {

                char backup = tabla[i][j];
                tabla[i][j] = simbol;

                if(verificaCastigator()) {
                    tabla[i][j] = backup;
                    return i * dimensiune + j;
                }

                tabla[i][j] = backup;
            }
        }
    }
    return -1;
}

// verifica daca celula e libera
int liber(int i, int j) {
    return (tabla[i][j] != 'X' && tabla[i][j] != 'O');
}

void mutareAI2() {

    int poz;

    if(modSpecial && putereActiva) {

        for(int i = 0; i < dimensiune; i++) {
            for(int j = 0; j < dimensiune; j++) {

                if(tabla[i][j] == SIMBOL_SPECIAL) {

                    tabla[i][j] = 'O';

                    putereActiva = 0;
                    pozitieSpeciala = -1;

                    printf("AI MEDIU foloseste puterea speciala\n");
                    folosestePutereAI();

                    return;
                }
            }
        }
    }

    // castiga
    poz = cautaMutare('O');
    if(poz != -1) {
        tabla[poz / dimensiune][poz % dimensiune] = 'O';
        printf("AI MEDIU castiga\n");
        return;
    }

    // blocheaza
    poz = cautaMutare('X');
    if(poz != -1) {
        tabla[poz / dimensiune][poz % dimensiune] = 'O';
        printf("AI MEDIU blocheaza\n");
        return;
    }

    // centru
    if(dimensiune % 2 == 1) {
        int c = dimensiune / 2;
        if(liber(c, c)) {
            tabla[c][c] = 'O';
            printf("AI MEDIU ia centrul\n");
            return;
        }
    }

    //  colturi
    int colturi[4][2] = {
        {0,0},
        {0,dimensiune-1},
        {dimensiune-1,0},
        {dimensiune-1,dimensiune-1}
    };

    for(int k = 0; k < 4; k++) {
        int i = colturi[k][0];
        int j = colturi[k][1];

        if(liber(i,j)) {
            tabla[i][j] = 'O';
            printf("AI MEDIU ia colt\n");
            return;
        }
    }

    // random fallback
    int linie, coloana;
    do {
        int r = rand() % (dimensiune * dimensiune);
        linie = r / dimensiune;
        coloana = r % dimensiune;
    } while(!liber(linie, coloana));

    tabla[linie][coloana] = 'O';
    printf("AI MEDIU random\n");
}
