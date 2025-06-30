#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

#define MAX_LINE_LENGTH 25

//definision of the record structure
typedef struct {
    int id;
    char field1[MAX_LINE_LENGTH];
    int field2;
    double field3;
} Record;

//This function is for compairing Record IDs
int compare_id(const void *a, const void *b) {
    const Record *record_a = (const Record *)a;
    const Record *record_b = (const Record *)b;
    return record_a->id - record_b->id;
}

//This function is for compairing field1
int compare_field1(const void *a, const void *b) {
    const Record *record_a = (const Record *)a;
    const Record *record_b = (const Record *)b;
    return strcasecmp(record_a->field1, record_b->field1);
}


//This function is for compairing field1
int compare_field2(const void *a, const void *b) {
    const Record *record_a = (const Record *)a;
    const Record *record_b = (const Record *)b;
    return record_a->field2 - record_b->field2;
}

//This function is for compairing field1
int compare_field3(const void *a, const void *b) {
    const Record *record_a = (const Record *)a;
    const Record *record_b = (const Record *)b;
    if (record_a->field3 < record_b->field3) return -1;
    if (record_a->field3 > record_b->field3) return 1;
    return 0;
}

//This function is for counting number of records
int count_records(FILE *infile) {
    int count = 0;
    char line[1000];
    while (fgets(line, sizeof(line), infile) != NULL) {
        count++;
    }
    rewind(infile); // Rewind the file to the beginning
    return count;
}


// Function to sort records based on the specified field and algorithm
void sort_records(FILE *infile, FILE *outfile, size_t field, size_t algo) {
    int num_records = count_records(infile);
    
    // Allocate memory for the record array
    Record *records = malloc(num_records * sizeof(Record));
    if (records == NULL) {
        exit(EXIT_FAILURE);
    }

    // Measure and print the reading time
    clock_t start_time = clock();
    num_records = 0;
    char line[1000];
    while (fgets(line, sizeof(line), infile) != NULL) {
        Record record;
        sscanf(line, "%d,%[^,],%d,%lf", &record.id, record.field1, &record.field2, &record.field3);
        records[num_records++] = record;
    }
    clock_t end_time = clock();
    double reading_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Reading time: %.2f seconds\n", reading_time);

    //field selection
    int (*compar)(const void *, const void *);
    switch (field) {
        case 1:
            compar = compare_field1;
            break;
        case 2:
            compar = compare_field2;
            break;
        case 3:
            compar = compare_field3;
            break;
        default:
            fprintf(stderr, "Invalid input, choose field 1, 2, or 3\n");
            exit(EXIT_FAILURE);
    }

    // Select the appropriate sorting algorithm
    void (*sorting_algorithm)(void *, size_t, size_t, int (*)(const void *, const void *));
    switch (algo) {
        case 1:
            sorting_algorithm = merge_sort;
            break;
        case 2:
            sorting_algorithm = quick_sort;
            break;
        default:
            fprintf(stderr, "Invalid input, select algorithm 1 (merge) or 2 (quick)\n");
            exit(EXIT_FAILURE);
    }

    // Measure and print the sorting time
    start_time = clock();
    sorting_algorithm(records, num_records, sizeof(Record), compar);
    end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorting time: %.2f seconds\n", execution_time);

    // Measure and print the writing time
    start_time = clock();
    for (int i = 0; i < num_records; i++) {
        fprintf(outfile, "%d,%s,%d,%.6f\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }
    end_time = clock();
    double writing_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Writing time: %.2f seconds\n\n", writing_time);

    printf("Total duration: %.2f seconds\n", reading_time + execution_time + writing_time);

    free(records);
}

int main(int argc, char *argv[]) {
    // Check the correct number of arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <sort_field> <sort_algorithm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file_input = argv[1];
    char *file_output = argv[2];
    size_t field = atoi(argv[3]);
    size_t algorithm = atoi(argv[4]);

    FILE *infile = fopen(file_input, "r");
    if (!infile) {
        fprintf(stderr, "Error opening input file %s\n", file_input);
        return EXIT_FAILURE;
    }

    FILE *outfile = fopen(file_output, "w");
    if (!outfile) {
        fprintf(stderr, "Error creating output file %s\n", file_output);
        fclose(infile); // Close the input file if error occurs
        return EXIT_FAILURE;
    }
    // Sort the records based on the specified field and algorithm
    sort_records(infile, outfile, field, algorithm);

    // Close the files after use
    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}