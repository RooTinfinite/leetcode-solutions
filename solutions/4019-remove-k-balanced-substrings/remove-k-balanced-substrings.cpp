class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<int> open_counts;
        vector<int> close_counts;
        int current_open = 0;
        int current_close = 0;
        string char_stack = "";
        
        for (char c : s) {
            char_stack += c;
            
            if (c == '(') {
                if (current_close != 0) {
                    close_counts.push_back(current_close);
                    open_counts.push_back(current_open);
                    current_close = 0;
                    current_open = 1;
                } else {
                    current_open++;
                }
            } else if (c == ')') {
                current_close++;
            }
            
            while (true) {
                if (current_close == k && current_open > k) {
                    for (int i = 0; i < 2 * k; i++) {
                        char_stack.pop_back();
                    }
                    current_open -= k;
                    current_close -= k;
                } else if (current_close == k && current_open == k) {
                    for (int i = 0; i < 2 * k; i++) {
                        char_stack.pop_back();
                    }
                    current_open -= k;
                    current_close -= k;
                    if (!char_stack.empty()) {
                        char last_char = char_stack.back();
                        if (last_char == '(') {
                            current_open = open_counts.back();
                            open_counts.pop_back();
                        } else {
                            current_open = open_counts.back();
                            open_counts.pop_back();
                            current_close = close_counts.back();
                            close_counts.pop_back();
                        }
                    }
                } else {
                    break;
                }
            }
        }
        
        return char_stack;
    }
};