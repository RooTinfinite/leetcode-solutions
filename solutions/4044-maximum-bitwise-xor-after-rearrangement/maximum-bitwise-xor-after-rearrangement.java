class Solution {
    public String maximumXor(String s, String t) {
        int zeros = 0;
        for (char chr : t.toCharArray()) zeros += chr == '0' ? 1 : 0;
        int ones = t.length() - zeros;

        StringBuilder result = new StringBuilder();
        result.ensureCapacity(s.length());

        for (char chr : s.toCharArray()) {
            if ((chr == '1' && zeros != 0) || (chr == '0' && ones != 0)) {
                result.append('1');
                zeros -= (chr == '1') ? 1 : 0;
                ones  -= (chr == '0') ? 1 : 0;
            } else {
                result.append('0');
                ones  -= (chr == '1') ? 1 : 0;
                zeros -= (chr == '0') ? 1 : 0;
            }
        }
        return result.toString();
    }
}