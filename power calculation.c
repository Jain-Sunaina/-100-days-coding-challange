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
char** split_string(char*);
int parse_int(char*);
long parse_long(char*);
long modular_exponentiation(long base, long exp, long mod) {
    long result = 1;
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod; 
    }
    return result;
}
char* solve(long k, long n) {
    long mod = 100;
    long S = 0;
    long powers[101]; 
    for (long i = 1; i <= 100; i++) {
        powers[i] = modular_exponentiation(i, n, mod);
    }
    if (k <= 100) {
        for (long i = 1; i <= k; i++) {
            S = (S + powers[i]) % mod;
        }
    } else {
        for (long i = 1; i <= 100; i++) {
            S = (S + powers[i]) % mod;
        }
        long complete_cycles = k / 100;
        S = (S * complete_cycles) % mod;
        for (long i = 1; i <= (k % 100); i++) {
            S = (S + powers[i]) % mod;
        }
    }
    char* result = malloc(4 * sizeof(char)); 
    snprintf(result, 4, "%02ld", S);
    return result;
}
int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    int t = parse_int(ltrim(rtrim(readline())));
    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));
        long k = parse_long(*(first_multiple_input + 0));
        long n = parse_long(*(first_multiple_input + 1));
        char* result = solve(k, n);
        fprintf(fptr, "%s\n", result);
        free(result); 
    }
    fclose(fptr);
    return 0;
}
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) {
            break;
        }
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) {
            data = '\0';
            break;
        }
    }
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);
        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }
    return data;
}
char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }
    if (!*str) {
        return str;
    }
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    return str;
}
char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }
    if (!*str) {
        return str;
    }
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}
char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    return value;
}
long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    return value;
}