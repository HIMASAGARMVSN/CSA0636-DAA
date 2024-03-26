#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    if (*str == '\0')
        return;

    reverseString(str + 1);
    
    printf("%c", *str);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';

    printf("Reversed string: ");
    reverseString(str);
    printf("\n");

    return 0;
}