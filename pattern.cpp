#include <stdio.h>

// Function to print the pattern recursively
void printPattern(int n, int i) {
    if (i > n) {  // Base case: stop recursion when i exceeds n
        return;
    }

    // Print the numbers from 1 to i
    for (int j = 1; j <= i; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Call the function recursively with the next value of i
    printPattern(n, i + 1);
}

int main() {
    int n = 6;
    printPattern(n, 1);  // Start printing pattern from i = 1
    return 0;
}
