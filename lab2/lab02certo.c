#include <stdio.h>

int main() {
    int atendentes;
    int clientes;
    float media;
    int muito = 0;
    int espera;
    float soma = 0.0;
    float contagem = 0.0;
    int i;
    scanf("%d %d", &atendentes, &clientes); //le o num de atendentes e de clientes
    int mat[clientes][3];
    for(i = 0; i < clientes; i++) {
        scanf("%d %d", &mat[i][0], &mat[i][1]); //le cada linha e salva em uma matriz o momento em que chegou (M) e o tempo de atendimento (T)
        contagem += 1; //conta quantas linhas tem e guarda em um float
    }
    for(i = 0; i < atendentes; i++) { //considerando N = num atendentes, os N primeiros clientes COM CERTEZA nao terao nada de espera
        mat[i][2] = mat[i][1] + mat[i][0]; //marca o momento em que cada caixa eh liberado, apos o primeiro uso
    }
    if(atendentes == 1){ //resolve o caso de ter 1 atendente
        for(i = 1; i < clientes; i++) {
            espera = mat[i - 1][0] + mat[i - 1][1] - mat[i][0]; // espera eh o momento que o caixa liberou menos o instante em que o cliente chegou
            if (espera > 10) {
                muito += 1; //marca quem demorou mais de 10 min
            }
            if(espera < 0) { //em caso de haver sobra de tempo
                espera = 0;
            }
            soma += espera; //soma a espera de cada cliente
            mat[i][1] += espera; //transforma a 2a coluna em uma coluna que guarda o tempo (T) que cada cliente passou na loja
        }                       //assim, podemos considerar que cada cliente saiu no momento = M + T
    }
    else { //resolve o caso de ter mais de 1 atendente 
        int k, j = 0;
        int ordem[atendentes]; //vetor que guarda os momentos em que os caixas ficam livres
        for(i = 0; i < atendentes; i++){
            ordem[i] = mat[i][2]; //comeca com os valores do primeiro round dos caixas
        }
        for(i = atendentes; i < clientes; i++){
            espera = mat[j][2] - mat[i][0]; //espera = momento em que o primeiro caixa esvazia - momento em que o cliente chega 
            if (espera > 10) { //conta os casos de quem demora mais de 10 min
                muito += 1;
            }
            if (espera < 0) { //quando sobra tempo, considera a espera como sendo 0
                espera = 0;
            }
            soma += espera; //acumula as esperas
            mat[i][1] += espera; //a 2a coluna passa a guardar o tempo total que o cliente passa na loja
            mat[i][2] = mat[i][1] + mat[i][0]; //a 3a coluna guarda o tempo em que o cliente sai
            mat[j][2] = mat[i][2];
            ordem[0] = mat[i][1] + mat[i][0]; //o menor momento de saida eh substituido pelo momento de saida do proximo cliente
            for(k = 0; k < atendentes; k++){ //determina qual caixa vai esvaziar primeiro
                if(mat[j][2] > mat[k][2]){
                    j = k;
                }
            }
        }
    }
    media = soma/contagem; //calcula a media
    printf("Espera media para %d clientes: %.1f minutos\n", clientes, media);
    printf("Numero de clientes que esperaram mais que 10 minutos: %d\n", muito);
}