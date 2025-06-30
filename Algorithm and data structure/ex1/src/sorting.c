#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

//------------------------------MERGE SORT---------------------------------------

//Function to merge two halves of an array into a single sorted array
static void merge(void *base, size_t left, size_t middle, size_t right, size_t size, int (*compar)(const void *, const void *)) {
    size_t i, j, k;
    size_t n1 = middle - left + 1; // Number of elements in the left half
    size_t n2 = right - middle;   // Number of elements in the right half

    // Allocate memory for temporary arrays L and R
    void *L = malloc(n1 * size);
    void *R = malloc(n2 * size); 

    // Check for memory allocation failure
    if (!L || !R) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    //copy data to temp arrays L[] and R[]
    char *left_ptr = (char *)base + left * size;
    char *right_ptr = (char *)base + (middle + 1) * size;
    for (i = 0; i < n1; i++)
        memcpy((char *)L + i * size, left_ptr + i * size, size);
    for (j = 0; j < n2; j++)
        memcpy((char *)R + j * size, right_ptr + j * size, size);

    //Merge the temporary arrays back into base[]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (compar((char *)L + i * size, (char *)R + j * size) <= 0) {
            memcpy((char *)base + k * size, (char *)L + i * size, size);
            i++;
        } else {
            memcpy((char *)base + k * size, (char *)R + j * size, size);
            j++;
        }
        k++;
    }

    //Copy remaining elements of L[]
    while (i < n1) {
        memcpy((char *)base + k * size, (char *)L + i * size, size);
        i++;
        k++;
    }

    //Copy remaining elements of R[]
    while (j < n2) {
        memcpy((char *)base + k * size, (char *)R + j * size, size);
        j++;
        k++;
    }
    // Free the temporary arrays
    free(L);
    free(R);
}

//Recursive helper function for merge sort
static void merge_sort_helper(void *base, size_t left, size_t right, size_t size, int (*compar)(const void *, const void *)) {
    if (left < right) {
        // Find the middle point
        size_t middle = left + (right - left) / 2;
        // Recursively sort the first and second halves
        merge_sort_helper(base, left, middle, size, compar);
        merge_sort_helper(base, middle + 1, right, size, compar);
        // Merge the sorted halves
        merge(base, left, middle, right, size, compar);
    }
}

//Main function to initiate merge sort
void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (!base || !compar) {
        exit(EXIT_FAILURE);
    }
    if (nitems > 1)
        merge_sort_helper(base, 0, nitems - 1, size, compar);
}

//--------------------------------QUICK SORT---------------------------------------

//Partition function for quicksort algorithm
static size_t partition(void *base, size_t low, size_t high, size_t size, int (*compar)(const void *, const void *)) {
    void *pivot = (char *)base + high * size;
    size_t i = low - 1;

    //partitioning the array
    for (size_t j = low; j <= high - 1; j++) {
        if (compar((char *)base + j * size, pivot) < 0) {
            //Swapping elements smaller than pivot
            i++;
            void *temp = malloc(size);
            if (!temp) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            memcpy(temp, (char *)base + i * size, size);
            memcpy((char *)base + i * size, (char *)base + j * size, size);
            memcpy((char *)base + j * size, temp, size);
            free(temp);
        }
    }

    //Moving pivot to its correct position
    void *temp = malloc(size);
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, (char *)base + (i + 1) * size, size);
    memcpy((char *)base + (i + 1) * size, (char *)base + high * size, size);
    memcpy((char *)base + high * size, temp, size);
    free(temp);

    return i + 1;
}

//Recursive helper function for quicksort
static void quick_sort_helper(void *base, size_t low, size_t high, size_t size, int (*compar)(const void *, const void *)) {
    if (low < high) {
        // Partitioning the array and recursively sorting partitions
        size_t pi = partition(base, low, high, size, compar);
        // Recursively sort elements before and after partition
        if (pi > 0)
            quick_sort_helper(base, low, pi - 1, size, compar);
        if (pi < high)
            quick_sort_helper(base, pi + 1, high, size, compar);
    }
}

//Main function to initiate quicksort
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) {
    if (!base || !compar) {
        exit(EXIT_FAILURE);
    }
    if (nitems > 1)
        quick_sort_helper(base, 0, nitems - 1, size, compar);
}
