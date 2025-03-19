#include <stdio.h>

#define MAX 500 
int multiply(int x, int result[], int result_size) {
    int carry = 0;

    for (int i = 0; i < result_size; i++) {
        int prod = result[i] * x + carry;
        result[i] = prod % 10; 
        carry = prod / 10; 
    }

    while (carry) { 
        result[result_size] = carry % 10;
        carry /= 10;
        result_size++;
    }

    return result_size;
}

void extraLongFactorials(int n) {
    int result[MAX];
    result[0] = 1;
    int result_size = 1;

    for (int x = 2; x <= n; x++) {
        result_size = multiply(x, result, result_size);
    }
    for (int i = result_size - 1; i >= 0; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    extraLongFactorials(n);
    return 0;
}