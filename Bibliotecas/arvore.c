#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Cria um novo nó com a valor fornecida
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

// Insere uma valor na árvore binária de busca
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    else if (valor > raiz->valor)
        raiz->direito = inserir(raiz->direito, valor);

    return raiz;
}

// Busca por uma valor na árvore
No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerdo, valor);
    else
        return buscar(raiz->direito, valor);
}

// Encontra o nó com o menor valor (usado na remoção)
No* encontrarMinimo(No* raiz) {
    while (raiz->esquerdo != NULL)
        raiz = raiz->esquerdo;
    return raiz;
}

// Remove uma valor da árvore
No* remover(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor) {
        raiz->esquerdo = remover(raiz->esquerdo, valor);
    } else if (valor > raiz->valor) {
        raiz->direito = remover(raiz->direito, valor);
    } else {
        // Caso com 1 ou nenhum filho
        if (raiz->esquerdo == NULL) {
            No* temp = raiz->direito;
            free(raiz);
            return temp;
        } else if (raiz->direito == NULL) {
            No* temp = raiz->esquerdo;
            free(raiz);
            return temp;
        }

        // Caso com 2 filhos
        No* temp = encontrarMinimo(raiz->direito);
        raiz->valor = temp->valor;
        raiz->direito = remover(raiz->direito, temp->valor);
    }

    return raiz;
}

// Rotação simples à esquerda
No* rotacionarEsquerda(No* raiz) {
    if (raiz == NULL || raiz->direito == NULL)
        return raiz;

    No* novaRaiz = raiz->direito;
    raiz->direito = novaRaiz->esquerdo;
    novaRaiz->esquerdo = raiz;
    return novaRaiz;
}

// Rotação simples à direita
No* rotacionarDireita(No* raiz) {
    if (raiz == NULL || raiz->esquerdo == NULL)
        return raiz;

    No* novaRaiz = raiz->esquerdo;
    raiz->esquerdo = novaRaiz->direito;
    novaRaiz->direito = raiz;
    return novaRaiz;
}

// Impressão em ordem (crescente)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerdo);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direito);
    }
}

// Libera a memória da árvore
void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}