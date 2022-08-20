//declarando a struct que guarda o vetor dinamico, a posicao do primeiro elemento e a posicao do ultimo elemento
typedef struct vetdinamico {
    int* vetor;
    int fim;
    int inicio;
    int tamanho;
} vetdinamico;

//declarando a funcao que aumenta o tamanho do vetor
void aumenta(int tamanho, vetdinamico* vetor);

//declarando a funcao que diminui o tamanho do vetor
void reduz(int tamanho, vetdinamico* vetor);

//declarando a funcao que imprime o vetor, com finalidade de testar se as funcoes funcionam corretamente
void imprime(int tamanho, vetdinamico* vetor);

//declarando a funcao que insere um numero no inicio do vetor
void insertfirst(int numero, vetdinamico* vetor, int ocupados);

//declarando a funcao que remove o primeiro elemento do vetor, se ele nao estiver vazio
void removefirst(vetdinamico* vetor);

//declarando a funcao que imprime o primeiro elemento do vetor, se ele nao estiver vazio
void printfirst(vetdinamico* vetor, int ocupados);

//declarando a funcao que insere um numero no final do vetor
void insertlast(int numero, vetdinamico* vetor, int ocupados);

//declarando a funcao que remove um numero do final do vetor, se ele nao estiver vazio
void removelast(vetdinamico* vetor);

//declarando a funcao que imprime o ultimo elemento do vetor, se ele nao estiver vazio
void printlast(vetdinamico* vetor, int ocupados);

//declarando a funcao que imprime yes se o vetor estiver vazio e no, caso contrario
void isempty(int ocupados);

//declarando a funcao que encerra o programa
int kill();