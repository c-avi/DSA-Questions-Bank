#include <stdio.h>
#include <stdlib.h>

char* getExcelColumnName(int n) {
    char temp[20]; // Temporary buffer to hold characters in reverse
    int index = 0;

    while (n > 0) {
        n--; // Adjust because Excel column indexing starts from 1
        temp[index++] = 'A' + (n % 26);
        n /= 26;
    }

    // Allocate memory for the final result (plus null terminator)
    char* result = (char*)malloc(index + 1);
    for (int i = 0; i < index; i++){
        result[i] = temp[index - i - 1]; // Reverse the characters
    }
    result[index] = '\0'; // Null-terminate the string
    
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    char* columnName = getExcelColumnName(n);
    printf("Excel Column Name: %s\n", columnName);

    free(columnName); // Free allocated memory
    return 0;
}