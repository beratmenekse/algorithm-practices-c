#include <stdio.h>

/**
 * Prints the elements of an array.
 * Output format: {e1, e2, e3}
 */
void printArray(int *array, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("}\n");
}

/**
 * Swaps two integers using pointers.
 */
void swap(int *a, int *b) {
    int tempA = *a;
    int tempB = *b;
    
    *a = tempB;
    *b = tempA;
}

/**
 * Sorts an array using the Bubble Sort algorithm.
 * Time Complexity: O(n^2)
 * Logic: Pushes the largest elements to the end step by step.
 */
void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        // Last i elements are already in place
        for(int j = 0; j < size - 1 - i; j++) {
            // Swap if the element found is greater than the next element
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/**
 * Performs Recursive Binary Search on a sorted array.
 * Returns the index of the target if found, otherwise returns -1.
 */
int binarySearch(int array[], int left, int right, int target) { 
    // Base case: If boundaries cross, element is not present
    if(left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;
    
    // Case 1: Target is present at mid
    if(target == array[mid]) {
        return mid;
    }
    
    // Case 2: Target is smaller than mid, it must be in the left subarray
    if(target < array[mid]) {
        return binarySearch(array, left, mid - 1, target);
    }
    
    // Case 3: Target is larger than mid, it must be in the right subarray
    return binarySearch(array, mid + 1, right, target);
}

int main() {
    // Initialize array
    int arr[] = {2, 31, 5, 576, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    // 1. Show Original Array
    printf("Original Array: ");
    printArray(arr, size);
    
    // 2. Sort the Array (Necessary for Binary Search)
    bubbleSort(arr, size);
    printf("Sorted Array:   ");
    printArray(arr, size);
    
    // 3. Get User Input
    printf("\nEnter the number you want to search: ");
    scanf("%d", &target);
    
    // 4. Perform Binary Search
    // Note: sending 'size - 1' as the 'high' index
    int value = binarySearch(arr, 0, size - 1, target);
    
    // 5. Display Results
    if(value == -1) {
        printf("Result: Element %d not found in the array.\n", target);
    } else {
        printf("Result: Element %d found at index %d (Position: %d).\n", target, value, value + 1);
    }
    
    return 0;
}
