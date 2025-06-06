#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), compare);

    int min_unfairness = INT_MAX;
    for (int i = 0; i <= arr_count - k; i++) {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < min_unfairness) {
            min_unfairness = unfairness;
        }
    }

    return min_unfairness;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));
    int k = parse_int(ltrim(rtrim(readline())));

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(ltrim(rtrim(readline())));
        arr[i] = arr_item;
    }

    int result = maxMin(k, n, arr);
    fprintf(fptr, "%d\n", result);

    fclose(fptr);
    free(arr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    if (!data) return NULL;

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, (int)(alloc_length - data_length), stdin);

        if (!line) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);

        if (!data) return NULL;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) return NULL;
    while (isspace((unsigned char)*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return NULL;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
