class Solution {
public:
    bool check(vector<int> &nums, int len) {
        int n = nums.size(), minn = 0;
        
        for (int i = 0; i < n; i += len) {
            if (nums[i] < minn) return false;
            
            int maxx = nums[i];
            bool point = false;
            
            for (int j = i + 1; j < i + len; j++) {
                if (nums[j] < minn) return false;
                
                if (nums[j - 1] > nums[j]) {
                    if (point) return false;
                    point = true;
                }
                
                maxx = max(maxx, nums[j]);
            }
            
            // If rotated, last must be <= first
            if (point) {
                if (nums[i] < nums[i + len - 1]) return false;
            }
            
            minn = maxx;
        }
        
        return true;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            if (check(nums, k)) ans += k;
        }
        
        return ans;
    }
};