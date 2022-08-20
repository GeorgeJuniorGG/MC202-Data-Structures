#include <stdio.h>
#include <math.h>

void inserirnoheap (int posicao, int n, int numeros[n]) {
    int aux;
    int loop = 1;
    while (loop) {
        int pai = floor ((posicao - 1)/2);
        if (numeros[posicao] > numeros[pai]) {
            aux = numeros[posicao];
            numeros[posicao] = numeros[pai];
            numeros[pai] = aux;
            posicao = pai;
            if (!posicao) { //quando o elemento chega na raiz, a insercao termina
                loop = 0;
            }
        }
        else {
            loop = 0; //quando o elemento eh menor do que seu pai, a insercao termina
        }
    }
}

void criarheap (int n, int numeros[n]) {
    int i;
    for (i = 1; i < n; i++) { //considera o vetor numeros[0] como um heap e insere os proximos elementos como em um heap
        inserirnoheap (i, n, numeros);
    }
}


void consertarheap (int tamanho, int posicao, int n, int numeros[n]) {
    if (posicao <= floor((tamanho - 1)/2) && posicao < tamanho) { //se o elemento nao tem filhos, ele ja eh o maximo
        if (numeros[posicao] >= numeros[posicao * 2 + 1] && numeros[posicao] >= numeros[posicao * 2 + 2]) {
            return;
        }
        else if (numeros[posicao * 2 + 2] < numeros[posicao * 2 + 1] && tamanho > 1) { //caso o "filho da esquerda" seja maior que o "filho da direita"
            int aux = numeros[posicao];
            numeros[posicao] = numeros[posicao * 2 + 1];
            numeros[posicao * 2 + 1] = aux;
            consertarheap(tamanho - 1, posicao * 2 + 1, n, numeros);
        }
        else if (numeros[posicao * 2 + 2] >= numeros[posicao * 2 + 1] && tamanho > 2 * posicao + 1 && tamanho > 2){ //eh importante que tamanho tenha essas restricoes, para garantir que ele tenha o "filho da direita"
            int aux = numeros[posicao];
            numeros[posicao] = numeros[posicao * 2 + 2];
            numeros[posicao * 2 + 2] = aux;
            consertarheap(tamanho - 2, posicao * 2 + 2, n, numeros);
        }
        else if (tamanho == 2) { //esse caso nao eh tratado pelas outras condicoes, se o numero da posicao + 2 eh maior que a posicao + 1 e o tamanho eh 2
            if (numeros[posicao] < numeros[posicao + 1]) {
                int aux = numeros[posicao];
                numeros[posicao] = numeros[posicao + 1];
                numeros[posicao + 1] = aux;
            }
        }
    }
}

int main () {
    int n, i, aux, tamanho;
    scanf("%d", &n);
    int numeros[n];
    tamanho = n;
    for (i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    criarheap(n, numeros);
    for (i = n - 1; i >= 1; i--) {
        aux = numeros[0]; //numeros[0] eh o maior valor do vetor, portanto, ele estara na ultima posicao, para que o vetor fique ordenado
        numeros[0] = numeros[i];
        numeros[i] = aux;
        tamanho --; //"esquece" a ultima posicao do vetor, ja que ela ja esta correta
        consertarheap (tamanho, 0, n, numeros); //volta a colocar o maximo na posicao numeros[0], ignorando a ultima posicao do vetor
    }
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}
