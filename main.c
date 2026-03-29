#include <stdio.h>
#include "game.h"

int main() {
    char jucator = 'X';

    initTabla();

    while(1) {
        afiseazaTabla();
        mutare(jucator);

        if(verificaCastigator()) {
            afiseazaTabla();
            printf("Jucatorul %c a castigat!\n", jucator);
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