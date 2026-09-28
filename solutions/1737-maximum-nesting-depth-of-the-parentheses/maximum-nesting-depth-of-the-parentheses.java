class Solution {
    public int maxDepth(String s) {
        int ans = 0;

        Stack<Character> st = new Stack<Character>();
        for (Character c : s.toCharArray()) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                st.pop();
            }
            
            ans = Math.max(ans, st.size());
        }
        
        return ans;
    }
}