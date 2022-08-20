#include <stdio.h>
#include <stdlib.h>
#include "lab09.h"

noarvore* criar () {
    noarvore* no = malloc(sizeof(noarvore));
    no->direita = NULL;
    no->esquerda = NULL;
    no->ocupados = 0;
    no->valor = 0;
}

void inserir (int valor, noarvore* pai) {
    if (pai->ocupados == 1) { //ja que o primeiro no ja foi criado
        pai->valor = valor;
    }
    else {
        int direita = 0;
        int jatem = 0;
        noarvore* novo = criar();
        noarvore* aux;
        noarvore* anterior;
        aux = pai;
        while (aux != NULL) { //posiciona aux na posicao de insercao
            if (valor == aux->valor) {
                jatem = 1;
                break;
            }
            else if (valor > aux->valor) {
                anterior = aux;
                aux = aux->direita;
                direita = 1;
            }
            else if (valor < aux->valor) {
                anterior = aux;
                aux = aux->esquerda;
                direita = 0;
            }
        }
        if (aux == NULL) {
            if (direita) {
                anterior->direita = novo;
            }
            else {
                anterior->esquerda = novo;
            }
            novo->valor = valor;
            novo->ocupados = -1; //para nao atrapalhar as funcoes preordem, emordem, posordem e largura
            novo->direita = NULL;
            novo->esquerda = NULL;
        }
        else if (jatem) {
            free(novo);
        }
    }
}

void buscar (int valor, noarvore* pai) {
    if (pai->ocupados == 0) {
        printf("%d nao pertence\n", valor);
    }
    else {
        noarvore* aux = malloc(sizeof(noarvore));
        aux = pai;
        while (aux != NULL) {
            if (valor == aux->valor) {
                printf("%d pertence\n", valor);
                break;
            }
            else if (aux->valor < valor) {
                aux = aux->direita;
            }
            else if (aux->valor > valor) {
                aux = aux->esquerda;
            }
        }
        if (aux == NULL) {
            printf("%d nao pertence\n", valor);
        }
        aux = NULL;
        free (aux);
    }
}

void posordem (noarvore* pai) {
    if (pai != NULL) {
        if (pai->ocupados == 0) {
            printf("vazia");
        }
        else {
            posordem (pai->esquerda);
            posordem(pai->direita);
            printf("%d ", pai->valor);
        }
    }
}

void preordem (noarvore* pai) {
    if (pai != NULL) {
        if (pai->ocupados == 0) {
            printf("vazia");
        }
        else {
            printf("%d ", pai->valor);
            preordem(pai->esquerda);
            preordem(pai->direita);
        }
    }
}

void emordem (noarvore* pai) {
    if (pai != NULL) {
        if (pai->ocupados == 0) {
            printf("vazia");
        }
        else {
            emordem(pai->esquerda);
            printf("%d ", pai->valor);
            emordem(pai->direita);
        }
    }
}

void largura (noarvore* pai) {
    if (pai->ocupados == 0) {
        printf("vazia");
    }
    else {
        noarvore** fila = malloc(pai->ocupados * sizeof(noarvore*));
        int inicio = 0;
        int fim = 0;
        noarvore* posicao;
        fila[0] = pai;
        while (inicio <= fim) { //enquanto a fila nao estiver vazia
            posicao = fila[inicio]; //posicao assume o valor do proximo elemento da fila
            printf("%d ", posicao->valor);
            if (posicao->esquerda != NULL) {
                fim++;
                fila[fim] = posicao->esquerda; //enfilera o no da esquerda do elemento desenfileirado
            }
            if (posicao->direita != NULL) {
                fim++;
                fila[fim] = posicao->direita; //enfileira o no da direita do elemento desenfileirado
            }
            inicio++; //remove o elemento desenfileirado da fila
        }
        free(fila);
    }
}

void liberar (noarvore* pai) {
    if (pai != NULL) {
        liberar(pai->esquerda);
        liberar(pai->direita);
        free (pai);
    }
}