typedef struct no* Lista;

Lista cria_lista();

int lista_vazia(Lista lst);
int insere_elem(Lista lst, int n);
int remove_elem(Lista lst, int n);
void imprime_lista(Lista lst);

int insere_ord(Lista lst, int n);
int remove_ord(Lista lst, int n);

int ordenado(Lista lst);