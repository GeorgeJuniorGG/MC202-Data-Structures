#include <stdio.h>

int main() {
	int linhas = 0;
	int colunas = 0;
	int nlinhas = 0;
	int ncolunas = 0;
	scanf("%d %d %d %d", &linhas, &colunas, &nlinhas, &ncolunas); //input dessas informacoes
	int linha = 0;
	int coluna = 0;
	int mat[linhas][colunas];
	for(linha = 0; linha < linhas; linha++) { //loops de scanf para atribuir os valores a matriz
		for(coluna = 0; coluna < colunas; coluna++) {
			scanf("%d", &mat[linha][coluna]);
		}
	}
	int maior = 0;
	int soma = 0;
	int i = 0;
	int j = 0;
	int r = 0;
	int s = 0;
	for(i = 0; i <= linhas - nlinhas; i++) { //loop que percorre as linhas da matriz original, menos as r linhas finais
		soma = 0;
		for(j = 0; j <= colunas - ncolunas; j++) { //loop que percorre as colunas da matriz original, menos as s colunas finais
			for(r = 0; r < nlinhas; r++){ //loop que "cria" matrizes de tamanho r x s na matriz original
				if (j == 0) {
					for(s = 0; s < ncolunas; s++) {
						soma += mat[i + r][j + s]; //acumula os valores da submatriz r x s
					}
				}
				else { //para ser mais eficiente, apenas subtraio o primeiro elemento da linha da submatriz e somo o ultimo
					soma -= (mat[i][j - 1]);
					soma += (mat[i][j + ncolunas]);
				}
			}
			if (soma > maior) {
				maior = soma; //salva o maior valor
			}
		}
	}
	printf("%d\n", maior);
}