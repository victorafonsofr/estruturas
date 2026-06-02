typedef struct lista* Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elemento(Lista lst, int n);
void imprime_lista(Lista lst);
void excluir_lista(Lista* lst);