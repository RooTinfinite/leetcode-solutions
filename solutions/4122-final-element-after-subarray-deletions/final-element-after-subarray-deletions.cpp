class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back()); 
    }
};