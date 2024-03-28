#include <stdio.h>

// Function to calculate the binomial coefficient
int binomialCoefficient(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

// Function to find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, k;
    printf("Enter the values of n and k for binomial coefficient calculation: ");
    scanf("%d %d", &n, &k);

    if (n < 0 || k < 0 || k > n) {
        printf("Invalid input.\n");
        return 1;
    }

    int result = binomialCoefficient(n, k);
    printf("Binomial coefficient C(%d, %d) = %d\n", n, k, result);

    return 0;
}
