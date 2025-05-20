#include <stdio.h>
#include <stdlib.h>

int* quickSort(int* arr, int n) {
    int* result = (int*)malloc(n * sizeof(int));
    int* left = (int*)malloc(n * sizeof(int));
    int* equal = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    
    int pivot = arr[0];
    int l = 0, e = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) {
            left[l++] = arr[i];
        } else if (arr[i] == pivot) {
            equal[e++] = arr[i];
        } else {
            right[r++] = arr[i];
        }
    }

    int index = 0;
    for (int i = 0; i < l; i++) result[index++] = left[i];
    for (int i = 0; i < e; i++) result[index++] = equal[i];
    for (int i = 0; i < r; i++) result[index++] = right[i];

    free(left);
    free(equal);
    free(right);

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int* sorted = quickSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    free(arr);
    free(sorted);
    return 0;
}
