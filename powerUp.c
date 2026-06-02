//
// Created by User on 6/2/2026.
//

#include "powerUp.h"
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int putereActiva = 0;
int pozitieSpeciala = -1;
int modSpecial = 0;
int putereAparuta = 0;

void genereazaPutere() {

    if(dimensiune != 3)
        return;

    if(!modSpecial)
        return;

    if(putereActiva)
        return;

    if(putereAparuta)
        return;

    int poz;

    do {
        poz = rand() % 9;
    }
    while(tabla[poz / 3][poz % 3] == 'X' ||
          tabla[poz / 3][poz % 3] == 'O');

    tabla[poz / 3][poz % 3] = SIMBOL_SPECIAL;

    pozitieSpeciala = poz;
    putereActiva = 1;
    putereAparuta = 1;

    printf("\n\033[1;32m*** A APARUT O PUTERE SPECIALA! ***\033[0m\n");
}

void folosestePutere(char jucator) {

    int poz;
    int rezultat;

    printf("\n");

    if(jucator == 'X')
        printf("\033[31mJucatorul X a activat PUTEREA SPECIALA!\033[0m\n");
    else
        printf("\033[34mJucatorul O a activat PUTEREA SPECIALA!\033[0m\n");

    while(1) {

        printf("Alege o pozitie ocupata pentru a o sterge (1-9): ");

        rezultat = scanf("%d", &poz);

        if(rezultat != 1) {

            printf("Input invalid!\n");

            while(getchar() != '\n');

            continue;
        }

        if(poz < 1 || poz > 9) {

            printf("Pozitie invalida!\n");
            continue;
        }

        int linie = (poz - 1) / 3;
        int coloana = (poz - 1) % 3;

        if(tabla[linie][coloana] != 'X' &&
           tabla[linie][coloana] != 'O') {

            printf("Pozitia nu este ocupata!\n");
            continue;
           }

        tabla[linie][coloana] = ' ';

        printf("\033[32mPiesa a fost stearsa!\033[0m\n");

        break;
    }
}

void folosestePutereAI() {

    // Prioritate 1: sterge centrul daca este X
    int c = dimensiune / 2;

    if(dimensiune == 3 && tabla[c][c] == 'X') {

        tabla[c][c] = ' ';

        printf("\033[32mAI a sters centrul!\033[0m\n");

        return;
    }

    // Prioritate 2: sterge un colt ocupat de X
    int colturi[4][2] = {
        {0,0},
        {0,dimensiune-1},
        {dimensiune-1,0},
        {dimensiune-1,dimensiune-1}
    };

    for(int k = 0; k < 4; k++) {

        int i = colturi[k][0];
        int j = colturi[k][1];

        if(tabla[i][j] == 'X') {

            tabla[i][j] = ' ';

            printf("\033[32mAI a sters un colt!\033[0m\n");

            return;
        }
    }

    // Prioritate 3: primul X gasit
    for(int i = 0; i < dimensiune; i++) {
        for(int j = 0; j < dimensiune; j++) {

            if(tabla[i][j] == 'X') {

                tabla[i][j] = ' ';

                printf("\033[32mAI a sters o piesa!\033[0m\n");

                return;
            }
        }
    }
}