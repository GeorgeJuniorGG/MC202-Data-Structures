void remover (hashtable* hashtable, unsigned long valor, char* cadeia) {
    if (hashtable->ocupados != 0) {
        int indice = buscar(hashtable, valor, cadeia);
        if (indice != -1) { //caso a chave esteja na lista
            hashtable->ocupados --;
            int pai = valor %6521;
            int aux = hashtable->status[pai];
            if (pai == indice) { //caso a chave seja a primeira posicao de uma possivel colisao
                if (aux != -1) { //caso haja colisao
                    hashtable->tabela[pai] = hashtable->tabela[aux];
                    hashtable->status[pai] = hashtable->status[aux];
                    hashtable->id[pai] = hashtable->id[aux];
                    hashtable->status[aux] = -5;
                }
                else { //caso nao haja colisao
                    hashtable->status[pai] = -5;
                }
            }
            else {
                while (aux != indice) {
                    pai = aux; //posiciona pai na posicao que aponta para chave que sera removida
                    aux = hashtable->status[pai];
                }
                hashtable->status[pai] = hashtable->status[indice];
                hashtable->status[indice] = -5;
            }
        }
    }
}
void inserir (hashtable* hashtable, unsigned long valor, char* cadeia) {
    int naotem = buscar(hashtable, valor, cadeia);
    if (naotem == -1) {
        int indice = posicao (valor, hashtable);
        int pai = valor % 6521; //posicao em que seria inserida, se nao houvesse colisoes
        hashtable->ocupados ++;
        hashtable->status[indice] = -1;
        hashtable->tabela[indice] = cadeia;
        hashtable->id[indice] = hashtable->identificacao;
        hashtable->identificacao ++;
        if (pai != indice) { //caso ocorra colisao
            int aux = hashtable->status[pai];
            while (aux != -1) {
                pai = aux;
                aux = hashtable->status[pai];
            }
            hashtable->status[pai] = indice;
        }
    }
}

int buscar (hashtable* hashtable, unsigned long valor, char* cadeia) { //retorna a posicao da cadeia de caracteres ou -1, se nao encontrar
    if (hashtable->ocupados != 0) {
        int pai = valor % 6521;
        if (hashtable->status[pai] != -5) { //so entra se o local nao estiver vazio
            int aux = hashtable->status[pai];
            if (hashtable->tabela[pai] != NULL) {
                if (!strcmp(hashtable->tabela[pai], cadeia)) { //caso seja a primeira posicao da colisao
                    return pai;
                }
            }
            else {
                int verificador = 0;
                while (aux != -1) { //percorre a tabela ate achar a cadeia de caracteres ou ate achar o fim
                    if (hashtable->tabela[aux] != NULL) { //passa por cima dos removidos
                        if (!strcmp (cadeia, hashtable->tabela[aux])) {
                            verificador = 1;
                            break;
                        }
                    }
                    pai = aux;
                    aux = hashtable->status[pai];
                }
                if (!verificador) {
                    return -1;
                }
                else {
                    return aux;
                }
            }
        }
    }
    return -1;
}

void remover (hashtable* hashtable, unsigned long valor, char* cadeia) {
    if (hashtable->ocupados != 0) {
        int indice = buscar(hashtable, valor, cadeia);
        if (indice != -1) { //caso a chave esteja na lista
            hashtable->ocupados --;
            hashtable->tabela[indice] = NULL; //seta a posicao como dummy, na tabela de strings
        }
    }
}