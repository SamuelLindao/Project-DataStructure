//
// Created by lacer on 05/07/2025.
//

#include "mergesort.h"

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i =0 ; i < n1 ; i++) {
        L[i] = arr[start + i];
    }

    for (int i =0 ; i < n2 ; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int start, int end) {
    if (start < end) {
        int mid =  start + (end-start)/2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
}
