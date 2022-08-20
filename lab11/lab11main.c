#include <stdio.h>
#include <stdlib.h>
#include "lab11.h"

int main () {
    hashtable* hashing = malloc(sizeof(hashtable));
    inicializar (hashing);
    char comando;
    int sucesso;
    unsigned long valor;
    char* cadeia = malloc(251 * sizeof(char));
    scanf("%c", &comando);
    while (comando != 'f') {  
        if (comando == 'i') {
            scanf(" %s", cadeia);
            valor = djb2(cadeia);  
            inserir (hashing, valor, cadeia);
        }
        else if (comando == 'b') {
            scanf(" %s", cadeia);
            valor = djb2(cadeia);  
            sucesso = buscar (hashing, valor, cadeia);
            if (sucesso == -1) {
                printf ("%s nao encontrada\n", cadeia);
            }
            else {
                printf("%s encontrada, id %d\n", cadeia, hashing->id[sucesso]);
            }
        }
        else if (comando == 'r') {
            scanf(" %s", cadeia);
            valor = djb2(cadeia);          
            remover (hashing, valor, cadeia);
        }
        scanf("%c", &comando);
    }
    for (sucesso = 0; sucesso < 6521; sucesso ++) {
        free (hashing->tabela[sucesso]);
    }
    free (hashing);
    free (cadeia);
}