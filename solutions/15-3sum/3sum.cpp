class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort array to handle duplicates and optimize searching
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        // Handle base cases
        if (nums.size() < 3 || nums[0] > 0) {
            return result;
        }
        
        // Fix first number and use two pointers for the remaining two numbers
        for (int i = 0; i < nums.size(); i++) {
            // Skip positive numbers as first element
            if (nums[i] > 0) {
                break;
            }
            
            // Skip duplicates for first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Use two pointers technique to find remaining two numbers
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for second number
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // Skip duplicates for third number
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers
                    left++;
                    right--;
                }
                else if (currentSum < 0) {
                    left++;  // Need larger numbers
                }
                else {
                    right--;  // Need smaller numbers
                }
            }
        }
        
        return result;
    }
};