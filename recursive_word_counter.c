#include <stdio.h>

/**
 * Counts the number of words in a string using recursion.
 * @param str: The input string (sentence)
 * @return: The number of words found
 */
int countWords(char *str) {
    // Base case: End of string
    if (*str == '\0') return 0;

    // Logic: If current char is NOT space, AND (next is space OR end of string)
    // It means we found the end of a word.
    if (*str != ' ') {
        if (*(str + 1) == '\0' || *(str + 1) == ' ') { 
            return 1 + countWords(str + 1);
        }
    }
    
    // Move to the next character
    return countWords(str + 1);
}

int main() {
    char sentence[100];
    
    printf("--- Recursive Word Counter ---\n");
    printf("Enter a sentence: ");
    
    // Reads input until newline (allows spaces)
    scanf("%[^\n]", sentence);
    
    printf("Total words: %d\n", countWords(sentence));
    
    return 0;
}
