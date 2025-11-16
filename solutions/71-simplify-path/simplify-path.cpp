class Solution {
public:
    string simplifyPath(string path) {
        // Initialize a stack
        vector<string> stack;
        // Used for split string by '/'
        stringstream ss(path);
        string temp;
        while (getline(ss, temp, '/')) {
            // If the current component is a "..", then
            // we pop an entry from the stack if it's non-empty
            if (temp == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (temp != "." && !temp.empty()) {
                // Finally, a legitimate directory name, so we add it
                // to our stack
                stack.push_back(temp);
            }
        }
        // Construct simplified path
        string res = "";
        for (auto str : stack) res += "/" + str;
        if (res.empty())
            return "/";
        else
            return res;
    }
};