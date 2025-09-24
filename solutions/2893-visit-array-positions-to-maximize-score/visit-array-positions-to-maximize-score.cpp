class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long odd = nums[0], even = nums[0];
        if(odd & 1) even -= x;
        else odd -= x;
        for(int i = 1, n = nums.size(); i < n; ++i){
            int num = nums[i];
            if(num & 1) odd = num + max(odd , even - x);
            else even = num + max(even , odd - x);
        }
        return max(even , odd);
    }
};