#include <stdio.h>
#include <string.h>

int main() {
    char n[20];
    scanf("%s", &n);
    for (int i = 0; i < strlen(n); ++i) {
        printf("%c\n", n[i]);
    }
    printf("%lu", strlen(n));
    return 0;
}
