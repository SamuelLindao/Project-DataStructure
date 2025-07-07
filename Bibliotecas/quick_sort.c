#include <stdio.h>
#include "quick_sort.h"

void trocar(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int v[],int ini,int fim){
    int pivo = v[fim];
    int i = ini-1;
    for(int j = ini;j<fim;j++){
        if(v[j] < pivo){
            i++;
            trocar(&v[i],&v[j]);
        }
    }
    trocar(&v[i+1],&v[fim]);
    return i+1; 
}
void quicksort(int v[],int ini,int fim){
    int pivo;
    if(ini < fim){
        pivo  = particiona(v,ini,fim);
        quicksort(v,ini,pivo-1);
        quicksort(v,pivo+1,fim);
    }
}
