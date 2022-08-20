#include <stdio.h>
#include <stdlib.h>
#include "lab08.h"

void imprime (registro* head, int vazio) {
    if (!vazio) {
        registro* aux = malloc(sizeof(registro));
        registro* anterior = malloc(sizeof(registro));
        if (head->A != NULL) {
            aux = head->A;
        }
        else if (head->B != NULL) {
            aux = head->B;
        }
        else {
            aux = head;
        }
        printf("%.4lf ", head->valor);
        anterior = head;
        while((aux->A != NULL) && (aux->B != NULL)) { //posiciona aux na ultima posicao e imprime o valor das outras
            printf("%.4lf ", aux->valor);
            if (aux->A == anterior) { //procura, pela posicao anterior, qual eh o ponteiro que aponta para o proximo registro
                anterior = aux;
                aux = aux->B;
            }
            else if (aux->B == anterior) {
                anterior = aux;
                aux = aux->A;
            }
        }
        if (aux != head) { //imprime o ultimo valor, se a lista nao tiver apenas 1 elemento
            printf("%.4lf ", aux->valor);
        }
        aux = NULL;
        anterior = NULL;
        free(aux);
        free(anterior);
    }
    printf("\n");
}

void inserir(registro* head, double valor, int posicao, int vazio, registro** ponteiro) {
    registro* aux = malloc(sizeof(registro));
    registro* anterior = malloc (sizeof(registro));
    registro* novo = malloc(sizeof(registro));
    int contador = 0;
    novo->valor = valor;
    if (vazio) { //caso a lista esteja vazia
        head->valor = valor;
        free(novo);
    }
    else if (head->A == NULL && head->B == NULL) { //caso a lista tenha apenas 1 elemento
        if (posicao > 0) {
            head->A = novo;
            novo->B = head;
            novo->A = NULL;
        }
        else {
            novo->A = head;
            novo->B = NULL;
            head->B = novo;
            (*ponteiro) = novo; //atualiza o inicio da lista
        }
    }
    else if (posicao == 0) { //caso a insercao seja na posicao 0
        if(head->A == NULL) {
            head->A = novo;
            novo->A = head;
            novo->B = NULL;
            (*ponteiro) = novo; //atualiza o inicio da lista
        }
        else if (head->B == NULL) {
            head->B = novo;
            novo->A = head;
            novo->B = NULL;
            (*ponteiro) = novo; //atualiza o inicio da lista
        }
    }
    else {
        if (head->A != NULL) {
            aux = head->A;
        }
        else if (head->B != NULL) {
            aux = head->B;
        }
        anterior = head;
        while ((contador < posicao - 1) && (aux != NULL)) { //faz com que o aux esteja na posicao em que o valor sera inserido
            contador ++;
            if (aux->A == anterior) {
                anterior = aux;
                if (aux->B != NULL) {
                    aux = aux->B;
                }
                else { //caso o aux seja o ultimo registro da lista
                    aux = NULL;
                }
            }
            else if (aux->B == anterior) {
                anterior = aux;
                if(aux->A != NULL) {
                    aux = aux->A;
                }
                else { //caso o aux seja o ultimo registro da lista
                    aux = NULL;
                }
            }
        }
        novo->A = anterior;
        novo->B = aux;
        if (aux != NULL) { //se o registro nao for ser inserido no fim da lista
            if (aux->A == anterior) {
                aux->A = novo;
            }
            else if (aux->B == anterior) {
                aux->B = novo;
            }
        }
        if (anterior->A == aux) {
            anterior->A = novo;
        }
        else if (anterior->B == aux) {
            anterior->B = novo;
        }

    }
    aux = NULL;
    anterior = NULL;
    free(aux);
    free(anterior);
}

void reverter (registro* head, int inicio, int fim, registro** ponteiro) {
    if (inicio != fim) {
        registro* aux = malloc(sizeof(registro));
        registro* antes = malloc(sizeof(registro));
        registro* depois = malloc (sizeof(registro));
        registro* aux2 = malloc(sizeof (registro));
        int contador = 0;
        antes = head;
        aux = head;
        if (head->A == NULL) {
            depois = head->B;
        }
        else if (head->B == NULL) {
            depois = head->A;
        }
        if (inicio != 1 && inicio != 0) {
            aux = depois;
            while (contador < inicio - 1) { //posiciona antes no registro anterior a posicao de inicio da reversao, e aux na proxima
                if (aux->A == antes) {
                    antes = aux;
                    aux = aux->B;
                }
                else if (aux->B == antes) {
                    antes = aux;
                    aux = aux->A;
                }
                contador ++;
            }
        }
        if (inicio == 1) {
            if(aux->A == NULL) {
                aux = aux->B;
            }
            else if (aux->B == NULL) {
                aux = aux->A;
            }
        }
        else if (inicio == 0) {
            antes = NULL;
            if (aux->A == NULL) {
                depois = aux->B;
            }
            else if (aux->B == NULL) {
                depois = aux->A;
            }
        }
        if (inicio > 0) {
            depois = aux;
        }
        aux2 = depois;
        if (inicio > 0) {
            if (depois->A == antes) {
                depois = depois->B;
            }
            else if (depois->B == antes) {
                depois = depois->A;
            }
        }
        else {
            if (depois->A == aux) {
                depois = depois->B;
            }
            else if (depois->B == aux) {
                depois = depois->A;
            }
        }
        if ((inicio - fim) != 1) {
            while (contador + 1 < fim) { //posiciona depois no registro posterior a posicao de termino da reversao, e aux2 na anterior de fim
                if (depois->A == aux2) {
                    aux2 = depois;
                    if (depois->B != NULL) {
                        depois = depois->B;
                    }
                    else {
                        depois = NULL;
                    }
                }
                else if (depois->B == aux2) {
                    aux2 = depois;
                    if (depois->A != NULL) {
                        depois = depois->A;
                    }
                    else {
                        depois = NULL;
                    }
                }
                contador++;
            }
        }
        if (depois != NULL) {
            if (depois->A == aux2) {
                depois->A = aux;
            }
            else if (depois->B == aux2) {
                depois->B = aux;
            }
        }
        if (aux2->A == depois) {
            aux2->A = antes;
        }
        else if (aux2->B == depois) {
            aux2->B = antes;
        }
        if (aux->A == antes) {
            aux->A = depois;
        }
        else if (aux->B == antes) {
            aux->B = depois;
        }
        if (antes != NULL) {
            if (antes->A == aux) {
                antes->A = aux2;
            }
            else if (antes->B == aux) {
                antes->B = aux2;
            }
        }
        else {
            (*ponteiro) = aux2;
        }
        aux = NULL;
        aux2 = NULL;
        depois = NULL;
        antes = NULL;
        free(aux);
        free(aux2);
        free(depois);
        free(antes);
    }
}

void liberar(registro* head, int vazio) {
    if (!vazio) {
        registro* aux = malloc(sizeof(registro));
        int loop = 1;
        if (head->A != NULL) {
            aux = head->A;
        }
        else if (head->B != NULL) {
            aux = head->B;
        }
        else { //caso a lista tenha somente um elemento
            free (head);
            loop = 0;
        }
        while((aux->A != NULL && aux->B != NULL) && loop) { //percorre a lista e da free em todas as posicoes, menos na ultima
            if(aux->A == head) {
                free (head);
                head = aux;
                aux = aux->B;
            }
            else if (aux->B == head) {
                free(head);
                head = aux;
                aux = aux->A;
            }
        }
        free (aux);
    }
}