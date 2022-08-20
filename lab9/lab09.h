//Definindo o registro de cada no da arvore de busca binaria
typedef struct noarvore {
    int valor;
    int ocupados;
    struct noarvore* esquerda;
    struct noarvore* direita;
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