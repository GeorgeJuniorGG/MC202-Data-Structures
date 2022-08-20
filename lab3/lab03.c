#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int numchave;
    int numdesc;
    int numconj = 0;
    int i;
    int j;
    int maior = 0;
    int tam = 0;
    int contagem = 0;
    int posicao[100];
    while ((scanf("%d %d", &numchave, &numdesc)) != EOF) { //loop enquanto tiver entrada
        numconj ++;
        char chaves[numchave][21];
        char desculpas[numdesc + 1][101];
        char copia[numdesc][101];
        contagem = 0;
        maior = 0;
        tam = 0;
        char *ponteiro1;
        for (i = 0; i < numchave; i++) { //salva as palavras chaves em uma matriz
            scanf("%s ", chaves[i]);
        }
        for (i = 0; i < numdesc; i++) { //salva as desculpas em uma matriz
            fgets(desculpas[i], 101, stdin);
            strcpy(copia[i], desculpas[i]); //copia as desculpas com lower case para outra matriz
            for (j = 0; j < 101; j++){
                copia[i][j] = tolower(copia[i][j]);
            }
        }
        printf("Conjunto de desculpas #%d\n", numconj);
        for (i = 0; i < numdesc; i++) { //loop que verifica quantas palavras-chave tem em cada desculpa e salva a/as maior/maiores
            contagem = 0; //reseta a contagem, apos cada desculpa
            for (j = 0; j < numchave; j++) {
                if ((ponteiro1 = strstr (copia[i], chaves[j])) != NULL) { //funcao que verifica se a palavra-chave está na desculpa
                    contagem ++; //se tiver, aumenta a contagem
                    ponteiro1++;
                    while((ponteiro1 = strstr(ponteiro1, chaves[j])) != NULL){ //se tiver na desculpa, verifica se ela está mais de uma vez
                        contagem++;
                        ponteiro1++;
                    }
                }
            }
            if (contagem > maior) { //caso a desculpa seja a com mais palavras-chave até esse momento
                maior = contagem;
                posicao[0] = i;
                tam = 1;
            }
            else if (contagem == maior) { //caso a desculpa empate com outra desculpa, em números de palavras-chave
                posicao[tam] = i;
                tam++;
            }
        }
        for (i = 0; i < tam; i++) {
            printf("%s", desculpas[posicao[i]]);
            if (i == tam - 1) {
                printf("\n");
            }
        }
    }
}