typedef struct bebida* ListaB;

ListaB cria_listab();

int lista_vaziab(ListaB lst);
int insere_elemb(ListaB lst, char nome[20], int volume, float preco );
int remove_elemb(ListaB lst, int cod);
void imprime_listab(ListaB lst);