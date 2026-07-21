#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

struct no{
 
    struct no* ant;
    int info;
    struct no* prox;
    
};

Lista cria_lista(){

    return NULL;

}

int lista_vazia(Lista lst){

    if(lst == NULL) return 1;
    
    return 0;

}

int insere_elem(Lista *lst, int n){

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL) return 0;


    if(lista_vazia(*lst) == 1){
        N->ant = NULL;
        N->info = n;
        N->prox = NULL;

        *lst = N;

        return 1;
    }

    Lista aux = *lst;

    N->info = n;
    N->prox = aux;
    aux->ant = N;
    N->ant = NULL;
    *lst = N;

    return 1;



}

int remove_elem(Lista *lst, int n){

    if(lista_vazia(*lst) == 1) return 0;

    Lista aux = *lst;

    while(aux->prox != NULL && aux->info!=n)
        aux=aux->prox;
   
    //verificar se o elemento nao esta na lista ou se o aux aponta pra ele
    if(aux->info != n) return 0; //elemento nao encontrado
    if(aux->prox!=NULL) aux->prox->ant = aux->ant;
    if(aux->ant!=NULL) aux->ant->prox = aux->prox;
    if(aux == *lst) *lst = aux->prox;


    free(aux);
    return 1;

}


void imprime_lista(Lista lst){

    if(lista_vazia(lst)==1){
        printf("{LISTA VAZIA}\n");
    }else{

        Lista aux = lst;  

        while(aux != NULL){
            
            printf("[%d] ", aux->info);
            aux = aux->prox;

      }  

    }

}
