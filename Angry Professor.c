#include <stdio.h>

void angryProfessor(int n, int k, int arrivalTimes[]) {
    int onTimeCount = 0;
    for (int i = 0; i < n; i++) {
        if (arrivalTimes[i] <= 0) {
            onTimeCount++;
        }
    }
    if (onTimeCount >= k) {
        printf("NO\n");  
    } else {
        printf("YES\n"); 
    }
}
int main() {
    int t;
    scanf("%d", &t); 
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k); 
        int arrivalTimes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arrivalTimes[i]); 
        }
        angryProfessor(n, k, arrivalTimes);
    }
    return 0;
}