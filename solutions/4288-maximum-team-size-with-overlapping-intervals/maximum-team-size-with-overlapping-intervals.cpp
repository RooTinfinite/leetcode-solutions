class Solution {
public:
    int maximumTeamSize(vector<int>& start, vector<int>& end) {
        int n = start.size();

        vector<int> sortedStart = start;
        vector<int> sortedEnd = end;

        sort(sortedStart.begin(), sortedStart.end());
        sort(sortedEnd.begin(), sortedEnd.end());

        int maxSize = 0;

        for (int i = 0; i < n; i++) {
            int a = upper_bound(sortedStart.begin(), sortedStart.end(), end[i]) - sortedStart.begin();
            int b = lower_bound(sortedEnd.begin(), sortedEnd.end(), start[i]) - sortedEnd.begin();

            maxSize = max(maxSize, a - b);
        }

        return maxSize;
    }
};