#include <stdio.h>

int main() {
	int info[4];
	scanf("%d %d %d %d", &info[0], &info[1], &info[2], &info[3]);
	int linha = 0;
	int coluna = 0;
	int mat[info[0]][info[1]];
	for(linha = 0; linha < info[0]; linha++) {
		for(coluna = 0; coluna < info[1]; coluna++) {
			scanf("%d", &mat[linha][coluna]);
		}
	}
	//int maiorvalor = 0;
	//for(linha = 0; linha < info[0]; linha++) {
	//	for(coluna = 0; coluna < info[1]; coluna++) {
	//		if(coluna == info[1] - 1) {
	//			printf("%d\n", mat[linha][coluna]);
	//		}
	//		else {
	//			printf("%d ", mat[linha][coluna]);
	//		}
	//	}
	//}
	int maior, soma = 0;
	int i, j, r, s = 0;
	for(i = 0; i <= info[0] - info[2]; i++) {
		for(j = 0; j <= info[1] - info[3]; j++) {
			soma = 0;
			for(r = 0; r < info[2]; r++){
				for(s = 0; s < info[3]; s++){
					soma += mat[i + r][j + s];
				}
			}
			if (soma > maior) {
				maior = soma;
			}
		}
	}
	printf("%d", maior);
}