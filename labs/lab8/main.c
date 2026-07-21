#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

int main(){

    Lista dupla = cria_lista();

    insere_elem(&dupla, 2);
    insere_elem(&dupla, 6);

    imprime_lista(dupla);

    return 0;
}