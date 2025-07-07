#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Estrutura de um nó da árvore
typedef struct No {
    int valor;
    struct No* esquerdo;
    struct No* direito;
} No;

// Criação de um novo nó
No* criarNo(int valor);

// Inserção de valor
No* inserir(No* raiz, int valor);

// Busca de valor
No* buscar(No* raiz, int valor);

// Remoção de valor
No* remover(No* raiz, int valor);

// Rotação simples à esquerda
No* rotacionarEsquerda(No* raiz);

// Rotação simples à direita
No* rotacionarDireita(No* raiz);

// Impressão em ordem (in-order)
void emOrdem(No* raiz);

// Liberação de memória da árvore
void liberarArvore(No* raiz);

#endif // ARVORE_BINARIA_H
