class Solution {
    public String addSpaces(String s, int[] spaces) {
        int i = 0, j = 0;
        StringBuilder res = new StringBuilder();
        
        while (i < s.length() && j < spaces.length) {
            if (i < spaces[j]) {
                res.append(s.charAt(i));
                i++;
            } else {
                res.append(' ');
                j++;
            }
        }
        
        if (i < s.length()) {
            res.append(s.substring(i));
        }
        
        return res.toString();
    }
}