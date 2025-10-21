class Solution {
    public int minOperations(String s) {
        int ans = 0;
        for (char c : s.toCharArray()) {
            int dist = (26 - (c - 'a')) % 26;
            ans = Math.max(ans, dist);
        }
        return ans;
    }
}

