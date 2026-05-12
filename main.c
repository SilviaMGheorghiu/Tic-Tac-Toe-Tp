#include <stdio.h>
#include "game.h"
#include "ai.h"
#include <stdlib.h>
#include <time.h>

int nivelAI;

int main() {

    srand(time(NULL));

    while(1)
    {
        int dim;

        printf("\033[33mAlege dimensiunea tablei (3 sau 4): \033[0m");
        scanf("%d", &dim);

        if(dim != 3 && dim != 4) {
            printf("Dimensiune invalida! Se foloseste 3.\n");
            dim = 3;
        }

        initTabla(dim);
        afiseazaInstructiuni(dim);

        int mod;

        printf("\033[33mAlege modul de joc:\033[0m\n");
        printf("1. Player vs Player\n");
        printf("2. Player vs AI\n");
        scanf("%d", &mod);

        if(mod != 1 && mod != 2) {
            printf("Mod invalid! Se foloseste Player vs Player.\n");
            mod = 1;
        }

        nivelAI = 1;

        if(mod == 2) {
            printf("\033[33mAlege nivel AI:\033[0m\n");
            printf("1. Usor\n");
            printf("2. Mediu\n");
            scanf("%d", &nivelAI);

            if(nivelAI != 1 && nivelAI != 2) {
                printf("Nivel invalid! Se foloseste usor.\n");
                nivelAI = 1;
            }
        }

        int modScor;

        printf("\033[33mAlege tipul de joc:\033[0m\n");
        printf("1. Joc simplu\n");
        printf("2. Joc cu scor (best of 3)\n");
        scanf("%d", &modScor);

        if(modScor != 1 && modScor != 2) {
            printf("Mod invalid! Se foloseste joc simplu.\n");
            modScor = 1;
        }

        char optiuneFinal;

        do {

            if(modScor == 2) {
                joacaMeci(mod, dim);
            }
            else {
                initTabla(dim);
                joacaRunda(mod);
            }

            printf("\n\033[33mAlege optiune:\033[0m\n");
            printf("R - Replay (aceleasi setari)\n");
            printf("M - Meniu principal\n");
            printf("Altceva - Iesire\n");

            scanf(" %c", &optiuneFinal);

            if(optiuneFinal != 'R' && optiuneFinal != 'r' &&
               optiuneFinal != 'M' && optiuneFinal != 'm') {

                printf("Iesire din joc...\n");
                return 0;
               }

        } while(optiuneFinal == 'R' || optiuneFinal == 'r');

        if(optiuneFinal == 'M' || optiuneFinal == 'm') {
            continue;
        }
    }
    return 0;
}