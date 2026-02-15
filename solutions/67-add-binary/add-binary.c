// Helper function to reverse a string in place
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

// Adds two binary strings using bit manipulation and returns the result as a
// new binary string
char *addBinary(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;

    // Allocate memory for the result which could be maxLen + 1 characters plus
    // a null terminator
    char *result = malloc(maxLen + 2);
    if (!result) return NULL;
    result[maxLen + 1] = '\0';

    // Reverse both strings for easier processing from least significant bit to
    // most
    char *x = strdup(a);
    char *y = strdup(b);
    if (!x || !y) {
        free(result);
        free(x);
        free(y);
        return NULL;
    }
    reverseString(x);
    reverseString(y);

    int carry = 0;
    for (int i = 0; i <= maxLen; i++) {
        int bitA = i < lenA ? x[i] - '0' : 0;
        int bitB = i < lenB ? y[i] - '0' : 0;

        // Bitwise XOR for current bit sum and AND shifted left for carry
        int sum = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | (carry & (bitA ^ bitB));

        result[i] = sum + '0';  // Convert sum back to character
    }

    if (carry) {  // If there's a final carry
        result[maxLen] = carry + '0';
    }

    // Reverse the result to return to the original order
    reverseString(result);

    // Trim any leading zero if the string has more than one character
    if (result[0] == '0' && result[1] != '\0') {
        memmove(result, result + 1, strlen(result));
    }

    free(x);
    free(y);
    return result;
}