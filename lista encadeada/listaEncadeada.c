#include <stdlib.h>
#include <stdio.h>
#include "listaEncadeada.h"

struct no
{
    int info;
    struct no *prox;
};

Lista cria_lista(){

    return NULL;

}

int lista_vazia(Lista lst){

    if(lst == NULL){
        return 1; //lista vazia
    }

    return 0; // lista nao vazia

}

int lista_cheia(Lista lst){

    Lista no_temp = (Lista) malloc(sizeof(struct no)); //tenta alocar um nó

    if (no_temp == NULL){ // se nao der certo, lista cheia
        return 1;
    }

    free(no_temp); //caso a alocação der certo, liberar o espaço temporario no_temp

    return 0;

}

int insere_elemen(Lista* lst, int elem){
 
    //alocar um novo no

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL) return 0; //nao foi possivel alocar o no

    N->info = elem; //recebe o elemento a ser inserido
    N->prox = *lst; //recebe o endereço do primeiro no ATUAL

    *lst = N;

    return 1;
    
}