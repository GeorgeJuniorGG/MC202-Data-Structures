#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab10.h"

int main() {
    char comando[18];
    int numero;
    int numero2;
    noarvore* pai = criar();
    noarvore* retorno;
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
        else if (!strcmp ("remover", comando)) {
            scanf("%d", &numero);
            remover(&pai, pai, numero);
        }
        else if (!strcmp ("maximo", comando)) {
            retorno = maximo (pai);
            if (retorno == NULL) {
                printf("vazia\n");
            }
            else {
                printf("%d\n", retorno->valor);
            }
        }
        else if (!strcmp ("minimo", comando)) {
            retorno = minimo (pai);
            if (retorno == NULL) {
                printf("vazia\n");
            }
            else {
                printf("%d\n", retorno->valor);
            }
        }
        else if (!strcmp ("sucessor", comando)) {
            scanf("%d", &numero);
            retorno = sucessor(pai, numero);
            if (retorno == NULL) {
                printf("nao ha\n");
            }
            else {
                printf("%d\n", retorno->valor);
            }
        }
        else if (!strcmp ("predecessor", comando)) {
            scanf("%d", &numero);
            retorno = predecessor(pai, numero);
            if (retorno == NULL) {
                printf ("nao ha\n");
            }
            else {
                printf ("%d\n", retorno->valor);
            }
        }
        else if (!strcmp ("buscar-intervalo", comando)) {
            scanf("%d %d", &numero, &numero2);
            numero = intervalo(pai, numero, numero2, 0);
            if (!numero) {
                printf("nenhuma");
            }
            printf("\n");
        }
        scanf("%s", comando);
    }
    liberar(pai);
}