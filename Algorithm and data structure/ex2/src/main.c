#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "edit_distance.h"

#define MAX_LENGTH 500  
#define MAX_WORDS 100000    
#define MAX_SUGGESTIONS 5 // Maximum number of suggestions for each word

// Function to remove punctuation from a string
void strip_punctuation(char *s) {
    int i = 0, j = 0;
    char punctuation[] = " .,;:!?'\""; // List of punctuation characters
    
    // Loop through the string
    while (s[i]) {
        int is_punctuation = 0;
        for (int k = 0; punctuation[k]; k++) {
            // If the character is punctuation, replace it with a space
            if (s[i] == punctuation[k]) {
                is_punctuation = 1;
                s[j++] = ' ';
                break;
            }
        }
        // If not punctuation, keep the character
        if (!is_punctuation) {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the modified string
}

// Function to find the closest words from the dictionary based on edit distance
void find_closest_word(const char* word, char* dictionary[], int dict_size) {
    char* closest_words[MAX_SUGGESTIONS] = {NULL}; // Array to hold closest words
    int min_distances[MAX_SUGGESTIONS] = {MAX_LENGTH}; // Array to hold minimum distances

    // Loop through each word in the dictionary
    for (int i = 0; i < dict_size; i++) {
        int distance = edit_distance_dyn(word, dictionary[i]); // Calculate edit distance
        // Check if the current distance is smaller than the stored distances
        for (int k = 0; k < MAX_SUGGESTIONS; k++) {
            if (closest_words[k] == NULL || distance < min_distances[k]) {
                // Shift existing entries to make room for the new closest word
                for (int l = MAX_SUGGESTIONS - 1; l > k; l--) {
                    closest_words[l] = closest_words[l - 1];
                    min_distances[l] = min_distances[l - 1];
                }
                // Add the new closest word
                closest_words[k] = dictionary[i];
                min_distances[k] = distance;
                break;
            }
        }
    }

    // Open the output file for appending the results
    FILE *output_file = fopen("./data/output.txt", "a");
    if (output_file == NULL) {
        return; // Return if file cannot be opened
    }

    // Write the results to the output file
    fprintf(output_file, "--------------------------------------------------\n");
    fprintf(output_file, "word: %s\n", word);
    for (int i = 0; i < MAX_SUGGESTIONS; i++) {
        if (closest_words[i] != NULL) {
            fprintf(output_file, "suggestion %d: %s (Editing distance: %d)\n", i + 1, closest_words[i], min_distances[i]);
        }
    }

    fclose(output_file); // Close the output file
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary> <sentence to be corrected>\n", argv[0]);
        return EXIT_FAILURE; // Exit if incorrect number of arguments
    }

    char *dictionary_path = argv[1];
    char *correctme_path = argv[2];
    FILE *dict_file = fopen(dictionary_path, "r");
    FILE *correctme_file = fopen(correctme_path, "r");

    if (!dict_file) {
        fprintf(stderr, "Error opening dictionary\n");
        return EXIT_FAILURE; // Exit if dictionary file cannot be opened
    }

    if (!correctme_file) {
        fprintf(stderr, "Error opening correctme\n");
        return EXIT_FAILURE; // Exit if sentence file cannot be opened
    }

    // Allocate memory for the dictionary dynamically
    char **dictionary = malloc(MAX_WORDS * sizeof(char *));
    if (!dictionary) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE; // Exit if memory allocation fails
    }

    int dict_size = 0;
    char word[MAX_LENGTH];
    while (fgets(word, MAX_LENGTH, dict_file) != NULL && dict_size < MAX_WORDS) {
        // Remove newline character if it exists
        size_t len = strlen(word);
        if (word[len - 1] == '\n')
            word[len - 1] = '\0';
        // Store the word in the dictionary
        dictionary[dict_size] = strdup(word);
        if (!dictionary[dict_size]) {
            fprintf(stderr, "Memory allocation failed\n");
            return EXIT_FAILURE; // Exit if memory allocation fails
        }
        dict_size++;
    }

    clock_t start_time = clock(); // Start the clock to measure execution time
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, correctme_file) != NULL) {
        // Remove newline character if it exists
        size_t len = strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';
        strip_punctuation(line); // Remove punctuation from the line
        char *token = strtok(line, " ");
        while (token != NULL) {
            find_closest_word(token, dictionary, dict_size); // Find closest words for each token
            token = strtok(NULL, " ");
        }
    }
    clock_t end_time = clock(); // End the clock
    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Reading time: %.4f seconds\n", total_time); // Print the total time taken

    fclose(correctme_file); // Close the files
    fclose(dict_file);

    // Free the memory allocated for the dictionary
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return EXIT_SUCCESS;
}
