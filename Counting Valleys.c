#include <stdio.h>
#include <string.h>

int countingValleys(int steps, char *path) {
    int seaLevel = 0, valleys = 0;
    
    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            seaLevel++;
            if (seaLevel == 0) {
                valleys++;
            }
        } else {
            seaLevel--;
        }
    }
    
    return valleys;
}

int main() {
    int steps;
    char path[1000001]; 

    scanf("%d", &steps);
    scanf("%s", path);

    int result = countingValleys(steps, path);
    printf("%d\n", result);

    return 0;
}