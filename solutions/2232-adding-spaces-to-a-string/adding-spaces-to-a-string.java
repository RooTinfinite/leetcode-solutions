class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder(s.length() + spaces.length);
        int prevSpace = 0;
        
        for (int i = 0; i < spaces.length; i++) {
            result.append(s.substring(prevSpace, spaces[i])).append(' ');
            prevSpace = spaces[i];
        }
        result.append(s.substring(prevSpace));
        return result.toString();
    }
}