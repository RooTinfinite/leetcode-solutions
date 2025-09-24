class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> dict1;

        int n = nums.size(), max_val = 0, left = 0;

        for (int right = 0; right < n; right++){
            dict1[nums[right]] += 1;
            max_val = max(max_val,dict1[nums[right]]);

            if (right-left+1-max_val > k){
                dict1[nums[left]] -= 1;
                left += 1;
            }
        }

        return max_val;
    }
};