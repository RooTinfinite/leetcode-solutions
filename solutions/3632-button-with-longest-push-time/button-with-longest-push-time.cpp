class Solution {
public:
    vector<int> m;

    Solution() : m(100001, 0) {}

    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ans = -1;
        int index = -1;
        int prevTime = 0;

        for (int i = 0; i < events.size(); i++) {
            int button = events[i][0];
            int time = events[i][1];

            m[button] = time - prevTime;
            prevTime = time;

            if (m[button] > ans || (m[button] == ans && button < index)) {
                ans = m[button];
                index = button;
            }
        }

        return index;
    }
};