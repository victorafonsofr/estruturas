#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaCab.h"

int main(){

    int v[] = {1, 2 ,4 , 5 ,6 ,78, 90, 120};


    Lista encadeada = cria_lista();

   /*                                 
   
   EX1: 
   
    imprime_lista(encadeada);
    
    for(int i = 0; i < 11; i++) 
        insere_elem(&encadeada, v[i]);
    
    imprime_lista(encadeada);
    
    remove_elem(&encadeada, 8);

    imprime_lista(encadeada);

    encadeada = cria_lista();
    imprime_lista(encadeada);
*/

    for(int i = 0; i < 7; i++) 
        insere_ord(encadeada, v[i]);
    
    imprime_lista(encadeada);

    insere_ord(encadeada, 150);
    imprime_lista(encadeada);

    insere_ord(encadeada, 3);
    imprime_lista(encadeada);
    
    insere_ord(encadeada, -2);
    imprime_lista(encadeada);


    return 0;
}


