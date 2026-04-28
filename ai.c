//
// Created by User on 4/28/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int poateCastiga(char simbol) {
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

void mutareAI() {
    int poz;

    // 1. incearca sa castige
    poz = poateCastiga('O');
    if(poz != -1) {
        int linie = poz / dimensiune;
        int coloana = poz % dimensiune;
        tabla[linie][coloana] = 'O';
        printf("AI castiga!\n");
        return;
    }

    // 2. blocheaza jucatorul
    poz = poateCastiga('X');
    if(poz != -1) {
        int linie = poz / dimensiune;
        int coloana = poz % dimensiune;
        tabla[linie][coloana] = 'O';
        printf("AI blocheaza!\n");
        return;
    }

    // 3. random
    int linie, coloana;
    do {
        int r = rand() % (dimensiune * dimensiune);
        linie = r / dimensiune;
        coloana = r % dimensiune;
    } while(tabla[linie][coloana] == 'X' || tabla[linie][coloana] == 'O');

    tabla[linie][coloana] = 'O';
    printf("AI mutare random\n");
}