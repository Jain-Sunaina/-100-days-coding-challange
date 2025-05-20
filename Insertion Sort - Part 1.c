#include <stdio.h>
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertionSort1(int n, int arr[]) {
    int key = arr[n - 1];  
    int i = n - 2;

    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i];
        printArray(arr, n);
        i--;
    }
    arr[i + 1] = key;
    printArray(arr, n);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertionSort1(n, arr);
    return 0;
}