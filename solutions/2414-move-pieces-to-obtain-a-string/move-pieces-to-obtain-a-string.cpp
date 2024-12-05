class Solution {
public:
    bool canChange(string start, string target) {
        // Queue to store characters and indices from both strings
        queue<pair<char, int>> startQueue, targetQueue;

        // Record non-underscore characters and their indices
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        // If number of pieces don't match, return false
        if (startQueue.size() != targetQueue.size()) return false;

        // Compare each piece's type and position
        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            // Check character match and movement rules
            if (startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex))
                return false;
        }

        return true;
    }
};