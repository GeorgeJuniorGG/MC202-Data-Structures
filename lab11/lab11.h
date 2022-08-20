//Criando a tabela de Hashing
typedef struct  hashtable {
    char* tabela[6521]; //que eh um numero primo que, quando a tabela ta cheia com 5000 elementos, ainda tem cerca de 30% vazio
    int status[6521]; //indica se esta vazio ou se houve colisao
    int id[6521]; //indica o id do elemento que esta na posicao indicada
    int ocupados; //indica quantos elementos estao na hashtable
    int identificacao; //indica o id do prox elemento
} hashtable;

//Definindo a funcao que inicializa a hashtable
void inicializar (hashtable* hashtable);

//Definindo a funcao que insere elementos na hashtable
void inserir (hashtable* hashtable, unsigned long valor, char* cadeia);

//Definindo a funcao que busca elementos na hashtable
int buscar (hashtable* hashtable, unsigned long valor, char* cadeia);

//Definindo a funcao que remove elementos da hashtable
void remover (hashtable* hashtable, unsigned long valor, char* cadeia);

//Definindo a funcao que transforma a cadeia de caracteres em um numero
unsigned long djb2 (char *cadeia);

//Definindo a funcao que calcula a posicao do elemento na hashtable
int posicao (unsigned long valor, int i);