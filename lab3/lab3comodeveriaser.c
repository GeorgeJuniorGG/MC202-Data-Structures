#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contem (char *chave, char *desculpa) {
    int i, j = 0;
    for (i = 0; i < strlen(desculpa); i++) {
        if ((desculpa[i] == chave[0]) && ((i == 0) || !(isalpha(desculpa[i - 1])) || (desculpa[i] == " "))) {
            for (j = 1; j < strlen(chave); j++) {
                if (desculpa[i + j] != chave[j]) {
                    break;
                }
            }
            if(desculpa[i + j] != chave[j]) {
                break;
            }
            else if (desculpa[i + j + 1] != "\0" || desculpa[i + j + 1] != " ") {
                break;
            }
            else if (! isalpha(desculpa[i + j + 1])) {
                break;
            }
            else {
                return 1;
            }
        } 
    }
    return 0;
}
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
                if ((contem (chaves[j], desculpas[i])) != 0) { //funcao que verifica se a palavra-chave está na desculpa
                    contagem ++; //se tiver, aumenta a contagem
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