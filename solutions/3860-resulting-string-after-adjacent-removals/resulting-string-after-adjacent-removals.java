class Solution {
    public String resultingString(String s) {
        // Create a stack to process characters
        Stack<Character> st = new Stack<>();

        // Loop through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i); // Current character

            // If the stack is not empty, check with the top character
            if (!st.isEmpty()) {
                char top = st.peek(); // Top character of the stack

                /*
                 * Check if current character 'c' and top of stack 'top' satisfy any of these:
                 * 1. If c is 'a' and top is 'z' (special wraparound case)
                 * 2. If c is 'z' and top is 'a' (special wraparound case)
                 * 3. If c and top are adjacent characters in the alphabet
                 *    Example: c = 'd', top = 'e' or vice versa → |'d'-'a' - ('e'-'a')| = 1
                 */
                if ((c == 'a' && top == 'z') || 
                    (c == 'z' && top == 'a') || 
                    (Math.abs((c - 'a') - (top - 'a')) == 1)) {
                    // Pop the top character if any of the above conditions are met
                    st.pop();
                } else {
                    // Otherwise, push the current character to the stack
                    st.push(c);
                }
            } else {
                // If stack is empty, just push the current character
                st.push(c);
            }
        }

        // Build the resulting string from the characters remaining in the stack
        StringBuilder sb = new StringBuilder();
        while (!st.isEmpty()) {
            sb.append(st.pop()); // Pop characters and append to result
        }

        // Since characters were popped from stack (LIFO), reverse to get correct order
        return sb.reverse().toString();
    }
}