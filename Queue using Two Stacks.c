#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int main() {
    int q;
    scanf("%d", &q);
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < q; i++) {
        int type, value;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &value);
            queue[rear++] = value;
        } else if (type == 2) {       
            if (front < rear) {
                front++;
            }
        } else if (type == 3) {
            if (front < rear) {
                printf("%d\n", queue[front]);
            }
        }
    }
    return 0;
}