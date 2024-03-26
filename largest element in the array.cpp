#include <stdio.h>

int main() {
    int size, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Invalid size of the array.\n");
        return 1;
    }
    
    int arr[size];
    
    printf("Enter %d elements of the array: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("The largest element of the array is: %d\n", max);
    
    return 0;
}
