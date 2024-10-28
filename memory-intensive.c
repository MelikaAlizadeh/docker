#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 250000000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int *arr = (int *)malloc(SIZE * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }

    start = clock();

    quickSort(arr, 0, SIZE - 1);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted %d integers\n", SIZE);
    printf("Time taken: %f seconds\n", cpu_time_used);

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[i-1]) {
            printf("Sort failed!\n");
            break;
        }
    }

    free(arr);
    return 0;
}
