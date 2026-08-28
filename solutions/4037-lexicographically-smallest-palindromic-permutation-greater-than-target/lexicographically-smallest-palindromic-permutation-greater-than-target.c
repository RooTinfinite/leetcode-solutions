char* lexPalindromicPermutation(char* s, char* target) {
    int n = strlen(s);
    // Special case: length of 1
    if (n == 1) {
        if (strcmp(s, target) > 0) {
            char* result = (char*)malloc(2);
            strcpy(result, s);
            return result;
        }
        return "";
    }

    // Count the frequency of each character
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    // Check if it can form a palindrome and record the characters with odd
    // occurrences
    char oddChar = '\0';
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            // More than one character appears an odd number of times, cannot
            // form a palindrome
            if (oddChar != '\0') {
                return "";
            }
            oddChar = 'a' + i;
        }
        cnt[i] /=
            2;  // It takes only half the characters to construct the left half
    }

    char* prefix = (char*)malloc(n / 2 + 1);
    int prefix_len = 0;
    prefix[0] = '\0';

    // Construct the left part of each digit greedily
    for (int i = 0; i < n / 2; i++) {
        bool found = false;
        // Try to place the smallest character in lexicographical order
        for (int j = 0; j < 26; j++) {
            if (cnt[j] == 0) {
                continue;
            }

            cnt[j]--;

            // construct left
            char* left = (char*)malloc(n / 2 + 2);
            int left_len = 0;
            strcpy(left, prefix);
            left_len = prefix_len;
            left[left_len++] = 'a' + j;

            for (int k = 25; k >= 0; k--) {
                for (int m = 0; m < cnt[k]; m++) {
                    left[left_len++] = 'a' + k;
                }
            }
            left[left_len] = '\0';

            // construct palindrome
            int palindrome_len = left_len * 2 + 1;
            char* palindrome = (char*)malloc(palindrome_len + 1);
            strcpy(palindrome, left);
            int pos = left_len;
            if (oddChar != '\0') {
                palindrome[pos++] = oddChar;
            }
            for (int k = left_len - 1; k >= 0; k--) {
                palindrome[pos++] = left[k];
            }
            palindrome[pos] = '\0';

            if (strcmp(palindrome, target) > 0) {
                // If the constructed palindrome is greater than target, choose
                // the character
                prefix[prefix_len++] = 'a' + j;
                prefix[prefix_len] = '\0';
                found = true;
                free(left);
                free(palindrome);
                break;
            } else {
                cnt[j]++;  // Not meeting the conditions, reset the counter
                free(left);
                free(palindrome);
            }
        }
        if (!found) {
            free(prefix);
            return "";  // Cannot construct a palindrome larger than target
        }

        if (prefix[i] > target[i]) {  // prefix is already greater than target
            char* left = (char*)malloc(n / 2 + 1);
            strcpy(left, prefix);
            int left_len = prefix_len;
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < cnt[j]; k++) {
                    left[left_len++] = 'a' + j;
                }
            }
            left[left_len] = '\0';

            int palindrome_len = left_len * 2 + 1;
            char* palindrome = (char*)malloc(palindrome_len + 1);
            strcpy(palindrome, left);
            int pos = left_len;
            if (oddChar != '\0') {
                palindrome[pos++] = oddChar;
            }
            for (int k = left_len - 1; k >= 0; k--) {
                palindrome[pos++] = left[k];
            }
            palindrome[pos] = '\0';

            free(prefix);
            free(left);
            return palindrome;
        }
    }

    // Construct the final palindrome string
    int ans_len = prefix_len * 2 + 1;
    char* ans = (char*)malloc(ans_len + 1);
    strcpy(ans, prefix);
    int pos = prefix_len;
    if (oddChar != '\0') {
        ans[pos++] = oddChar;
    }
    for (int k = prefix_len - 1; k >= 0; k--) {
        ans[pos++] = prefix[k];
    }
    ans[pos] = '\0';

    free(prefix);
    return ans;
}