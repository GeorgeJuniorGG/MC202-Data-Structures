#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab08.h"

int main () {
    char comando;
    int posicao, inicio, fim;
    double valor;
    int vazio = 1;
    registro* head = malloc(sizeof(registro));
    head->A = NULL;
    head->B = NULL;
    scanf("%c", &comando);
    while (comando != 't') {
        if (comando == 'p') {
            imprime(head, vazio);
        }
        else if (comando == 'v') {
            scanf("%d %d", &inicio, &fim);
            reverter(head, inicio, fim, &head);
        }
        else if (comando == 'i') {
            scanf("%d %lf", &posicao, &valor);
            inserir(head, valor, posicao, vazio, &head);
            vazio = 0;
        }
        scanf("%c", &comando);
    }
    liberar(head, vazio);
}