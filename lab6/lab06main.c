#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

int main() {
    int chaves, requisicoes, i;
    int comparador[3]; //vetor que salva os custos para cada funcao
    for (i = 0; i < 3; i++) {
        comparador[i] = 0;
    }
    node* list;
    scanf("%d", &chaves);
    scanf("%d", &requisicoes);
    int escolhidos[requisicoes]; //vetor que guarda as requisicoes
    for (i = 0; i < requisicoes; i ++) {
        scanf("%d", &escolhidos[i]);
    }
    list = criar(chaves, list); //cria a lista encadeada
    for (i = 0; i < requisicoes; i++) {
        comparador[0] += MTF(chaves, escolhidos[i], list, &list); //calcula o custo da funcao MTV
    }
    list = resetar(list); //reseta a lista, para estar na ordem inicial
    for (i = 0; i < requisicoes; i++) {
        comparador[1] += TR(chaves, escolhidos[i], list, &list); //calcula o custo da funcao TR
    }
    list = resetar(list); //reseta a lista, para estar na ordem inicial
    for (i = 0; i < requisicoes; i++) {
        comparador[2] += C(escolhidos[i], list, chaves, &list); //calcula o custo da funcao C
    }
    limpar(list); //esvazia a lista e libera a memoria
    printf("%d %d %d\n", comparador[0], comparador[1], comparador[2]); //imprime os custos
}