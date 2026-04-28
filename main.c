#include <stdio.h>
#include "game.h"
#include "ai.h"
#include <stdlib.h>
#include <time.h>

int main() {
    char jucator = 'X';
    int dim;
    srand(time(NULL));

    printf("Alege dimensiunea tablei (3 sau 4): ");
    scanf("%d", &dim);

    if(dim != 3 && dim != 4) {
        printf("Dimensiune invalida! Se foloseste 3.\n");
        dim = 3;
    }

    int mod;

    printf("Alege modul de joc:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs AI\n");
    scanf("%d", &mod);

    if(mod != 1 && mod != 2) {
        printf("Mod invalid! Se foloseste Player vs Player.\n");
        mod = 1;
    }

    initTabla(dim);  // IMPORTANT: inițializează înainte

    // 👉 AICI pui ghidul
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
            afiseazaInstructiuni(dim);
        }
    }

    while(1) {
        afiseazaTabla();

        if(mod == 2 && jucator == 'O') {
            mutareAI();
        } else {
            mutare(jucator);
        }

        if(verificaCastigator()) {
            afiseazaTabla();

            if (jucator == 'X')
                printf("Jucatorul \033[31m%c\033[0m a castigat!\n", jucator);
            else if (jucator == 'O')
                printf("Jucatorul \033[34m%c\033[0m a castigat!\n", jucator);
            break;
        }

        if(remiza()) {
            afiseazaTabla();
            printf("Remiza!\n");
            break;
        }

        jucator = (jucator == 'X') ? 'O' : 'X';
    }

    return 0;
}