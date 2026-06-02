#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"

int main(){

    Lista lista = cria_lista();

    imprime_lista(lista);

    insere_elemento(lista, 4);
    insere_elemento(lista, 8);
    insere_elemento(lista, -1);
    insere_elemento(lista, 19);
    insere_elemento(lista, 2);
    insere_elemento(lista, 7);
    insere_elemento(lista, 8);
    insere_elemento(lista, 5);
    insere_elemento(lista, 9);
    insere_elemento(lista, 22);
    insere_elemento(lista, 45);

    imprime_lista(lista);
    



    return 0;
}
