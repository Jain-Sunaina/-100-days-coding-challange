#include <stdio.h>
void reverse_array(int A[], int N) {
    int start = 0, end = N - 1;
  
    while(start < end) {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    int A[N];
    

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
   
    reverse_array(A, N);
    
   
    for(int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    
    return 0;
}