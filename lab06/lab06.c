#include "lab06.h"
#include <stdlib.h>
#include <stdio.h>

node* criar(int chaves, node* list) {
    int i;
    node* aux;
    list = malloc(1 * sizeof(node)); //aloca dinamicamente o espaço para o primeiro registro
    list->valor = 1;
    list->contador = 0;
    list->next = NULL;
    aux = list;
    for (i = 1; i < chaves; i++) {
        aux->next = malloc(1 * sizeof(node));
        aux->next->valor = i + 1; //o valor do registro é a sua ordem no inicio, quando a ista é criada
        aux->next->contador = 0;
        aux = aux->next;
    }
    aux->next = NULL; //o ultimo valor sempre aponta para vazio
    aux = list;
    return list;
}

node* resetar(node* list) { //reseta os valores dos registros em ordem
    int i = 1;
    node* aux;
    aux = list;
    while(aux != NULL) {
        aux->valor = i;
        aux = aux->next;
        i++;
    }
    return list;
}

void limpar(node* list) { //da free nas memorias alocadas da lista encadeada
    node* aux;
    aux = list;
    while (aux != NULL) {
        free(aux);
        aux = aux->next;
    }
}

void imprimir(node** list) {
    node* aux = (*list);
    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->next;
    }
    printf("\n");
}

int MTF(int chaves, int numero, node* list, node** ponteiro) { //passa a lista por referencia
    if ((*ponteiro)->valor == numero) { //caso o registro seja a primeira posicao da lista
        return 1;
    }
    else{
        node* aux = list;
        node* anterior = list;
        int custo = 1;
        int i;
        for(i = 1; i < chaves + 1; i++) { //encontra o registro e faz a troca
            if(aux->valor == numero) {
                anterior->next = aux->next;
                aux->next = list;
                (*ponteiro) = aux;
                return custo;
            }
            anterior = aux;
            aux = aux->next;
            custo++; //considera mais um nó visitado
        }
    }
}

int TR (int chaves, int numero, node* list, node** ponteiro) { //passa a lista por referencia
    if ((*ponteiro)->valor == numero) { //caso o registro seja a primeira posicao da lista
        return 1;
    }
    else if (list->next->valor == numero) { //caso o registro seja a segunda posicao da lista
        node* aux = list->next;
        node* anterior = list;
        anterior->next = aux->next;
        aux->next = anterior;
        (*ponteiro) = aux;
        return 2;
    }
    else {
        node* aux = list->next->next;
        node* anterior = list->next;
        node* antesanterior = list;
        int i;
        int custo = 3;
        for (i = 3; i < chaves + 1; i++) { //encontra o registro e faz a troca
            if(aux->valor == numero) {
                antesanterior->next = aux;
                anterior->next = aux->next;
                aux->next = anterior;
                return custo;
            }
            antesanterior = anterior;
            anterior = aux;
            custo++; //considera mais um nó visitado
            aux = aux->next;
        }
    }
}

int C (int numero, node* list, int chaves, node** ponteiro) { //passa a lista por referencia
    node* aux = list->next;
    node* anterior = list;
    node* testador = list->next;
    node* anteriortestador = list;
    int i;
    int custo = 1;
    if ((*ponteiro)->valor == numero) { //caso seja a primeira posicao da lista
        list->contador ++;
        return 1;
    }
    else{
        for (i = 1; i < chaves; i++) { //loop que incrementa o contador do registro escolhido e guarda seu endereço e o do registro anterior
            if(aux->valor == numero) {
                aux->contador ++;
                custo++;
                break;
            }
            anterior = aux;
            aux = aux->next;
            custo++; //considera mais um nó visitado
        }
        if(anteriortestador->contador <= aux->contador) { //se o elemento escolhido tiver que ir para a primeira posicao
            anterior->next = aux->next;
            aux->next = anteriortestador;
            (*ponteiro) = aux;
            return custo;
        }
        else if (anterior->contador > aux->contador) { //se nao for preciso trocar de posicao
            return custo;
        }
        else{ //caso contrario, encontra quem deve substituir quem
            for (i = 1; i < chaves; i++) {
                if(testador->contador <= aux->contador) {
                    anterior->next = aux->next;
                    aux->next = testador;
                    anteriortestador->next = aux;
                    return custo;
                }
                anteriortestador= testador;
                testador = testador->next;
            }
        }
    }
}