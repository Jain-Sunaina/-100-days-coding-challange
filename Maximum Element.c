#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int stack[MAX_SIZE], maxStack[MAX_SIZE];
int top = -1, maxTop = -1;

void push(int x) {
    stack[++top] = x;
    if (maxTop == -1 || x >= maxStack[maxTop]) {
        maxStack[++maxTop] = x;
    }
}

void pop() {
    if (top == -1) return;
    if (stack[top] == maxStack[maxTop]) {
        maxTop--;
    }
    top--;
}

int getMax() {
    return maxTop == -1 ? -1 : maxStack[maxTop];
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    while (n--) {
        int type, value;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &value);
            push(value);
        }
        else if (type == 2) {
            pop();
        }
        else if (type == 3) {
            printf("%d\n", getMax());
        }
    }
    return 0;
}