#include <stdio.h>
#include <stdlib.h>
#include "lista_com_vetor.h"

void inicializar(Lista *lista){
    lista->tam=0;
}
void inserir(Lista *lista, int valor){
    if(lista->tam < MAX){
        lista->itens[lista->tam++] = valor;
    }else{
        printf("Lista cheia\n");
    }
}
void excluir(Lista *lista,int valor){
    for(int i=0;i<lista->tam;i++){
        if(lista->itens[i] == valor){
            for(int j = i;j<lista->tam-1;j++){
                lista->itens[j] = lista->itens[j+1];
            }
            lista->tam--;
            printf("Valor excluido com sucesso\n");
            return;
        }
    }
    printf("Valor não encontrado\n");
}

bool buscar(Lista *lista,int valor){
    for(int i=0;i<lista->tam;i++){
        if(lista->itens[i]==valor){
            return true;
        }
    }
    return false;
}
void exibirLista(Lista *lista){
    for(int i = 0;i<lista->tam;i++){
        printf("%2d ",lista->itens[i]);
    }printf("\n");
}

