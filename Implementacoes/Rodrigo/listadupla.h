
#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H
#define TAMANHONOME 32

typedef struct Lista{
    char nome[TAMANHONOME];
    int numero;
    struct Lista* prox;
    struct Lista* ant;
} Lista;

Lista* insere_comeco(char* nome, int numero, Lista* no);
Lista* insere_final(char* nome, int numero, Lista* no);
Lista* procura_por_nome(char* nome, Lista* no);
Lista* remove_por_nome(char* nome, Lista* no);
void libera_lista(Lista *no);
void mostra_lista(Lista* no);

#endif // LISTA_DUPLA_H