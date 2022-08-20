#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int ordem, i, j;
    double soma = 0;
    double contagem = 0;
    double media, desvio;
    scanf("%d", &ordem);
    double* matriz[ordem];
    for(i = 0; i < ordem; i++) {
        matriz[i] = (double*) malloc((i + 1) * sizeof(double)); //aloca a memoria necessaria para cada linha, levando em conta o numero de elementos
        for(j = 0; j <= i; j++) {
            scanf("%lf", &matriz[i][j]);
            soma += matriz[i][j]; //soma os valores dos elementos da matriz
            contagem += 1; //conta quantos elementos tem na matriz
        }
    }
    media = soma/contagem;
    soma = 0;
    for(i = 0; i < ordem; i ++) {
        for(j = 0; j <= i; j++) {
            desvio = matriz[i][j] - media; //calcula os desvios
            soma += (desvio * desvio); //soma os desvios ao quadrado
        }
    }
    desvio = sqrt(soma/contagem); //calcula o desvio padrao
    for (i = 0; i < ordem; i++) {
        for(j = 0; j <= i; j++) {
            matriz[i][j] = (matriz[i][j] - media)/desvio;
            printf("%.12lf ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("%.12lf %.12lf \n", media, desvio);
    for (i = 0; i < ordem; i++) {
        free(matriz[i]); //libera a memoria alocada
    }
}