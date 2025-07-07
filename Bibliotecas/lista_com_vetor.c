#include <stdio.h>
#include <stdlib.h>
#include "lista_com_vetor.h"

void inicializar(Lista *lista){
    lista->tam=0;
    lista->capacidade=20;
    lista->itens = malloc(lista->capacidade * sizeof(int));
}
void inserir(Lista *lista, int valor){
    if(lista->tam == lista->capacidade ){
        lista->capacidade *=2;
        int *novo = realloc(lista->itens,lista->capacidade * sizeof(int));
        if(novo == NULL){
            printf("Erro ao alocar memória");
            free(lista->itens);
            exit(EXIT_FAILURE);
        }
        lista->itens = novo;
    }
    lista->itens[lista->tam++] = valor;
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
void libera_lista(Lista *lista){
    free(lista->itens);
    lista->itens = NULL;
    lista->tam = 0;
    lista->capacidade = 0;
}
void exibir_lista(Lista *lista){
    for(int i = 0;i<lista->tam;i++){
        printf("%2d ",lista->itens[i]);
    }printf("\n");
}

