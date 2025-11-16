int* grayCode(int n, int* returnSize) {
    // there are 2 ^ n numbers in the Gray code sequence.
    int sequenceLength = 1 << n;
    *returnSize = sequenceLength;
    int* result = (int*)malloc(sizeof(int) * sequenceLength);
    for (int i = 0; i < sequenceLength; i++) {
        int num = i ^ i >> 1;
        result[i] = num;
    }
    return result;
}