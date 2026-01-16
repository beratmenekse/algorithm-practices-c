#include <stdio.h>

/**
 * Prints the array elements in a formatted way.
 * Example output: {10, 20, 30}
 */
void printArray(int *array, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        // If it's the last element, don't print the comma
        if (i == size - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("}\n");
}

int main() {
    // Initialize the array
    int myNumbers[] = {5, 15, 25, 35, 45};
    
    // Calculate the number of elements in the array
    // sizeof(myNumbers) gives total bytes, sizeof(myNumbers[0]) gives bytes of one integer.
    int size = sizeof(myNumbers) / sizeof(myNumbers[0]);
    
    printf("Original Array:\n");
    printArray(myNumbers, size);
    
    // Pointer to the start of the array
    int *ptr = myNumbers;
    
    // Swap elements using pointer arithmetic
    // Iterate until the middle of the array
    for (int i = 0; i < size / 2; i++) {
        // Store the values temporarily
        int leftValue = *(ptr + i);
        int rightValue = *(ptr + size - 1 - i);
        
        // Swap them
        *(ptr + i) = rightValue;
        *(ptr + size - 1 - i) = leftValue;
    }
    
    printf("Reversed Array:\n");
    printArray(myNumbers, size);

    return 0;
}
