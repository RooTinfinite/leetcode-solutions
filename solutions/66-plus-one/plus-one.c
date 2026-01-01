int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int idx = digitsSize - 1; idx >= 0; --idx) {
        if (digits[idx] == 9)
            digits[idx] = 0;
        else {
            digits[idx]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    digits = realloc(digits, (digitsSize + 1) * sizeof(int));
    digits[0] = 1;
    for (int i = 1; i < digitsSize + 1; ++i) digits[i] = 0;
    *returnSize = digitsSize + 1;
    return digits;
}