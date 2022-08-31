#include <stdio.h>

#define MAX 200

long long int generateHash(const char input[MAX]) {
    const int x = 792, y = 8240;
    long long int hash = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        hash += (i + 1) * x * input[i] % y;
    }

    return hash;
}

int main() {

    char input[MAX];

    scanf("%[^\n]", input);

    printf("%lld\n", generateHash(input));

    return 0;
}

