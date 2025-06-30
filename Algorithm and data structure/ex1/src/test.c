#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

// Comparison function for integers, used by sorting algorithms
int compare_int(const void *a, const void *b) {
    const int *int_a = (const int *)a;
    const int *int_b = (const int *)b;
    
    // Return -1 if int_a is less than int_b, 1 if greater, and 0 if equal
    if (*int_a < *int_b) {
        return -1;
    } else if (*int_a > *int_b) {
        return 1;
    } else {
        return 0; // values are equal
    }
}

// Test merge sort with an empty array
void test_merge_sort_empty_array() {
    int a[] = {};
    merge_sort(a, 0, sizeof(int), compare_int);
    // No assertions needed for an empty array
}

// Test merge sort with a single-element array
void test_merge_sort_single_element_array() {
    int a[] = {42};
    merge_sort(a, 1, sizeof(int), compare_int);
    assert(a[0] == 42); // The element should remain the same
}

// Test merge sort with an already sorted array
void test_merge_sort_sorted_array() {
    int a[] = {1, 2, 3, 4, 5};
    merge_sort(a, 5, sizeof(int), compare_int);
    // Verify each element is in its correct position
    for (int i = 0; i < 5; i++) {
        assert(a[i] == i + 1);
    }
}

// Test merge sort with a reverse sorted array
void test_merge_sort_reverse_sorted_array() {
    int a[] = {5, 4, 3, 2, 1};
    merge_sort(a, 5, sizeof(int), compare_int);
    // Verify the array is sorted correctly
    for (int i = 0; i < 5; i++) {
        assert(a[i] == i + 1);
    }
}

// Test quick sort with an empty array
void test_quick_sort_empty_array() {
    int a[] = {};
    quick_sort(a, 0, sizeof(int), compare_int);
    // No assertions needed for an empty array
}

// Test quick sort with a single-element array
void test_quick_sort_single_element_array() {
    int a[] = {42};
    quick_sort(a, 1, sizeof(int), compare_int);
    assert(a[0] == 42); // The element should remain the same
}

// Test quick sort with an already sorted array
void test_quick_sort_sorted_array() {
    int a[] = {1, 2, 3, 4, 5};
    quick_sort(a, 5, sizeof(int), compare_int);
    // Verify each element is in its correct position
    for (int i = 0; i < 5; i++) {
        assert(a[i] == i + 1);
    }
}

// Test quick sort with a reverse sorted array
void test_quick_sort_reverse_sorted_array() {
    int a[] = {5, 4, 3, 2, 1};
    quick_sort(a, 5, sizeof(int), compare_int);
    // Verify the array is sorted correctly
    for (int i = 0; i < 5; i++) {
        assert(a[i] == i + 1);
    }
}

int main() {
    // Run tests for merge sort
    test_merge_sort_empty_array();
    printf("test_merge_sort_empty_array: PASSED\n");
    test_merge_sort_single_element_array();
    printf("test_merge_sort_single_element_array: PASSED\n");
    test_merge_sort_sorted_array();
    printf("test_merge_sort_sorted_array: PASSED\n");
    test_merge_sort_reverse_sorted_array();
    printf("test_merge_sort_reverse_sorted_array: PASSED\n");
    
    // Run tests for quick sort
    test_quick_sort_empty_array();
    printf("test_quick_sort_empty_array: PASSED\n");
    test_quick_sort_single_element_array();
    printf("test_quick_sort_single_element_array: PASSED\n");
    test_quick_sort_sorted_array();
    printf("test_quick_sort_sorted_array: PASSED\n");
    test_quick_sort_reverse_sorted_array();
    printf("test_quick_sort_reverse_sorted_array: PASSED\n");

    printf("\nAll tests passed successfully!\n\n");

    return 0;
}
