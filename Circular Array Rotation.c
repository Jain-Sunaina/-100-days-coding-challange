#include <stdio.h>

void circularArrayRotation(int arr[], int n, int k, int queries[], int q) {
    k = k % n; 
    for (int i = 0; i < q; i++) {
        int index = (queries[i] - k + n) % n; 
        printf("%d\n", arr[index]);
    }
}

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int queries[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &queries[i]);
    }

    circularArrayRotation(arr, n, k, queries, q);
    
    return 0;
}