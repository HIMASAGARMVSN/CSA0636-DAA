#include <stdio.h>
int i;
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int n) {
    if (n <= 1) {
        return;
    }
    if (isPrime(n)) {
        printf("%d\n", n);
    }
    generatePrimes(n - 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    generatePrimes(n);
    return 0;
}
