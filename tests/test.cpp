#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "string_utils.h"

void test_reverseString() {
    char s1[20] = "hello";
    reverseString(s1);
    assert(strcmp(s1, "olleh") == 0);

    char s2[20] = "a";
    reverseString(s2);
    assert(strcmp(s2, "a") == 0);

    char s3[20] = "ab";
    reverseString(s3);
    assert(strcmp(s3, "ba") == 0);

    char s4[20] = "racecar";
    reverseString(s4);
    assert(strcmp(s4, "racecar") == 0); // palindrome

    printf("reverseString: ALL TESTS PASSED\n");
}

void test_toUpper() {
    char s1[20] = "hello";
    toUpper(s1);
    assert(strcmp(s1, "HELLO") == 0);

    char s2[20] = "HeLLo";
    toUpper(s2);
    assert(strcmp(s2, "HELLO") == 0);

    char s3[20] = "123abc!";
    toUpper(s3);
    assert(strcmp(s3, "123ABC!") == 0);

    printf("toUpper: ALL TESTS PASSED\n");
}

void test_resizeArray() {
    int *arr = (int *)malloc(3 * sizeof(int));
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    int *newArr = resizeArray(arr, 3, 5);

    // Should preserve first 3 elements
    assert(newArr[0] == 10);
    assert(newArr[1] == 20);
    assert(newArr[2] == 30);
    
    // The last two elements are uninitialized — we only check that memory exists.
    // Test shrinking
    int *shrunk = resizeArray(newArr, 5, 2);
    assert(shrunk[0] == 10);
    assert(shrunk[1] == 20);

    free(shrunk);

    printf("resizeArray: ALL TESTS PASSED\n");
}

int main() {
    printf("Running tests...\n\n");

    test_reverseString();
    test_toUpper();
    test_resizeArray();

    printf("\nAll tests completed successfully.\n");
    return 0;
}
