#ifndef SORT_H
#define SORT_H

#include <stdint.h>

int* create_array1(uint64_t length);
enum array_ordering { RANDOM, SORTED, REVERSE_SORTED};
int* create_array2(uint64_t length, enum array_ordering order);

void swap (int *a, int *b);
int partition(int arr[], int start, int end);
int quicksort(int arr[], int start, int end);

int mid_partition(int arr[], int start, int end);
int mid_quicksort(int arr[], int start, int end);

int median_of_three_partition(int arr[], int start, int end);
int median_of_three_quicksort(int arr[], int start, int end);

#endif



