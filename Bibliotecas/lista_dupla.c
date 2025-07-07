#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadupla.h"

ListaD* insere_comeco(char* nome, int numero, ListaD* no){
    ListaD* novo_no = (ListaD*)malloc(sizeof(ListaD));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória");
        exit(1);
    }
    strcpy(novo_no->nome, nome);
    novo_no->numero = numero;
    novo_no->prox = no;
    novo_no->ant = NULL;

    if (no != NULL) {
        no->ant = novo_no;
    }

    return novo_no;
}

ListaD* insere_final(char* nome, int numero, ListaD* no){
    if (no == NULL) {
        return insere_comeco(nome, numero, no);
    }
    ListaD* aux_no = no;
    ListaD* novo_no = (ListaD*)malloc(sizeof(ListaD));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória");
        exit(1);
    }
    strcpy(novo_no->nome, nome);
    novo_no->numero = numero;
    novo_no->prox = NULL;

    while (aux_no->prox != NULL){
        aux_no = aux_no->prox;
    }
    aux_no->prox = novo_no;
    novo_no->ant = aux_no;
    return no;
}

ListaD* procura_por_nome(char* nome, ListaD* no){
    if (no == NULL){
        return NULL;
    }
    while (no != NULL){
        if (strcmp(no->nome, nome) == 0){
            return no;
        }
        no = no->prox;
    }
    return NULL;
}

ListaD* remove_por_nome(char* nome, ListaD* no){
    ListaD* escolhido = procura_por_nome(nome, no);
    if (escolhido == NULL){
        return no;
    }
    if (escolhido == no){
        ListaD* prox_no = no->prox;
        free(escolhido);
        if (prox_no != NULL) {
            prox_no->ant = NULL;
        }
        return prox_no;
    }
    else{
        if (escolhido->ant != NULL) {
            escolhido->ant->prox = escolhido->prox;
        }
        if (escolhido->prox != NULL){
            escolhido->prox->ant = escolhido->ant;
        }
        free(escolhido);
        return no;
    }
}

void libera_lista_dupla(ListaD *no){
    while (no != NULL){
        ListaD* temp = no;
        no = no->prox;
        free(temp);
    }
}

void mostra_lista(ListaD* no){
    if (no == NULL){
        printf("LISTA VAZIA\n");
        return;
    }
    while (no != NULL){
        printf("NOME: %s\n", no->nome);
        printf("NUMERO: %d\n\n", no->numero);
        no = no->prox;
    }
}
