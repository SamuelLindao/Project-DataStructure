//
// Created by lacer on 06/07/2025.
//

#include "fila_de_prioridade.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i)
{
    return (i-1)/2;
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

void heapifyDown(MaxHeap * heap, int i) {

    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap->size && heap->data[l] > heap->data[i]) {
        largest = l;
    }
    else {
        largest = i;
    }

    if (r < heap->size && heap->data[r] > heap->data[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        heapifyDown(heap, largest);
    }

}


void heapifyUp(MaxHeap * heap, int i) {
    while (i > 0 && heap->data[parent(i)] < heap->data[i]) {
        swap(&heap->data[i], &heap->data[parent(i)]);
        i = parent(i);
    }
}

MaxHeap *constroi_heap(MaxHeap *heap)
{

    for (int i = heap->size/2; i >= 1; i--) {
        heapifyDown(heap, i);
    }
    return heap;
}


void insert(MaxHeap *heap, int value)
{
    if (heap->size <= 0) {
        printf("\nEmpty Heap");
        return;
    }
    heap->data[heap->size] = value;
    heapifyUp(heap, heap->data[heap->size]);
    heap->size++;
}

int extractMax(MaxHeap *heap)
{
    if (heap->size <= 0) {
        printf("\nEmpty Heap");
        return -1;
    }
    int max = heap->data[0];
    swap(&heap->data[0], &heap->data[heap->size-1]);
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}