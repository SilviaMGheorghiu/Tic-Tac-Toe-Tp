//
// Created by User on 6/2/2026.
//
#include <stdio.h>
#include "ai3.h"
#include "ai2.h"
#include <limits.h>
#include "game.h"

int evalueaza() {

    for(int i = 0; i < 3; i++) {

        if(tabla[i][0] == tabla[i][1] &&
           tabla[i][1] == tabla[i][2]) {

            if(tabla[i][0] == 'O')
                return 10;

            if(tabla[i][0] == 'X')
                return -10;
           }

        if(tabla[0][i] == tabla[1][i] &&
           tabla[1][i] == tabla[2][i]) {

            if(tabla[0][i] == 'O')
                return 10;

            if(tabla[0][i] == 'X')
                return -10;
           }
    }

    if(tabla[0][0] == tabla[1][1] &&
       tabla[1][1] == tabla[2][2]) {

        if(tabla[0][0] == 'O')
            return 10;

        if(tabla[0][0] == 'X')
            return -10;
       }

    if(tabla[0][2] == tabla[1][1] &&
       tabla[1][1] == tabla[2][0]) {

        if(tabla[0][2] == 'O')
            return 10;

        if(tabla[0][2] == 'X')
            return -10;
       }

    return 0;
}

int maiExistaMutari() {

    for(int i = 0; i < dimensiune; i++)
        for(int j = 0; j < dimensiune; j++)
            if(tabla[i][j] != 'X' &&
               tabla[i][j] != 'O')
                return 1;

    return 0;
}

int minimax(int adancime, int esteMax) {

    int scor = evalueaza();

    if(scor == 10)
        return scor - adancime;

    if(scor == -10)
        return scor + adancime;

    if(!maiExistaMutari())
        return 0;

    if(esteMax) {

        int best = INT_MIN;

        for(int i = 0; i < dimensiune; i++) {
            for(int j = 0; j < dimensiune; j++) {

                if(tabla[i][j] != 'X' &&
                   tabla[i][j] != 'O') {

                    char backup = tabla[i][j];

                    tabla[i][j] = 'O';

                    int valoare =
                        minimax(adancime + 1, 0);

                    tabla[i][j] = backup;

                    if(valoare > best)
                        best = valoare;
                   }
            }
        }

        return best;
    }

    int best = INT_MAX;

    for(int i = 0; i < dimensiune; i++) {
        for(int j = 0; j < dimensiune; j++) {

            if(tabla[i][j] != 'X' &&
               tabla[i][j] != 'O') {

                char backup = tabla[i][j];

                tabla[i][j] = 'X';

                int valoare =
                    minimax(adancime + 1, 1);

                tabla[i][j] = backup;

                if(valoare < best)
                    best = valoare;
               }
        }
    }

    return best;
}

void mutareAI3() {

    if(dimensiune != 3) {
        mutareAI2();
        return;
    }

    int bestVal = INT_MIN;
    int bestLinie = -1;
    int bestColoana = -1;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            if(tabla[i][j] != 'X' &&
               tabla[i][j] != 'O') {

                char backup = tabla[i][j];

                tabla[i][j] = 'O';

                int moveVal = minimax(0, 0);

                tabla[i][j] = backup;

                if(moveVal > bestVal) {
                    bestLinie = i;
                    bestColoana = j;
                    bestVal = moveVal;
                }
               }
        }
    }

    tabla[bestLinie][bestColoana] = 'O';

    printf("AI HARD joaca perfect!\n");
}