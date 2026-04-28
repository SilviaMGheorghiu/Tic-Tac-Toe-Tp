#include <stdio.h>
#include "game.h"
#include "ai.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int dim;
    srand(time(NULL));

    printf("Alege dimensiunea tablei (3 sau 4): ");
    scanf("%d", &dim);

    if(dim != 3 && dim != 4) {
        printf("Dimensiune invalida! Se foloseste 3.\n");
        dim = 3;
    }

    initTabla(dim);
    afiseazaInstructiuni(dim);

    int mod;

    printf("Alege modul de joc:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs AI\n");
    scanf("%d", &mod);

    if(mod != 1 && mod != 2) {
        printf("Mod invalid! Se foloseste Player vs Player.\n");
        mod = 1;
    }

    int modScor;

    printf("Alege tipul de joc:\n");
    printf("1. Joc simplu\n");
    printf("2. Joc cu scor (best of 3)\n");
    scanf("%d", &modScor);

    if(modScor != 1 && mod != 2) {
        printf("Mod invalid! Se foloseste joc simplu.\n");
        modScor = 1;
    }

    if(modScor == 2) {
        joacaMeci(mod, dim);
    }
    else {
        initTabla(dim);
        joacaRunda(mod);
    }

    return 0;
}