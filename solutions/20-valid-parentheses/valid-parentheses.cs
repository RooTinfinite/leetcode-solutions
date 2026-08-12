public class Solution {
    private Dictionary<char, char> mappings;

    public Solution() {
        mappings = new Dictionary<char, char> {
            { ')', '(' }, { '}', '{' }, { ']', '[' }
        };
    }

    public bool IsValid(string s) {
        var stack = new Stack<char>();
        foreach (var c in s) {
            if (mappings.ContainsKey(c)) {
                char topElement = stack.Count == 0 ? '#' : stack.Pop();
                if (topElement != mappings[c]) {
                    return false;
                }
            } else {
                stack.Push(c);
            }
        }

        return stack.Count == 0;
    }
}