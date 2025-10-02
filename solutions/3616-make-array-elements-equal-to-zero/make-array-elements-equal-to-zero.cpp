class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int index = 0;
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            left += nums[i];
            if (nums[i] == 0) {
                index = i;
                break;
            }
        }
        
        for (int i = index; i < nums.size(); i++) right += nums[i];        

        int count = 0;
        for (int i = index; i < nums.size(); i++) {
            left += nums[i];
            right -= nums[i];
            
            if (nums[i] != 0) continue;
            
            if (left == right) count += 2;
            else if (left - 1 == right || left + 1 == right) count += 1;
        }
        
        return count;
    }
};