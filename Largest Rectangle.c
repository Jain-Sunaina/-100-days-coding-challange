#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

long largestRectangle(int h[], int n) {
    long max_area = 0;
    int *stack = (int *)malloc(n * sizeof(int));  
    int top = -1;  
    int i;

    for (i = 0; i < n; i++) {
        
        while (top != -1 && h[stack[top]] > h[i]) {
            int height = h[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1; 
            long area = (long)height * width;
            if (area > max_area) {
                max_area = area;
            }
        }
        
        stack[++top] = i;
    }

    while (top != -1) {
        int height = h[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;  
        long area = (long)height * width;
        if (area > max_area) {
            max_area = area;
        }
    }

    free(stack);  
    
    return max_area;
}

int main() {
    int n;
 
    scanf("%d", &n);
    int h[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    
    long result = largestRectangle(h, n);
    
    printf("%ld\n", result);
    
    return 0;
}