class Solution {
    public String rearrangeString(String s, char x, char y) {
        StringBuilder xc = new StringBuilder();
        StringBuilder yc = new StringBuilder();
        StringBuilder others = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (c == y) {
                yc.append(c);
            } else if (c == x) {
                xc.append(c);
            } else {
                others.append(c);
            }
        }
        
        return yc.toString() + others.toString() + xc.toString();
    }
}
