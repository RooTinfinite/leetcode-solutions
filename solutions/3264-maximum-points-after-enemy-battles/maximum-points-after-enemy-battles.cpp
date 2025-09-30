class Solution {
public:
    long long maximumPoints(vector<int>& e, int c) {
        sort(e.begin(), e.end());
        if (c < e[0]) return 0;
        long long a = c;
        for( int j = e.size() - 1;j > 0; --j)  a += e[j];
        return a / e[0];
    }
};