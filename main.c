#include <stdio.h>
#include "game.h"

int main() {
    char jucator = 'X';
    int dim;

    printf("Alege dimensiunea tablei (3 sau 4): ");
    scanf("%d", &dim);

    if(dim != 3 && dim != 4) {
        printf("Dimensiune invalida! Se foloseste 3.\n");
        dim = 3;
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
        mutare(jucator);

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