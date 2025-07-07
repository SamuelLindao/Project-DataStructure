#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadupla.h"

Lista* insere_comeco(char* nome, int numero, Lista* no){
    Lista* novo_no = (Lista*)malloc(sizeof(Lista));
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

Lista* insere_final(char* nome, int numero, Lista* no){
    if (no == NULL) {
        return insere_comeco(nome, numero, no);
    }
    Lista* aux_no = no;
    Lista* novo_no = (Lista*)malloc(sizeof(Lista));
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

Lista* procura_por_nome(char* nome, Lista* no){
    Lista* escolhido = NULL;
    if (no == NULL){
        return NULL;
    }
    else{
        while (no != NULL){
            if (strcmp(no->nome, nome) == 0){
                escolhido = no;
            }
            no = no->prox;
        }
    }
    return escolhido;

}

Lista* remove_por_nome(char* nome, Lista* no){

    Lista* aux_no = no;
    Lista* escolhido = procura_por_nome(nome, no);
    if (escolhido == NULL){
        return no;
    }
    if (escolhido == no){
        aux_no = no->prox;
        free(escolhido);
        aux_no->ant = NULL;
        return aux_no;
    }

    else{
        (escolhido->ant)->prox = escolhido->prox;
        if (escolhido->prox != NULL){
            (escolhido->prox)->ant = escolhido->ant;
        }
        free(escolhido);
        return no;
    }
}

void libera_lista(Lista *no){
    while (no != NULL){
        Lista* temp = no;
        no = no->prox;
        free(temp);
    }
}

void mostra_lista(Lista* no){
    if (no == NULL){
        printf("LISTA VAZIA\n");
    }
    else{
        do {
            printf("NOME: %s\n", no->nome);
            printf("NUMERO: %d\n\n", no->numero);
            no = no->prox;
        } while (no != NULL);
    }

}