class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        if(indexDifference == 0 && valueDifference == 0) return {0 , 0};
        for(int i = 0, n = nums.size(); i < n; ++i){
            for(int j = i + indexDifference; j < n; ++j){
                if(abs(nums[i] - nums[j]) >= valueDifference) return {i , j};
            }
        }
        return {-1 , -1};
    }
};