class Solution {
    public int minTimeToType(String word) {
        int ans = word.length();
        int cur = 1;
        for (int i = 0; i < word.length(); i++) {
            int pos = word.charAt(i) - 96;
            int diff = Math.abs(pos - cur);
            ans += Math.min(diff, 26 - diff);
            cur = pos;
        }
        return ans;
    }
}