#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"

#define MAX 20

struct lista{

    int vet[MAX];
    int fim;

}; //tipo Lista

Lista cria_lista(){ //retorna um ponteiro de uma Lista


    Lista temp = (Lista) malloc(sizeof(struct lista));

    if(temp != NULL){
        temp->fim = 0;
        return temp;
    }
    return NULL;


}


int lista_vazia(Lista lst){

    if(lst != NULL){

        if (lst->fim == 0)
        {
            return 1;
        }

    }
    return 0;
    

}
int lista_cheia(Lista lst){

    if(lst != NULL){

        if(lst->fim == MAX){
        
            return 1;
        
        }
    }

    return 0;

}

int insere_elemento(Lista lst, int n){

    if(lst != NULL && lista_cheia(lst)!=1){

        lst->vet[lst->fim] = n;

        lst->fim++;

        return 1;
    }

    return 0;

}

void imprime_lista(Lista lst){

    for (int i = 0; i < lst->fim; i++)
    {
        if(i == 0){
            printf("{");
        }

        printf("%d, ",lst->vet[i]);

        if(i == (lst->fim)-1){
            printf("}\n");
        }

    }
        

}