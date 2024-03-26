#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(void) {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n],i;
    printf("Enter the elements of the array in sorted order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int x;
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}

