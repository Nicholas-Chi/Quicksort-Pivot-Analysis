#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "sort.h"

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* create_array1(uint64_t length) {
    int* array = (int*)malloc(length * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    for (uint64_t i = 0; i < length; i++) {
        array[i] = rand() % 1000; // Fill with random integers
    }
    return array;
}

void reverse_array(int* arr, uint64_t length) {
    for (uint64_t i = 0; i < length / 2; i++) {
        swap(&arr[i], &arr[length - i - 1]);
    }
}

int* create_array2(uint64_t length, enum array_ordering order) {
    int* array = (int*)malloc(length * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    for (uint64_t i = 0; i < length; i++) {
        array[i] = rand() % 1000; // Fill with random integers
    }

    switch (order) {
    case RANDOM:
        // Already random
        break;  
    case SORTED:
        qsort(array, length, sizeof(int), comp);
        break;
    case REVERSE_SORTED:
        qsort(array, length, sizeof(int), comp);
        reverse_array(array, length);
        break;
    }
    return array;

}

int partition(int arr[], int start, int end) {
    // use last element as pivot
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j <= end -1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;
}

int quicksort(int arr[], int start, int end) {
    if (end <= start) {
        return 0;
    }
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
    return 0;
}

// lets use the middle element as pivot
int mid_partition(int arr[], int start, int end) {
    // use middle element as pivot
    int mid = start + (end - start) / 2;
    swap(&arr[mid], &arr[end]);
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;
}

int mid_quicksort(int arr[], int start, int end) {
    if (end <= start) {
        return 0;
    }
    int pivot = mid_partition(arr, start, end);
    mid_quicksort(arr, start, pivot - 1);
    mid_quicksort(arr, pivot + 1, end);
    return 0;
}

int median_of_three_partition(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;
    int pivot;
    // Find median of arr[start], arr[mid], arr[end]
    if (arr[start] > arr[mid]) {
        swap(&arr[start], &arr[mid]);
    }
    if (arr[start] > arr[end]) {
        swap(&arr[start], &arr[end]);
    }
    if (arr[mid] > arr[end]) {
        swap(&arr[mid], &arr[end]);
    }

    // move the median value to the end
    swap(&arr[mid], &arr[end]);
    pivot = arr[end];

    int i = start - 1;
    for (int j = start; j <= end -1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    return i+1;
}

int median_of_three_quicksort(int arr[], int start, int end) {
    if (end <= start) {
        return 0;
    }
    int pivot = median_of_three_partition(arr, start, end);
    median_of_three_quicksort(arr, start, pivot - 1);
    median_of_three_quicksort(arr, pivot + 1, end);
    return 0;
}

// int main(int argc, char *argv[]) {
//     int length = atoi(argv[1]);
//     int* arr = create_array2(length, REVERSE_SORTED);

//     // for (int i = 0; i < length; i++) {
//     //     printf("%d ", arr[i]);
//     // }
//     // printf("\n");
//     quicksort(arr, 0, length - 1);
//     // mid_quicksort(arr, 0, length - 1);
//     // printf("Sorted array: \n");
//     // for (int i = 0; i < length; i++) {
//     //     printf("%d ", arr[i]);
//     // }
//     // printf("\n");
//     free(arr);
//     return 0;
// }

