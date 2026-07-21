#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeadaCab.h"

struct no {

    int data;
    struct no *prox;

};

Lista cria_lista(){

    Lista cab = (Lista) malloc(sizeof(struct no));
    
    if(cab != NULL){
        cab->prox = NULL;
        cab->data = 0;
        }

    return cab;

}

int lista_vazia(Lista lst){
    
    if(lst->data == 0) return 1;

    return 0;

}

int insere_elem(Lista lst, int n){

    Lista N = (Lista) malloc(sizeof(struct no)); //se cria um novo nó N

    if(N == NULL) 
        return 0;
    
    N->data = n;
    N->prox = lst->prox;
    lst->prox = N;

    lst->data ++;
    return 1;

}

int remove_elem(Lista lst, int n){

    if (lista_vazia(lst) == 1) return 0;

    Lista aux = lst->prox;

    if(aux->data == n){
        lst->prox = lst->prox->prox;
        free(aux);
        return 1;
    }

    while((aux->prox != NULL) && (aux->prox->data != n))
        aux = aux->prox; 

        //while percorrido, ou o elemento ta na lista ou nao esta, aux parou no elemento ou nao;

    if(aux->prox == NULL) return 0; //parou no final e nao encontrou o elemento

    Lista elem_removido = aux->prox;
    aux->prox = aux->prox->prox;


    free(elem_removido);

    return 1;


}

void imprime_lista(Lista lst){

    Lista aux = lst->prox;

    if(lista_vazia(lst) != 1){
        
        printf("{");

        while(aux != NULL){

            printf("%d, ", aux->data);
            aux = aux->prox;

        }

        printf("}\n");

    }else
        printf("{LISTA VAZIA}\n");

}


int insere_ord(Lista lst, int n){

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL) return 0;

    N->data = n;
    N->prox = NULL;

    if(lista_vazia(lst)==1 || n <= lst->prox->data){
        N->prox = lst->prox;
        lst->prox = N;

        lst->data++;
        return 1;
        //caso a info do primeiro nó seja <= n
    }
    
    Lista aux = lst->prox;

    while(aux->prox !=NULL && aux->prox->data <= n)
          aux = aux->prox;
    
    if(aux->prox == NULL){ //inserção no fim
        N->prox = NULL;
        aux->prox = N;
           
    }
    else{ //inserção no meio
        
        N->prox = aux->prox;
        aux->prox = N;
    }
    
    lst->data++;
    return 1;
    
    
    

}
int remove_ord(Lista lst, int n);

int ordenado(Lista lst){

    Lista aux = lst->prox;

    if(lista_vazia(lst) == 1) return 1;

    while(aux->prox != NULL && aux->data <= aux->prox->data){
        aux = aux->prox;
    }

    if(aux->prox == NULL) return 1; //ordenado
    else return 0;

}