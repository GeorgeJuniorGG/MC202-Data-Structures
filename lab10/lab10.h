//Definindo o registro de cada no da arvore de busca binaria
typedef struct noarvore {
    int valor;
    int ocupados;
    struct noarvore* esquerda;
    struct noarvore* direita;
    struct noarvore* pai;
} noarvore;

//Definindo a funcao que cria um no da arvore
noarvore* criar ();

//Definindo a funcao inserir, que insere um elemento inteiro x na arvore de busca binaria, se este ja nao estiver nela
void inserir (int valor, noarvore* pai);

//Definindo a funcao buscar, que busca um elemento na arvore e indica se ele pertence ou nao a arvore
void buscar (int valor, noarvore* pai);

//Definindo a funcao posordem, que imprime as chaves visitadas por um percurso em profundidade pos ordem. Indica se a arvore for vazia
void posordem (noarvore* pai);

//Definindo a funcao preordem, que imprime as chaves visitadas por um percurso em profundidade pre ordem. Indica se a arvore for vazia
void preordem (noarvore* pai);

//Definindo a funcao emordem, que imprime as chaves visitadas por um percurso em profundidade em ordem. Indica se a arvore for vazia
void emordem (noarvore* pai);

//Definindo a funcao largura, que imprime as chaves visitadas por um percurso em largura. Indica se a chave for vazia
void largura (noarvore* pai);

//Definindo a funcao que desaloca a memoria
void liberar (noarvore* pai);

//Definindo a funcao que imprime a menor chave da arvore, se ela nao estiver vazia
noarvore* minimo (noarvore* pai);

//Definindo a funcao que imprime a maior chave da arvore, se ela nao estiver vazia
noarvore* maximo (noarvore* pai);

//Definindo a funcao que imprime o sucessor de x. Indica se este nao existir ou se este nao estiver na arvore
noarvore* sucessor(noarvore* pai, int valor);

//Definindo a funcao que imprime o predecessor de x. Indica se este nao existir ou se este nao estiver na arvore
noarvore* predecessor (noarvore* pai, int valor);

//Definindo a funcao que imprime, em ordem crescente, todas as chaves contidas no intervalo [x,y]. Indica se nao tiver chaves neste intervalo
int intervalo (noarvore* pai, int inicio, int fim, int tem);

//Definindo a funcao que remove o elemento x da arvore, se houver, usando sempre o sucessor para substituir um no que tem dois filhos
void remover (noarvore** endereco, noarvore*pai, int valor);