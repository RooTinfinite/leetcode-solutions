class Solution {
private:
    unordered_map<char, char> mappings;

public:
    Solution() {
        mappings[')'] = '(';
        mappings['}'] = '{';
        mappings[']'] = '[';
    }
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (mappings.find(c) != mappings.end()) {  // closing bracket
                // get the top element of the stack, if stack is empty, set a
                // dummy value '#'
                char topElement = stk.empty() ? '#' : stk.top();
                stk.pop();
                // if the mapping for this bracket doesn't match the stack's top
                // element, return false.
                if (topElement != mappings[c]) {
                    return false;
                }
            } else {  // opening bracket
                stk.push(c);
            }
        }
        return stk.empty();
    }
};