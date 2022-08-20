#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab11.h"

unsigned long djb2 (char *cadeia) { //funcao retirada do enunciado do problema
    unsigned long hash = 5381;
    int c;
    while ((c = *cadeia++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

void inicializar (hashtable* hashtable) {
    int i;
    for (i = 0; i < 6521; i++) {
        hashtable->status[i] = -5; //setando todos os status como vazios
        hashtable->tabela[i] = malloc(251 * sizeof(char));
    }
    hashtable->ocupados = 0;
    hashtable->identificacao = 0;
}

int posicao (unsigned long valor, int i) {  //funcao de hashing
    unsigned long hash;
    hash = valor % 6521;
    hash = (hash + i * (1 + valor % 6519)) % 6521;
    return hash;
}

void inserir (hashtable* hashtable, unsigned long valor, char* cadeia) {
    int naotem = buscar(hashtable, valor, cadeia); //primeiro, verifica se a cadeia ja esta na tabela
    if (naotem == -1) {
        int i = 0;
        int indice = posicao (valor, i);
        while ((hashtable->status[indice] != -5) && (hashtable->status[indice] != -4)) { //acha uma posicao vazia para a insercao
            i++;
            indice = posicao (valor, i);
        }
        strcpy(hashtable->tabela[indice], cadeia);
        hashtable->ocupados ++;
        hashtable->status[indice] = -1;
        hashtable->id[indice] = hashtable->identificacao;
        hashtable->identificacao ++;
    }
}

int buscar (hashtable* hashtable, unsigned long valor, char* cadeia) { //retorna a posicao da cadeia de caracteres ou -1, se nao encontrar
    if (hashtable->ocupados != 0) {
        int i = 0;
        int achou = 0;
        int suposto = posicao(valor, i);
        while (!achou && hashtable->status[suposto] != -5) { //testa as possiveis posicoes, ate achar a chave ou achar um lugar vazio
            if (hashtable->status[suposto] != -4) { //passa por cima dos removidos
                if (!strcmp (cadeia, hashtable->tabela[suposto])) {
                    achou = 1;
                    return suposto;
                }
            }
            i++;
            suposto = posicao(valor, i);
        }
    }
    return -1;
}

void remover (hashtable* hashtable, unsigned long valor, char* cadeia) {
    if (hashtable->ocupados != 0) {
        int indice = buscar(hashtable, valor, cadeia);
        if (indice != -1) { //caso a chave esteja na lista
            hashtable->ocupados --;
            hashtable->status[indice] = -4; //seta a posicao como removida
        }
    }
}