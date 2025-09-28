class Solution {
    public int minAnagramLength(String s) {
        char[] chars = s.toCharArray();
        int[] letterCount = new int[26];
        for (int i = 0; i <= chars.length / 2; i++) {
            letterCount[chars[i] - 'a']++;
            if (chars.length % (i + 1) == 0 && isRepeatingAnagram(chars, i + 1, letterCount)) {
                return i + 1;
            }
        }
        return chars.length;
    }

    private boolean isRepeatingAnagram(char[] chars, int size, int[] matching) {
        for (int i = size; i <= chars.length - size; i += size) {
            int[] fingerPrint = new int[26];
            for (int j = i; j < i + size; j++) {
                if (matching[chars[j] - 'a'] < ++fingerPrint[chars[j] - 'a']) {
                    return false;
                }
            }
        }
        return true;
    }
}