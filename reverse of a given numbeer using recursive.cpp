#include <stdio.h>

int reverse(int num, int rev) {
    // Base case: When num becomes 0, return the reversed number
    if (num == 0) {
        return rev;
    } else {
        // Extract the last digit of num
        int digit = num % 10;
        // Update rev by multiplying it by 10 and adding the extracted digit
        rev = rev * 10 + digit;
        // Recursively call reverse with num/10 and updated rev
        return reverse(num / 10, rev);
    }
}

int main() {
    int num, reversed;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Initial call to reverse function with num and initial rev as 0
    reversed = reverse(num, 0);

    printf("The reverse of %d is %d\n", num, reversed);

    return 0;
}
