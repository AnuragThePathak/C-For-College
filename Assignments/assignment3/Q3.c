#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

bool *primes;

void sieveOfEratosthenes(int n) {
    primes[0] = false, primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = true;
            }
        }
    }
}

void outputPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!primes[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() {

    int n;
    scanf("%d", &n);

    primes = (bool *) malloc((n + 1) * sizeof(bool));

    sieveOfEratosthenes(n);
    outputPrimes(n);

    free(primes);
    return 0;
}

