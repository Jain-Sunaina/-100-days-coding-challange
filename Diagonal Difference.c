#include <stdio.h>
#include <stdlib.h>
int diagonalDifference(int arr[100][100], int n) {
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    
    for (int i = 0; i < n; i++) {
        primaryDiagonalSum += arr[i][i];        
        secondaryDiagonalSum += arr[i][n - 1 - i]; 
    }
    return abs(primaryDiagonalSum - secondaryDiagonalSum);
}
int main() {
    int n;
    
    scanf("%d", &n);
    
    int arr[100][100];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int result = diagonalDifference(arr, n);
    printf("%d\n", result);
    return 0;
}
