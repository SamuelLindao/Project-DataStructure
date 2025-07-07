#include "fila_de_prioridade.h"
#include <stdio.h>

static void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int pai(int i) {
    return (i - 1) / 2;
}

static int filho_esquerdo(int i) {
    return 2 * i;
}

static int filho_direito(int i) {
    return 2 * i + 1;
}

void desce_heap(fila_prioridade_t *fila, int i) {
    int esquerda = filho_esquerdo(i);
    int direita = filho_direito(i);
    int maior = i;

    if (esquerda < fila->tamanho && fila->dados[esquerda] > fila->dados[i]) {
        maior = esquerda;
    } else {
        maior = i;
    }

    if (direita < fila->tamanho && fila->dados[direita] > fila->dados[maior]) {
        maior = direita;
    }

    if (maior != i) {
        trocar(&fila->dados[i], &fila->dados[maior]);
        desce_heap(fila, maior);
    }
}

void sobe_heap(fila_prioridade_t *fila, int i) {
    while (i > 0 && fila->dados[pai(i)] < fila->dados[i]) {
        trocar(&fila->dados[i], &fila->dados[pai(i)]);
        i = pai(i);
    }
}

fila_prioridade_t *construir_heap(fila_prioridade_t *fila) {
    for (int i = fila->tamanho / 2; i >= 1; i--) {
        desce_heap(fila, i);
    }
    return fila;
}

void inserir_valor(fila_prioridade_t *fila, int valor) {
    if (fila->tamanho >= TAM_MAX) {
        printf("\nFila cheia");
        return;
    }
    fila->dados[fila->tamanho] = valor;
    sobe_heap(fila, fila->tamanho);
    fila->tamanho++;
}

int remover_maximo(fila_prioridade_t *fila) {
    if (fila->tamanho <= 0) {
        printf("\nFila vazia");
        return -1;
    }
    int maximo = fila->dados[0];
    trocar(&fila->dados[0], &fila->dados[fila->tamanho - 1]);
    fila->tamanho--;
    desce_heap(fila, 0);
    return maximo;
}
