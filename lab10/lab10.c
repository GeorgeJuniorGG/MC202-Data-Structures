#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

noarvore* criar () {
    noarvore* no = malloc(sizeof(noarvore));
    no->direita = NULL;
    no->esquerda = NULL;
    no->ocupados = 0;
    no->valor = 0;
    no->pai = NULL;
    return no;
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
            novo->pai = anterior;
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

noarvore* minimo (noarvore* pai) {
    if (pai->ocupados == 0) {
        return NULL;
    }
    else {
        noarvore* aux = pai;
        while (aux->esquerda != NULL) {
            aux = aux->esquerda;
        }
        return aux;
    }
}

noarvore* maximo (noarvore* pai) {
    if (pai->ocupados == 0) {
        return NULL;
    }
    else {
        noarvore* aux = pai;
        while (aux->direita != NULL) {
            aux = aux->direita;
        }
        return aux;
    }
}

noarvore* predecessor (noarvore* pai, int valor) {
    if (pai->ocupados == 0) {
        return NULL;
    }
    else {
        int jatem = 0;
        noarvore* aux = pai;
        while (aux != NULL) { //loop que encontra a chave na arvore e posiciona aux na posicao dela
            if (valor == aux->valor) {
                jatem = 1;
                break;
            }
            else if (valor < aux->valor) {
                aux = aux->esquerda;
            }
            else if (valor > aux->valor) {
                aux = aux->direita;
            }
        }
        if (!jatem) { //caso o valor nao esteja na arvore
            return NULL;
        }
        else {
            if (aux->esquerda != NULL) { //caso a chave tenha filhos menores que ela
                aux = maximo (aux->esquerda);
                return aux;
            }
            else {
                noarvore* aux2 = aux->pai;
                while (aux2 != NULL && aux == aux2->esquerda) { //quando aux for o filho da direita de aux2, aux2 sera menor que aux
                    aux = aux2;
                    aux2 = aux2->pai;
                }
                return aux2;
            }
        }
    }
}

noarvore* sucessor (noarvore* pai, int valor) {
    if (pai->ocupados == 0) {
        return NULL;
    }
    else {
        int jatem = 0;
        noarvore* aux = pai;
        while (aux != NULL) { //loop que encontra a chave na arvore e posiciona aux na posicao dela
            if (valor == aux->valor) {
                jatem = 1;
                break;
            }
            else if (valor < aux->valor) {
                aux = aux->esquerda;
            }
            else if (valor > aux->valor) {
                aux = aux->direita;
            }
        }
        if (!jatem) { //caso o valor nao esteja na arvore
            return NULL;
        }
        else {
            if (aux->direita != NULL) {
                aux = minimo(aux->direita);
                return aux;
            }
            else {
                noarvore* aux2 = aux->pai;
                while (aux2 != NULL && aux == aux2->direita) { //quando aux for filho da esquerda de aux2, aux2 sera maior que aux
                    aux = aux2;
                    aux2 = aux2->pai;
                }
                return aux2;
            }
        }
    }
}

void remover (noarvore** endereco, noarvore* pai, int valor) {
    int jatem = 0;
    noarvore* aux = pai;
    while (aux != NULL) {
        if (valor == aux->valor) { //loop que encontra a chave na arvore e posiciona aux na posicao dela
            jatem = 1;
            break;
        }
        else if (valor < aux->valor) {
            aux = aux->esquerda;
        }
        else if (valor > aux->valor) {
            aux = aux->direita;
        }
    }
    if (jatem) {
        noarvore* anterior = aux->pai;
        if (aux->direita == NULL) {
            if (anterior != NULL) {
                if (aux == anterior->esquerda) {
                    anterior->esquerda = aux->esquerda;
                }
                else {
                    anterior->direita = aux->esquerda;
                }
            }
            else { //caso a chave seja o primeiro elemento da arvore
                if (aux->esquerda != NULL) {
                    aux->esquerda->ocupados = aux->ocupados;
                    (*endereco) = aux->esquerda; //atualiza o endereco do primeiro elemento da arvore
                }
                else {
                    aux->ocupados = 0; //no caso, ao inves de remover o no, apenas fazemos as outras funcoes desconsiderarem esse no
                }
            }
            if (aux->esquerda != NULL) {
                aux->esquerda->pai = anterior;
                free(aux);
            }
        }
        else if (aux->esquerda == NULL) {
            if(anterior != NULL) {
                if (aux == anterior->esquerda) {
                    anterior->esquerda = aux->direita;
                }
                else {
                    anterior->direita = aux->direita;
                }
            }
            else { //caso a chave seja o primeiro elemento da arvore
                (*endereco) = aux->direita; //atualiza o endereco do primeiro elemento da arvore
                aux->direita->ocupados = aux->ocupados;
            }
            aux->direita->pai = anterior;
            free(aux);
        }
        else {
            noarvore* substituto = sucessor(pai, valor);
            if (substituto != NULL) {
                if (substituto->pai != aux) {
                    //colocando o filho da direita do substituto no lugar do substituto
                    if (substituto->direita != NULL) {
                        substituto->direita->pai = substituto->pai;
                    }
                    substituto->pai->esquerda = substituto->direita;
                    //colocando o filho da direita do substituido no filho da direita do substituto
                    substituto->direita = aux->direita;
                    substituto->direita->pai = substituto;
                }
                if (anterior != NULL) { //faz o pai da chave a ser removida apontar para o sucessor desta ultima
                    if (anterior->direita == aux) {
                        anterior->direita = substituto;
                    }
                    else if (anterior->esquerda == aux) {
                        anterior->esquerda = substituto;
                    }
                }
                else { //caso a chave seja o primeiro elemento da arvore
                    (*endereco) = substituto; //atualiza o endereco do primeiro elemento da arvore
                    substituto->ocupados = aux->ocupados;
                }
                //colocando o filho da esquerda do substituido no filho da esquerda do substituto
                substituto->esquerda = aux->esquerda;
                substituto->esquerda->pai = substituto;
                substituto->pai = anterior; //faz o pai do sucessor da chave removida ser o pai desta ultima
                free(aux);
            }
        }
    }
}

int intervalo (noarvore* pai, int inicio, int fim, int tem) {
    if (pai != NULL) {
        if (pai->ocupados != 0) {
            if (pai->valor > inicio) {
                tem = intervalo (pai->esquerda, inicio, fim, tem);
            }
            if (pai->valor >= inicio && pai->valor <= fim) {
                printf("%d ", pai->valor);
                tem = 1;
            }
            if (pai->valor < fim) {
                int teste;
                teste = intervalo(pai->direita, inicio, fim, tem);
                if (teste != 0) {
                    tem = teste;
                }
            }
            return tem;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}