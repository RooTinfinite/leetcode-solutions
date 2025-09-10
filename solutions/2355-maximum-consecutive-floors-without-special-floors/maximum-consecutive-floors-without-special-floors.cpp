class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin() , special.end());
        int res = 0, prev = bottom - 1;
        for(int i = 0, n = special.size(); i < n; ++i){
            res = max(res , special[i] - prev - 1);
            prev = special[i];
        }
        return max(res , top - prev);
    }
};