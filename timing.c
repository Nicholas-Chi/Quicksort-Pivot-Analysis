#define _POSIX_C_SOURCE 199309L
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define TIMING_RESULT(DESCR, CODE) do { \
    struct timespec start, end; \
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); \
    CODE; \
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); \
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9; \
    printf("%25s took %7.1f ms\n", descr, elapsed * 1000); \
} while(0)

// write test cases here
void quicksort_speed(const char* descr, int sort(int*, int, int), uint64_t length) {
    int* array = create_array1(length);
    assert(array != NULL);
    TIMING_RESULT(descr, sort(array, 0, length - 1));
    free(array);
}

void quicksort_speed2(const char* descr, int sort(int*, int, int), uint64_t length, enum array_ordering order) {
    int* array = create_array2(length, order);
    assert(array != NULL);
    TIMING_RESULT(descr, sort(array, 0, length - 1));
    free(array);
}


int main(void) {
    // uint64_t n = 49152; // L1 cache size
    uint64_t n = 1000000;
    // uint64_t n = 10000;
    printf("Array size: %lu kB\n", n * sizeof(int) / 1024);
    // quicksort_speed("quicksort", quicksort, 1000000);
    quicksort_speed("warmup", quicksort, n);
    quicksort_speed("warmup", quicksort, n);
    quicksort_speed2("quicksort sorted", quicksort, n, SORTED);
    quicksort_speed2("quicksort reverse", quicksort, n, REVERSE_SORTED);
    quicksort_speed2("quicksort random", quicksort, n, RANDOM);

    quicksort_speed2("mid_quicksort sorted", mid_quicksort, n, SORTED);
    quicksort_speed2("mid_quicksort reverse", mid_quicksort, n, REVERSE_SORTED);
    quicksort_speed2("mid_quicksort random", mid_quicksort, n, RANDOM);

    quicksort_speed2("median_of_three_quicksort sorted", median_of_three_quicksort, n, SORTED);
    quicksort_speed2("median_of_three_quicksort reverse", median_of_three_quicksort, n, REVERSE_SORTED);
    quicksort_speed2("median_of_three_quicksort random", median_of_three_quicksort, n, RANDOM);

    return 0;
}