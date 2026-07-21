#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

int main(){

    Lista c = cria_lista();
    insere_elem(&c, 2);
    insere_elem(&c, 1);
    insere_elem(&c, 26);
    imprime_lista(c);
    remove_elem(&c, 26);
    imprime_lista(c);

    return 0;
}