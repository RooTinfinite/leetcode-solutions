public class Solution {
    public string SimplifyPath(string path) {
        // Initialize a stack
        Stack<string> stack = new Stack<string>();
        string[] components = path.Split('/');
        // Split the input string on "/" as the delimiter
        // and process each portion one by one
        foreach (string directory in components) {
            // A no-op for a "." or an empty string
            if (directory.Equals(".") || directory.Length == 0) {
                continue;
            } else if (directory.Equals("..")) {
                // If the current component is a "..", then
                // we pop an entry from the stack if it's non-empty
                if (stack.Any()) {
                    stack.Pop();
                }
            } else {
                // Finally, a legitimate directory name, so we add it
                // to our stack
                stack.Push(directory);
            }
        }

        // Stich together all the directory names together
        StringBuilder result = new StringBuilder();
        foreach (string dir in stack.Reverse()) {
            result.Append("/");
            result.Append(dir);
        }

        return result.Length > 0 ? result.ToString() : "/";
    }
}