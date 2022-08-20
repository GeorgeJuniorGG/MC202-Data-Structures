//criando o struct de cada nó da lista, que contem o ponteiro para o proximo nó
typedef struct node {
    int valor;
    int contador;
    struct node* next;
} node;

//funcao que move o registro para o início da lista, sem bagunçar a ordem, SE ele já não estiver no início da lista, e retorna o custo
int MTF(int chaves, int numero, node* list, node** ponteiro);

//funcao que troca o registro com o registro que o precede, SE ele já não estiver no início da lista, e retorna o custo
int TR(int chaves, int numero, node* list, node** ponteiro);

//funcao que possui um contador e quando um registro é chamado, aumenta sua contagem e ordena o vetor de registros de acordo com a contagem,
//ficando anterior a todos os registros com contagem menor ou igual a dele
int C (int numero, node* list, int chaves, node** ponteiro);

//funcao que cria a lista encadeada
node* criar(int chaves, node* list);

//funcao que reseta a lista encadeada
node* resetar(node* list);

//funcao que libera a memoria da lista
void limpar(node* list);

void imprimir(node** list);