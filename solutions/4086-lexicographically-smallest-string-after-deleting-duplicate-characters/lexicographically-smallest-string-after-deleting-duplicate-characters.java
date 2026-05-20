class Solution {
    public String lexSmallestAfterDeletion(String s) {
        char[] a = s.toCharArray();
        int[] rem = new int[26];
        for (char c : a) rem[c - 'a']++;

        int[] cnt = new int[26];
        StringBuilder sb = new StringBuilder();

        for (char c : a) {
            rem[c - 'a']--;
            while (sb.length() > 0) {
                char t = sb.charAt(sb.length() - 1);
                if (t > c && (rem[t - 'a'] > 0 || cnt[t - 'a'] > 1)) {
                    cnt[t - 'a']--;
                    sb.setLength(sb.length() - 1);
                } else break;
            }
            sb.append(c);
            cnt[c - 'a']++;
        }

        while (sb.length() > 0) {
            int i = sb.length() - 1;
            char c = sb.charAt(i);
            if (cnt[c - 'a'] > 1) {
                cnt[c - 'a']--;
                sb.setLength(i);
            } else break;
        }

        return sb.toString();
    }
}