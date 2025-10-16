class Solution {
public:
    bool isActiveAtTime(int t, const string& s, const vector<int>& order, int k) {
        int n = s.size();
        vector<bool> isStar(n, false);
        for (int i = 0; i <= t; ++i) {
            isStar[order[i]] = true;
        }
        long long invalidCount = 0, segmentLength = 0;
        for (int i = 0; i < n; ++i) {
            if (!isStar[i]) {
                ++segmentLength;
            } else {
                invalidCount += (segmentLength * (segmentLength + 1)) / 2;
                segmentLength = 0;
            }
        }
        if (segmentLength > 0) {
            invalidCount += (segmentLength * (segmentLength + 1)) / 2;
        }

        long long totalSubstrings = (long long)n * (n + 1) / 2;
        long long validSubstrings = totalSubstrings - invalidCount;

        return validSubstrings >= k;
    }

    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        int left = 0, right = n - 1, answer = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (isActiveAtTime(mid, s, order, k)) {
                answer = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;  
            }
        }

        return answer;
    }
};