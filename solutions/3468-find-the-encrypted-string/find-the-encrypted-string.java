class Solution {
    public String getEncryptedString(String s, int k) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            ans.append(s.charAt((i + k) % n));
        }
        return ans.toString();
    }
}