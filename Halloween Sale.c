#include <stdio.h>

int howManyGames(int p, int d, int m, int s) {
    int count = 0;
    int current_price = p;

    while (s >= current_price) {
        s -= current_price;
        count++;
        if (current_price - d >= m) {
            current_price -= d;
        } else {
            current_price = m;
        }
    }
    
    return count;
}

int main() {
    int p, d, m, s;
    scanf("%d %d %d %d", &p, &d, &m, &s);

    int result = howManyGames(p, d, m, s);
    printf("%d\n", result);
    
    return 0;
}
