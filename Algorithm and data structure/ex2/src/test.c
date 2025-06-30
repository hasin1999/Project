#include <stdio.h>
#include <assert.h>
#include "edit_distance.h"

//EDIT DISTANCE 
void test_edit_distance_empty_strings() {
    const char *s1 = "";
    const char *s2 = "";
    int distance = edit_distance(s1, s2);
    assert(distance == 0);
}

void test_edit_distance_first_string_empty() {
    const char *s1 = "";
    const char *s2 = "test";
    int distance = edit_distance(s1, s2);
    assert(distance == 4);
}

void test_edit_distance_second_string_empty() {
    const char *s1 = "prova";
    const char *s2 = "";
    int distance = edit_distance(s1, s2);
    assert(distance == 5);
}

void test_edit_distance_equal_strings() {
    const char *s1 = "hello";
    const char *s2 = "hello";
    int distance = edit_distance(s1, s2);
    assert(distance == 0);
}

void test_edit_distance_single_insertion() {
    const char *s1 = "cat";
    const char *s2 = "cart";
    int distance = edit_distance(s1, s2);
    assert(distance == 1);
}

void test_edit_distance_single_deletion() {
    const char *s1 = "cart";
    const char *s2 = "cat";
    int distance = edit_distance(s1, s2);
    assert(distance == 1);
}

void test_edit_distance_substitution() {
    const char *s1 = "faramir";
    const char *s2 = "angmar";
    int distance = edit_distance(s1, s2);
    assert(distance == 7);
}

void test_edit_distance_substitution2() {
    const char *s1 = "baggings";
    const char *s2 = "saruman";
    int distance = edit_distance(s1, s2);
    assert(distance == 11);
}

//EDIT DISTANCE DYNAMIC

void test_edit_distance_dyn_empty_strings() {
    const char *s1 = "";
    const char *s2 = "";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 0);
}

void test_edit_distance_dyn_first_string_empty() {
    const char *s1 = "";
    const char *s2 = "test";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 4);
}

void test_edit_distance_dyn_second_string_empty() {
    const char *s1 = "prova";
    const char *s2 = "";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 5);
}

void test_edit_distance_dyn_equal_strings() {
    const char *s1 = "hello";
    const char *s2 = "hello";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 0);
}

void test_edit_distance_dyn_single_insertion() {
    const char *s1 = "cat";
    const char *s2 = "cart";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 1);
}

void test_edit_distance_dyn_single_deletion() {
    const char *s1 = "cart";
    const char *s2 = "cat";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 1);
}

void test_edit_distance_dyn_substitution() {
    const char *s1 = "faramir";
    const char *s2 = "angmar";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 7);
}

void test_edit_distance_dyn_substitution2() {
    const char *s1 = "baggings";
    const char *s2 = "saruman";
    int distance = edit_distance_dyn(s1, s2);
    assert(distance == 11);
}

int main() {
    //tests for edit distance
    test_edit_distance_empty_strings();
    printf("test edit_distance_empty_strings: DONE !\n");
    test_edit_distance_first_string_empty();
    printf("test_edit_distance_first_string_empty: DONE !\n");
    test_edit_distance_second_string_empty();
    printf("test_edit_distance_second_string_empty: DONE !\n");
    test_edit_distance_equal_strings();
    printf("test edit_distance_equal_strings: DONE !\n");
    test_edit_distance_single_insertion();
    printf("test edit_distance_single_insertion: DONE !\n");
    test_edit_distance_single_deletion();
    printf("test edit_distance_single_deletion: DONE !\n");
    test_edit_distance_substitution();
    printf("test edit_distance_substitution: DONE !\n");
    test_edit_distance_substitution2();
    printf("test edit_distance_substitution2: DONE !\n");

    //tests for edit distance dynamic
    test_edit_distance_dyn_empty_strings();
    printf("test edit_distance_empty_strings: DONE !\n");
    test_edit_distance_dyn_first_string_empty();
    printf("test edit_distance_first_string_empty: DONE !\n");
    test_edit_distance_dyn_second_string_empty();
    printf("test edit_distance_second_string_empty: DONE !\n");
    test_edit_distance_dyn_equal_strings();
    printf("test edit_distance_equal_strings: DONE !\n");
    test_edit_distance_dyn_single_insertion();
    printf("test edit_distance_single_insertion: DONE !\n");
    test_edit_distance_dyn_single_deletion();
    printf("test edit_distance_single_deletion: DONE !\n");
    test_edit_distance_dyn_substitution();
    printf("test edit_distance_substitution: DONE !\n");
    test_edit_distance_dyn_substitution2();
    printf("test edit_distance_substitution2: DONE !\n");

    printf("\nALL THE TESTS ARE PASSED SUCCESSFULLY !\n");

    return 0;
}

