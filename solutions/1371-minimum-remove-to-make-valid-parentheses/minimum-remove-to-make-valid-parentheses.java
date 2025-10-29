
class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder();
        int open = 0;
        for (int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if (c == '('){ open++; sb.append(c); }
            else if (c == ')'){
                if (open == 0) continue;
                open--; sb.append(c);
            } else sb.append(c);
        }
        if (open == 0) return sb.toString();
        StringBuilder res = new StringBuilder();
        for (int i = sb.length() - 1; i >= 0; i--) {
            char c = sb.charAt(i);
            if (c == '(' && open > 0) { open--; continue; }
            res.append(c);
        }
        return res.reverse().toString();
    }
}