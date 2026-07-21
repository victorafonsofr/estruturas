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

int insere_ordenado(Lista lst, int n){

    if(lst == NULL || lista_cheia(lst)==1) return 0;

    if(lista_vazia(lst) == 1) lst->vet[lst->fim] = n;
    
    else{

        if((n<lst->vet[0]) || ((lst->vet[0] < n) && ((lst->vet[(lst->fim)-1] ) > n) ) ){

            //deslocar elementos e colocar na posicao certa
            int i = lst->fim;

            while(i > 0){

                if(n < lst->vet[i-1]){
                    lst->vet[i] = lst->vet[i-1];
                    i--;
                }else{ //pode ser que essa condição nao aconteça no loop, já que não é possivel acessar a posicao -1

                    lst->vet[i] = n;
                }

            }
            lst->vet[i] = n;
            //inserir ao final caso saia do loop se n < vet[0]

        }else{

            lst->vet[lst->fim] = n; // inserir ao final se n for maior que todos os elementos

        }

    }
    lst->fim ++;
    return 1;

}

void excluir_lista(Lista* Plst){ //ponteir de ponteiro, se limpa primeiro o endereço do ponteiro depois esvazia seu conteudo que é um ponteiro

    free(*Plst); //limpa a lista

    *Plst = NULL; //se usa nulo pois mesmo apos o free, *Plst continua com um endereço

}

int remover_elemento(Lista lst, int n) {
    if (lst == NULL || lista_vazia(lst) == 1) return 0;

    // ultimo elemento
    if (lst->vet[lst->fim - 1] == n) {
        lst->fim--;
        return 1;
    }

    // Busca nas demais posições
    int aux = 0;
    while (aux < lst->fim - 1) {
        if (lst->vet[aux] == n) {
            // Desloca a partir de aux
            for (int i = aux; i < lst->fim - 1; i++) {
                lst->vet[i] = lst->vet[i + 1];
            }
            lst->fim--;
            return 1;
        }
        aux++;
    }

    return 0; // não encontrado
}