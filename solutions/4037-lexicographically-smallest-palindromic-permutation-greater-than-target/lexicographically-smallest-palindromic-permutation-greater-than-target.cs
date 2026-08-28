public class Solution {
    public string LexPalindromicPermutation(string s, string target) {
        int n = s.Length;
        // Special case: length of 1
        if (n == 1) {
            return string.Compare(s, target) > 0 ? s : "";
        }

        // Count the frequency of each character
        int[] cnt = new int[26];
        foreach (char c in s) {
            cnt[c - 'a']++;
        }

        // Check if it can form a palindrome and record the characters with odd
        // occurrences
        string oddChar = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                // More than one character appears an odd number of times,
                // cannot form a palindrome
                if (oddChar != "") {
                    return "";
                }
                oddChar = ((char)('a' + i)).ToString();
            }
            cnt[i] /= 2;  // It takes only half the characters to construct the
                          // left half
        }

        StringBuilder prefix = new StringBuilder();

        // Construct the left part of each digit greedily
        for (int i = 0; i < n / 2; i++) {
            bool found = false;
            // Try to place the smallest character in lexicographical order
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 0) {
                    continue;
                }

                cnt[j]--;
                if (Check(prefix.ToString(), (char)('a' + j), cnt, oddChar,
                          target)) {
                    // If the constructed palindrome is greater than target,
                    // choose the character
                    prefix.Append((char)('a' + j));
                    found = true;
                    break;
                } else {
                    cnt[j]++;  // Not meeting the conditions, reset the counter
                }
            }
            if (!found) {
                return "";  // Cannot construct a palindrome larger than target
            }

            if (prefix[i] >
                target[i]) {  // prefix is already greater than target
                StringBuilder left = new StringBuilder(prefix.ToString());
                for (int j = 0; j < 26; j++) {
                    left.Append(new string((char)('a' + j), cnt[j]));
                }
                char[] leftArr = left.ToString().ToCharArray();
                Array.Reverse(leftArr);
                string palindrome =
                    left.ToString() + oddChar + new string(leftArr);
                return palindrome;
            }
        }

        // Construct the final palindrome string
        char[] prefixArr = prefix.ToString().ToCharArray();
        Array.Reverse(prefixArr);
        string ans = prefix.ToString() + oddChar + new string(prefixArr);
        return ans;
    }

    private bool Check(string prefix, char c, int[] cnt, string oddChar,
                       string target) {
        StringBuilder left = new StringBuilder(prefix);
        left.Append(c);
        for (int i = 25; i >= 0; i--) {
            left.Append(new string((char)('a' + i), cnt[i]));
        }

        char[] leftArr = left.ToString().ToCharArray();
        Array.Reverse(leftArr);
        string palindrome = left.ToString() + oddChar + new string(leftArr);

        return string.Compare(palindrome, target) > 0;
    }
}