#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include "edit_distance.h"

#define MAX_LENGTH 10000
#define CACHE_SIZE 500
#define TEST_CASES 100

//---------------------------EDIT DISTANCE-----------------------------------

// Finds the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Recursive function to calculate the edit distance between two strings
int edit_distance(const char *s1, const char* s2) {
    // Base cases: if either string is empty, return the length of the other string
    if(strlen(s1) == 0)
        return strlen(s2);
    if(strlen(s2) == 0)
        return strlen(s1);

    // Recursive cases
    // No operation needed if the first characters of both strings are the same
    int d_no_op = (*s1 == *s2) ? edit_distance(s1 + 1, s2 + 1) : INT_MAX;

    // One operation needed for either insert or delete
    int d_canc = 1 + edit_distance(s1, s2 + 1); // Insertion
    int d_ins = 1 + edit_distance(s1 + 1, s2); // Deletion
    
    // Return the minimum of the three operations
    return min(d_no_op, min(d_canc, d_ins));
}

//---------------------------EDIT DISTANCE DYNAMIC PROGRAMMING----------------

// Helper function for the dynamic programming approach to calculate the edit distance
int edit_distance_dyn_helper(const char *s1, const char *s2, int **cache, int len1, int len2) {
    // Base cases: if either string is empty, return the length of the other string
    if(len1 == 0)
        return len2;
    if(len2 == 0)
        return len1;

    // If the value has already been calculated, return the stored value
    if (cache[len1][len2] != -1)
        return cache[len1][len2];
    
    // If the first characters of both strings are the same, no operation is needed
    if (s1[0] == s2[0]) {
        cache[len1][len2] = edit_distance_dyn_helper(s1 + 1, s2 + 1, cache, len1 - 1, len2 - 1);
    } else {
        // One operation needed for either insert, delete, or substitute
        int d_canc = 1 + edit_distance_dyn_helper(s1, s2 + 1, cache, len1, len2 - 1); // Insertion
        int d_ins = 1 + edit_distance_dyn_helper(s1 + 1, s2, cache, len1 - 1, len2); // Deletion
        
        cache[len1][len2] = min(INT_MAX, min(d_canc, d_ins));
    }

    return cache[len1][len2];
}

// Entry point for the dynamic programming approach to calculate the edit distance
int edit_distance_dyn(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Allocate memory for the cache
    int **cache = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        cache[i] = (int *)malloc((len2 + 1) * sizeof(int));
        for (int j = 0; j <= len2; j++) {
            cache[i][j] = -1;
        }
    }

    // Call the helper method to calculate the edit distance
    int distance = edit_distance_dyn_helper(s1, s2, cache, len1, len2);

    // Free the allocated memory for the cache
    for (int i = 0; i <= len1; i++) {
        free(cache[i]);
    }
    free(cache);

    return distance;
}
