#include <stdio.h>
#include <stdlib.h>
#include "listaCirc.h"

struct no{

    int info;
    struct no *prox;

};

Lista cria_lista(){

    return NULL;

}

int lista_vazia(Lista lst){

    if(lst == NULL) return 1;

    return 0;

}

int insere_elem(Lista *lst, int n){ //insere no final

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL) return 0;

    N->info = n;
    N->prox = N;

    if(lista_vazia(*lst)) *lst = N;    
    
    else{

        N->prox = (*lst)->prox; //N aponta para o primeiro no da lista
        (*lst)->prox = N; //ultimo no aponta para N
        *lst = N; //novo no vira ultimo

    }
    return 1;
    
}
int remove_elem(Lista *lst, int n){// remove no inicio 

    if(lista_vazia(*lst)) return 0;

    Lista aux = (*lst)->prox;
    Lista primeiro = aux;
    
    if(primeiro == *lst){ //se a lista so tem um no

        if(primeiro->info != n)
            return 0; // o elemento nao esta na lista

        free(primeiro);
        *lst = NULL;
        return 1;
    }

    while(aux->prox!=primeiro && aux->prox->info != n)
    aux = aux->prox;

    if(aux->prox == primeiro) return 0; //elem nao encontrado
        Lista temp = aux->prox;
        aux->prox = temp->prox;
        free(temp);


    return 1;
    
} 

void imprime_lista(Lista lst){

    if(lista_vazia(lst)){
        printf("{LISTA VAZIA}\n");
    }
    else{

        Lista aux = lst->prox;

        do{
            printf("[%d] ", aux->info);
            aux = aux->prox;
        }while(aux != lst->prox);
            
        printf("\n");

    }

}