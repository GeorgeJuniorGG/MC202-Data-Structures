typedef struct registro {
    double valor;
    struct registro* A;
    struct registro* B;
} registro;

//Declarando a funcao que imprime os valores da lista a partir da cabeça. Se a lista for vazia, imprime uma linha em branco
void imprime (registro* head, int vazio);

//Declarando a funcao que insere o nó de valor i na posicao j. Se j for maior do que a lista, a funcao insere i no final
void inserir (registro* head, double valor, int posicao, int vazio, registro** ponteiro);

//Declarando a funcao que reverte o trecho da lista entre as posicoes i e j, inclusive
void reverter (registro* head, int inicio, int fim, registro** ponteiro);

//Declarando a funcao que da free nos registros
void liberar(registro* head, int vazio);