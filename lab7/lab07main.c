#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab07.h"

int main () {
    char comando[13];
    int ocupados = 0;
    int loop = 1;
    int numero;
    vetdinamico* vetor = malloc(1 * sizeof(vetdinamico));
    vetor->inicio = 0;
    vetor->fim = 0;
    vetor->tamanho = 2;
    vetor->vetor = malloc(2 * sizeof(int));
    scanf("%s", &comando);
    while (loop) {
        if(strstr(comando, "insert-first")) {
            scanf("%d", &numero);
            ocupados++;
            if (ocupados == vetor->tamanho) { //caso precise redimensionar o vetor
                aumenta(vetor->tamanho, vetor);
            }
            insertfirst(numero, vetor, ocupados);
        }

        else if (strstr(comando, "remove-first")) {
            if(ocupados != 0) { //nao pode remover se nao tiver elementos
                ocupados--;
                if(ocupados == vetor->tamanho/4) { //caso precise redimensionar o vetor
                    reduz(vetor->tamanho, vetor);
                }
                removefirst (vetor);
            }
        }

        else if (strstr(comando, "print-first")) {
            printfirst(vetor, ocupados);
        }

        else if (strstr(comando, "insert-last")) {
            scanf("%d", &numero);
            ocupados++;
            if (ocupados == vetor->tamanho) { //caso precise redimensionar o vetor
                aumenta(vetor->tamanho, vetor);
            }
            insertlast(numero, vetor, ocupados);
        }

        else if (strstr(comando, "remove-last")) {
            if(ocupados != 0) { //nao pode remover se nao tiver elementos
                ocupados--;
                if(ocupados == vetor->tamanho/4) { //caso precise redimensionar o vetor
                    reduz(vetor->tamanho, vetor);
                }
                removelast(vetor);
            }
        }

        else if (strstr (comando, "print-last")) {
            printlast(vetor, ocupados);
        }

        else if (strstr (comando, "is-empty")) {
            isempty(ocupados);
        }

        else if (strstr(comando, "exit")) {
            loop = kill();
        }

        //imprime (vetor->tamanho, vetor);
        //printf("Inicio = %d e Fim = %d\n", vetor->inicio, vetor->fim);
        scanf("%s", &comando);
    }
    free(vetor->vetor);
    free(vetor);
}