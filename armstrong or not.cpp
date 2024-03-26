#include <stdio.h>
#include <math.h>

int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * power(base, exponent - 1);
}

int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}

int isArmstrong(int num, int n) {
    if (num == 0)
        return 0;
    return pow(num % 10, n) + isArmstrong(num / 10, n);
}

int main() {
    int num, digits, sum;
    printf("Enter a number: ");
    scanf("%d", &num);

    digits = countDigits(num);
    sum = isArmstrong(num, digits);

    if (sum == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
