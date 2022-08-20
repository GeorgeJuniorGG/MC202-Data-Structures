#include <stdio.h>
#include <string.h>

typedef struct registro {
    int numero;
    char nome[51];
    char endereco[101];
    char telefone[13];
    char aniversario[9];
} registro;

registro inserir(registro pessoa) { //funcao que insere registros
    scanf(" %[^\n] ", &pessoa.nome); //insere o nome
    scanf(" %[^\n] ",&pessoa.endereco); //insere o endereco
    scanf(" %s ", &pessoa.telefone); //insere o telefone
    scanf(" %s", &pessoa.aniversario); //insere o aniversario
    printf("Contato para %s inserido.\n", pessoa.nome);
    printf("\n");
    return pessoa;
}

void buscar(char* nome, registro* registros, int total) { //funcao que busca registros
    int i;
    int contagem = 0; //conta quantos achou
    printf("Resultado da busca:\n");
    for (i = 0; i < total; i++) {
        if ((strstr(registros[i].nome, nome)) != NULL) { //verifica se o nome que se quer achar faz parte do nome de determinado registro
            contagem++;
            printf("(%d) %s\t%s\t%s\t%s\n", registros[i].numero, registros[i].nome, registros[i].endereco, registros[i].telefone, registros[i].aniversario);
            printf("\n");
        }
    }
    if (contagem == 0) {
        printf("Nenhum contato.\n");
        printf("\n");
    }
}

int remover(char* removido, registro* registros, int total) { //funcao que remove registros
    int contagem = 0; //conta quantos serao removidos
    int i;
    registro aux; //para passar o registro do indice i, para o indice i - 1
    int guarda;
    for (i = 0; i < total; i++) { //percorre os registros
        if (strcmp(removido, registros[i].nome) == 0) { //se ja tiver o nome
            guarda = i;
            for (i = guarda; i < total; i++) {
                aux = registros[i + 1];
                registros[i] = aux;
                registros[i].numero -= 1;
            }
            i = guarda - 1;
            contagem++; //conta quantos sao removidos
        }
    }
    printf("Contatos de %s removidos: %d.\n", removido, contagem);
    printf("\n");
    return contagem;
}

void imprimir(int contagem, registro* registros) { //funcao que imprime todos os registros
    int i;
    printf("Listagem:\n");
    if (contagem == 0){
        printf("Nenhum contato.\n");
    }
    else{
        for (i = 0; i < contagem; i++) {
            printf("(%d) %s\t%s\t%s\t%s\n", registros[i].numero, registros[i].nome, registros[i].endereco, registros[i].telefone, registros[i].aniversario);
        }
    }
    printf("\n");
}

int main() {
    int i = 0; //variavel que guarda o numero de registros salvos
    registro registros[1000];
    int verificador;
    scanf("%c", &verificador);
    do {
        if (verificador == 105){
            registros[i] = inserir(registros[i]);
            registros[i].numero = i + 1;
            i++;
        }
        else if (verificador == 98) {
            char buscado[51];
            scanf(" %[^\n] ", &buscado);
            buscar(buscado, registros, i);
        }
        else if (verificador == 114) {
            char removido[51];
            scanf(" %[^\n] ", &removido);
            i =  i - remover(removido, registros, i);
        }
        else if (verificador == 112) {
            imprimir(i, registros);
        }
        scanf("%c", &verificador);
    } while (verificador != 102);     
}