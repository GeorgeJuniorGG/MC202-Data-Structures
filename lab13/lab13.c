#include <stdio.h>

void criarvetorarestas (int numarestas, int numvertices, int vertices[numvertices], int arestas[numarestas * 2], int fila[2000]) {
    int i, j;
    int posicao = 0;
    vertices[0] = 0;
    for (j = 0; j < numvertices; j++) {
        for (i = 0; i < numarestas * 2; i++) {
            if (fila[i] == j + 1) {
                if (i % 2 == 0) { //ja que as arestas sao guardadas em duplas, o "i" esta sempre em uma posicao par e o "j" em posicao impar
                    arestas[posicao] = fila[i + 1]; //se achou o "i", guarda o "j"
                }
                else {
                    arestas[posicao] = fila[i - 1]; //se achou o "j", guarda o "i"
                }
                posicao++; //guarda a proxima posicao de insercao no vetor de arestas
            }
        }
        if (j < numvertices - 1) {
            vertices[j + 1] = posicao; //faz cada posicao do vetor de vertices apontar para a primeira posicao do vetor de arestas que contem um aresta deste vertice
        }
    }
}

void bfs (int numvertices, int vertices[numvertices], int numarestas, int arestas [numarestas * 2], int marcados [numvertices], int inicio, int largura[numvertices]) {
    int comeco = 0;
    int final = 0;
    int atual, i;
    int distancias[numvertices];
    distancias[0] = 0;
    largura[0] = inicio; //enfileira o vertice de inicio
    while (comeco <= final) {
        atual = largura[comeco]; //desenfileira o proximo da lista
        if (atual != numvertices) {
            for (i = 0; i < vertices[atual] - vertices[atual - 1]; i++) { //a presenca dos -1 se deve ao fato de que o elemento i esta sendo representado pelo indice i - 1 no vetor
                if (marcados[arestas[vertices[atual - 1] + i]] == 0) {
                    final++;
                    distancias[final] = distancias[comeco] + 1;
                    printf("%d %d\n", arestas[vertices[atual - 1] + i], distancias[final]);
                    marcados[arestas[vertices[atual - 1] + i]] = 1;
                    largura[final] = arestas[vertices[atual - 1] + i]; //enfileira o vertice encontrado
                }
            }
        }
        else { //se for o ultimo elemento, ele nao tem um proximo para verificar quantas arestas ele tem
            for (i = 0; i < numarestas * 2 - vertices[atual - 1]; i++) {
                if (marcados[arestas[vertices[atual - 1] + i]] == 0) {
                    final ++;
                    distancias[final] = distancias[comeco] + 1;
                    printf("%d %d\n", arestas[vertices[atual - 1] + i], distancias[final]);
                    marcados[arestas[vertices[atual - 1] + i]] = 1;
                    largura[final] = arestas[vertices[atual - 1] + i]; //enfileira o vertice encontrado
                }
            }
        }
        comeco ++;
    }
}

int main() {
    int numvertices, inicio;
    int i = -1;
    int j = -1;
    int posicao = 0;
    int numarestas = 0;
    scanf("%d", &numvertices);
    int vertices[numvertices]; //vetor que guarda a posicao do primeiro vizinho de cada vertice
    int marcados[numvertices + 1]; //vetor que indica se tal vertice ja foi visitado
    int fila[numvertices * (numvertices - 1)]; //guarda as arestas para montar, posteriormente, o vetor das arestas
    int largura[numvertices];
    while (i != 0 && j != 0) {
        scanf("%d,%d", &i, &j);
        fila[posicao] = i;
        fila[posicao + 1] = j;
        numarestas ++;
        posicao += 2;
    }
    numarestas --; //ja que ele contou o 0,0 como aresta
    int arestas[numarestas * 2];
    for (i = 0; i <= numvertices; i++) { //seta todos os vertices como nao marcados
        marcados[i] = 0;
    }
    criarvetorarestas(numarestas, numvertices, vertices, arestas, fila);
    scanf("%d", &inicio);
    printf("Origem da busca: %d\n", inicio);
    printf("Vertices alcancados e distancias:\n");
    printf("%d 0\n", inicio);
    marcados[inicio] = 1; //seta o inicio como marcado
    bfs(numvertices, vertices, numarestas, arestas, marcados, inicio, largura);
}