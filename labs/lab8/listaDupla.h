typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int n);
void imprime_lista(Lista lst);
int remove_elem(Lista *lst, int n);
