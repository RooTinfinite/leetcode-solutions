class Solution {
public:
    bool canChange(string start, string target) {
        if (start == target) {
            return true;
        }
        int pending_L = 0;
        int waiting_R = 0;
        
        for (int i = 0; i < start.length(); i++) {
            char curr = start[i];
            char goal = target[i];
            if (curr == 'R') {
                if (pending_L > 0) {
                    return false;
                }
                waiting_R++;
            }
            if (goal == 'L') {
                if (waiting_R > 0) {
                    return false;
                }
                pending_L++;
            }
            if (goal == 'R') {
                if (waiting_R == 0) {
                    return false;
                }
                waiting_R--;
            }
            if (curr == 'L') {
                if (pending_L == 0) {
                    return false;
                }
                pending_L--;
            }
        }
        return pending_L == 0 && waiting_R == 0;
    }
};