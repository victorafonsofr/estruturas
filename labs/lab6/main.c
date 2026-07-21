#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeada.h"
#include "ListaEncBebida.h"

int main(){

    int v[] = {4, 8 ,-1 , 19 ,2 ,7, 8, 5, 9, 22, 45};


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


// EX3

ListaB bebidas = cria_listab();

//valores temporarios

int op = 0, cod;
char tNome[20];
int tVolume;
float tPreco;

do{

    printf("[1] Inserir registro\n");
    printf("[2] Apagar ultimo registro\n");
    printf("[3] Imprimir dados\n");
    printf("[4] Sair\n");
    printf(">> ");
    scanf("%d",&op);

    printf("\n");

    while (getchar() != '\n'); //consome os espaços com salto de linha


    switch (op)
    {
    case 1:
        
        printf("Digite o nome: ");
        fgets(tNome, sizeof(tNome), stdin);
        tNome[strcspn(tNome, "\n")] = '\0'; //tira o /n e coloca um terminador nulo

        printf("\n");

        printf("Entre com o volume: ");
        scanf("%d",&tVolume);
        printf("\n");

        printf("Entre com o preco: ");
        scanf("%f",&tPreco);
        printf("\n");

        insere_elemb(bebidas, tNome, tVolume, tPreco);

        break;
    case 2:
        
        printf("Entre com o codigo da bebida a ser removida: ");
        scanf("%d",&cod);
        printf("\n");
        remove_elemb(bebidas, cod);
        break;
    case 3:
        imprime_listab(bebidas);
        break;
    case 4:
        printf("saindo...\n");
        break;
    
    default:
        break;
    }

}while (op != 4);


    return 0;
}


