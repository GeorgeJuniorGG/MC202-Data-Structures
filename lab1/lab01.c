#include <stdio.h>

int main() {
	int linhas, colunas, nlinhas, ncolunas;
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
	int i, j, r, s = 0;
	for(i = 0; i <= linhas - nlinhas; i++) { //loop que percorre as linhas da matriz original, menos as r linhas finais
		for(j = 0; j <= colunas - ncolunas; j++) { //loop que percorre as colunas da matriz original, menos as s colunas finais
			soma = 0; //resetando a soma da matriz r x s
			for(r = 0; r < nlinhas; r++){ //loop que "cria" matrizes de tamanho r x s na matriz original
				for(s = 0; s < ncolunas; s++){
					soma += mat[i + r][j + s]; //acumula os valores da submatriz r x s
				}
			}
			if (soma > maior) {
				maior = soma; //salva o maior valor
			}
		}
	}
	printf("%d\n", maior);
}