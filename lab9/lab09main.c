#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab09.h"

int main() {
    char comando[10];
    int numero;
    noarvore* pai = criar();
    scanf("%s", comando);
    while (strcmp (comando, "terminar")) {
        if (!strcmp("inserir", comando)) {
            scanf("%d", &numero);
            pai->ocupados ++;
            inserir (numero, pai);
        }
        else if (!strcmp ("buscar", comando)) {
            scanf("%d", &numero);
            buscar (numero, pai);
        }
        else if (!strcmp ("pos-ordem", comando)) {
            posordem (pai);
            printf("\n");
        }
        else if (!strcmp ("pre-ordem", comando)) {
            preordem (pai);
            printf("\n");
        }
        else if (!strcmp ("em-ordem", comando)) {
            emordem (pai);
            printf("\n");
        }
        else if (!strcmp ("largura", comando)) {
            largura (pai);
            printf("\n");
        }
        scanf("%s", comando);
    }
    liberar(pai);
}