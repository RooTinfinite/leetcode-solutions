import java.util.HashMap;

class Solution {
    public int numberOfSubstrings(String s, int k) {
        int ans = 0;
        int l = 0;
        HashMap<Character, Integer> d = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            d.put(c, d.getOrDefault(c, 0) + 1);
            
            while (d.get(c) == k) {
                d.put(s.charAt(l), d.get(s.charAt(l)) - 1);
                l++;
            }
            
            ans += l;
        }

        return ans;
    }
}