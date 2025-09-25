class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int Sum=0;

        for(int i=0;i<=nums.size()-1;++i){
            if(__builtin_popcount(i)==k) Sum+=nums[i];
        }

        return Sum;
    }
};