#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

char* twoArrays(int k, int n, int A[], int B[]) {

    qsort(A, n, sizeof(int), compare_asc);
    qsort(B, n, sizeof(int), compare_desc);

    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int q;
    scanf("%d", &q);  
    
    for (int i = 0; i < q; i++) {
        int n, k;
        scanf("%d %d", &n, &k);  
        
        int A[n], B[n];
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[j]);
        }
        printf("%s\n", twoArrays(k, n, A, B));
    }
    return 0;
}
