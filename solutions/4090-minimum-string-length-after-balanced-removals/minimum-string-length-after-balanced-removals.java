class Solution {
    public int minLengthAfterRemovals(String s) {
        Stack<Character> st = new Stack<>();
        int i = 0;
        while (i < s.length()) {
            while (!st.isEmpty() && s.charAt(i) != st.peek()) {
                if (i >= s.length()) break;
                st.pop();
                i++;
                if (i >= s.length()) break;
            }
            if (i < s.length()) st.push(s.charAt(i));
            i++;
        }
        return st.size();
    }
}