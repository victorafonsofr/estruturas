#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"

int main(){

    int v[] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};

    Lista lista1 = cria_lista();
    imprime_lista(lista1);

    for(int i = 0; i < 11; i++ )
        insere_elemento(lista1, v[i]);

    imprime_lista(lista1);        
    
    remover_elemento(lista1, 45);
        imprime_lista(lista1);        

    remover_elemento(lista1, 4);
        imprime_lista(lista1);        


    return 0;
}