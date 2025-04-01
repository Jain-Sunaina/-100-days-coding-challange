#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

char* isBalanced(char* s) {
    int len = strlen(s);
    char stack[MAX_LEN];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '{' || c == '[' || c == '(') {
            stack[++top] = c;
        } else {
      
            if (top == -1) {
                return "NO"; 
            }

            char top_char = stack[top--];

            if ((c == '}' && top_char != '{') || 
                (c == ']' && top_char != '[') || 
                (c == ')' && top_char != '(')) {
                return "NO";
            }
        }
    }

  
    if (top == -1) {
        return "YES";
    } else {
        return "NO"; 
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char s[MAX_LEN];
        scanf("%s", s); 
        printf("%s\n", isBalanced(s)); 
    }

    return 0;
}
