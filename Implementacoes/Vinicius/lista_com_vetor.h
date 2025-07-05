#ifndef LISTA_COM_VETOR_H
#define LISTA_COM_VETOR_H

#include <stdbool.h>

#define MAX 1000

/**
 * @struct Lista
 * @brief  Lista de inteiros com tamanho máximo definido por MAX.
 * 
 * Campos:
 * - itens: array que armazena os valores inteiros
 * - tam: quantidade atual de elementos na lista
 */
typedef struct{
    int itens[MAX];
    int tam;
}Lista;

/**
 * @brief Inicializa a lista tornando seu tamanho zero.
 * 
 * @param lista ponteiro para a estrutura que será inicializada.
 */
void inicializar(Lista *lista);

/**
 * @brief Insere um valor no final da lista, se houver espaço.
 * 
 * @param lista Ponteiro para a estrutura do tipo Lista onde o valor será adicionado.
 * @param valor Valor inteiro que será adicionado. 
 */
void inserir(Lista *lista,int valor);

/**
 * @brief Exclui o primeiro valor indicado no parâmetro.
 * 
 * @param lista Ponteiro para a lista onde o valor será excluido.
 * @param valor Valor inteiro que será excluido.
 */
void excluir(Lista *lista,int valor);

/**
 * @brief Busca um valor na lista.
 * 
 * @param lista Ponteiro da lista onde será buscado.
 * @param valor Valor inteiro que será buscado.
 * @return true se o valor existir na lista; senão false.
 */
bool buscar(Lista *lista,int valor);

/**
 * @brief Exibe todos os elementos da lista.
 * 
 * @param lista Ponteiro da lista que será exibida.
 */
void exibirLista(Lista *lista);

#endif
