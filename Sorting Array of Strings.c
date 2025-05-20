#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int count_distinct_characters(const char* str) {
    int count[26] = {0}, distinct = 0;
    for (int i = 0; str[i]; i++) {
        if (!count[str[i] - 'a']) {
            count[str[i] - 'a'] = 1;
            distinct++;
        }
    }
    return distinct;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = count_distinct_characters(a);
    int count_b = count_distinct_characters(b);
    if (count_a != count_b)
        return count_a - count_b;
    return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a != len_b)
        return len_a - len_b;
    return strcmp(a, b);
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}