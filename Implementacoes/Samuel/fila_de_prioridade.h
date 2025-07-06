//
// Created by lacer on 06/07/2025.
//

#ifndef FILA_DE_PRIORIDADE_H
#define FILA_DE_PRIORIDADE_H

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
}MaxHeap;

void heapifyDown(MaxHeap *heap, int i);
void heapifyUp(MaxHeap *heap, int i);

MaxHeap *constroi_heap(int V[], int n);

void insert(MaxHeap *heap, int value);
int extractMax(MaxHeap *heap);


#endif //FILA_DE_PRIORIDADE_H
