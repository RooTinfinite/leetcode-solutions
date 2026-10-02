/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize) {
    if (n == 0) {
        char **result = malloc(sizeof(char *));
        result[0] = malloc(sizeof(char));
        result[0][0] = '\0';
        *returnSize = 1;
        return result;
    }
    int length = 0, index = 0;
    char **result = NULL;
    for (int left_count = 0; left_count < n; ++left_count) {
        int left_size = 0;
        int right_size = 0;
        char **left_strings = generateParenthesis(left_count, &left_size);
        char **right_strings =
            generateParenthesis(n - 1 - left_count, &right_size);
        for (int i = 0; i < left_size; ++i) {
            for (int j = 0; j < right_size; ++j) {
                length +=
                    2 + strlen(left_strings[i]) + strlen(right_strings[j]);
                result = realloc(result, length * sizeof(char *));
                result[index] = malloc(2 + strlen(left_strings[i]) +
                                       strlen(right_strings[j]) + 1);
                sprintf(result[index], "(%s)%s", left_strings[i],
                        right_strings[j]);
                ++index;
            }
        }
        for (int i = 0; i < left_size; ++i) free(left_strings[i]);
        free(left_strings);
        for (int j = 0; j < right_size; ++j) free(right_strings[j]);
        free(right_strings);
    }
    *returnSize = index;
    return result;
}