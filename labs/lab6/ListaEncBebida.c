#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncBebida.h"

struct bebida{

    int cod;
    char nome[20];
    int volume;
    float preco;
    struct bebida *prox;

};

static int proximo_cod = 1;


ListaB cria_listab(){

    ListaB cab = (ListaB) malloc(sizeof(struct bebida));

    if(cab == NULL) return NULL;

    cab->prox = NULL;

    return cab;

}

int lista_vaziab(ListaB lst){

    if(lst->prox == NULL){
        return 1;
    }

    return 0;
}

int insere_elemb(ListaB lst, char nome[20], int volume, float preco ){

    ListaB N = (ListaB) malloc(sizeof(struct bebida));

    if(N == NULL) //alocacao deu errado
        return 0;
        
    N->cod = proximo_cod; //auto incremento

    proximo_cod++;

    strncpy(N->nome, nome, 19);
    N->nome[19] = '\0'; //preenche o final da linha

    N->volume = volume;
    N->preco = preco;

    //inserção no começo da lista

    N->prox = lst->prox;
    lst->prox = N;

    return 1;

}
int remove_elemb(ListaB lst, int cod){

    if (lista_vaziab(lst) == 1) return 0;
    

    ListaB aux = lst->prox;

    if(aux->cod == cod){
        lst->prox = lst->prox->prox;
        free(aux);
        return 1;
    }

    while((aux->prox != NULL) && (aux->prox->cod != cod))
        aux = aux->prox; 

        //while percorrido, ou o elemento ta na lista ou nao esta, aux parou no elemento ou nao;

    if(aux->prox == NULL) return 0; //parou no final e nao encontrou o elemento

    ListaB elem_removido = aux->prox;
    aux->prox = aux->prox->prox;


    free(elem_removido);

    return 1;


}
void imprime_listab(ListaB lst){

    

    if(lst == NULL)
        printf("{LISTA NAO ALOCADA}\n");
    
    else if(lista_vaziab(lst) == 1)
        printf("{LISTA VAZIA}\n");

    else{

        ListaB aux = lst->prox;
        
        while(aux != NULL){

            printf("Codigo: %d\n", aux->cod);
            printf("Nome: %s\n", aux->nome);
            printf("Volume: %dml\n", aux->volume);
            printf("Preco: $%.2f\n", aux->preco);

            aux = aux->prox;

        }

    }

}

