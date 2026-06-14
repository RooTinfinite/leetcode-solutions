class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();

        int minIdx = n, mini = 200;
        for(int i = 0; i < n; i++) {
            int val = capacity[i];

            if(val >= itemSize) {
                if(val < mini) {
                    minIdx = i;
                    mini = val;
                }
            }
        }

        if(minIdx == n) return -1;
        return minIdx;
    }
};