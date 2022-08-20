#include <stdio.h>
#include <stdlib.h>
#include "lab07.h"

void aumenta (int tamanho, vetdinamico* vetor) {
    int i;
    int* novo = malloc(2 * tamanho * sizeof(int));
    for (i = 0; i < tamanho; i++) { //loop que copia o vetor antigo para o vetor novo, colocando o inicio na posicao 0
        novo[i] = vetor->vetor[(vetor->inicio + i) % tamanho];
    }
    free(vetor->vetor); //libera a memoria do vetor antigo
    vetor->inicio = 0;
    vetor->fim = tamanho - 2;
    vetor->vetor = novo;
    vetor->tamanho = 2 * vetor->tamanho; 
}

void reduz(int tamanho, vetdinamico* vetor) {
    if(tamanho/2 > 0) {
        int i;
        int* novo = malloc((tamanho/2) * sizeof(int));
        for (i = 0; i < tamanho/2; i++) { //loop que copia o vetor antigo para o vetor novo, colocando o inicio na posicao 0
            novo[i] = vetor->vetor[(vetor->inicio + i) % tamanho];
        }
        vetor->inicio = 0;
        vetor->fim = tamanho/4;
        free(vetor->vetor); //libera a memoria do vetor antigo
        vetor->vetor = novo;
        vetor->tamanho = vetor->tamanho / 2;
    }
}

void imprime(int tamanho, vetdinamico* vetor) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor->vetor[i]);
    }
    printf("\n");
}

void insertfirst (int numero, vetdinamico* vetor, int ocupados) {
    int novoinicio = vetor->inicio - 1;
    if (novoinicio < 0) { //caso esteja na primeira posicao, o inicio passa a ser a ultima posicao do vetor
        novoinicio = vetor->tamanho - 1;
    }
    vetor->vetor[novoinicio] = numero;
    vetor->inicio = novoinicio;
    if(ocupados == 1) { //caso so tenha um elemento, o inicio e o fim sao iguais
        vetor->fim = vetor->inicio;
    }
}

void removefirst(vetdinamico* vetor) {
    int novoinicio = vetor->inicio + 1;
    if(novoinicio >= vetor->tamanho) { //caso ultrapasse o tamanho do vetor, o inicio passa a ser a primeria posicao do vetor
        novoinicio = 0;
    }
    vetor->inicio = novoinicio;
}

void printfirst (vetdinamico* vetor, int ocupados) {
    if(ocupados != 0) {
        printf("%d\n", vetor->vetor[vetor->inicio]);
    }
}

void insertlast (int numero, vetdinamico* vetor, int ocupados) {
    int novofim = vetor->fim + 1;
    if (novofim >= vetor->tamanho) { //caso ultrapasse o tamanho do vetor, passa a ser a primeira posicao
        novofim = 0;
    }
    vetor->fim = novofim;
    vetor->vetor[novofim] = numero;
    if(ocupados == 1) {
        vetor->inicio = vetor->fim; //caso tenha um unico elemento, o fim e o inicio sao iguais
    }
}

void removelast(vetdinamico* vetor) {
    int novofim = vetor->fim - 1;
    if (novofim < 0) { //caso o fim esteja na primeira posicao do vetor, passa a ser a ultima
        novofim = vetor->tamanho - 1;
    }
    vetor->fim = novofim;
}

void printlast(vetdinamico* vetor, int ocupados) {
    if (ocupados != 0) {
        printf("%d\n", vetor->vetor[vetor->fim]);
    }
}

void isempty(int ocupados) {
    if (ocupados == 0) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
}

int kill() {
    return 0;
}