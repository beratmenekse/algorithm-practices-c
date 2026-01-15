#include <stdio.h>

/**
 * Helper function to convert negative numbers to positive.
 * GCD is always positive.
 */
int makePositive(int number) {
    if (number < 0) return -number;
    return number;
}

/**
 * Calculates the Greatest Common Divisor (GCD) using the Euclidean Algorithm.
 * Uses recursion instead of loops.
 * @param num1: First integer
 * @param num2: Second integer
 * @return: The GCD of num1 and num2
 */
int gcd(int num1, int num2) {
    // Convert inputs to positive absolute values
    num1 = makePositive(num1);
    num2 = makePositive(num2);

    // Determine logical big and small numbers for modulus
    int big = (num1 > num2) ? num1 : num2;
    int small = (num1 > num2) ? num2 : num1;

    // Base case: If the division has no remainder, we found the GCD.
    if (big % small == 0) return small;

    // Recursive step: Euclidean algorithm logic
    return gcd(small, big % small);
}

int main() {
    int input1, input2;
    
    printf("--- Recursive GCD (EBOB) Calculator ---\n");
    
    printf("Enter first number: ");
    scanf("%d", &input1);
    
    printf("Enter second number: ");
    scanf("%d", &input2);
    
    // Error handling for zero input
    if (input1 == 0 || input2 == 0) {
        printf("Error: GCD is undefined for 0.\n");
    } else {
        printf("GCD of %d and %d is: %d\n", input1, input2, gcd(input1, input2));
    }
    
    return 0;
}
