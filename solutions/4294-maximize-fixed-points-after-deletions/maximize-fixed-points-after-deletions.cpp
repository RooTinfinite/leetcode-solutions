class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;

        // store {i - nums[i], nums[i]} where i-nums[i] is the number of 
        // elements to delete for nums[i] to be at corect index i
        for(int i = 0; i < n; i++){
            if(nums[i] <= i){
                v.push_back({i - nums[i], nums[i]});
            }
        }

        if(v.empty()) return 0;

        // sort by d, then by value
        sort(v.begin(), v.end());

        // LIS on values
        vector<int> lis;

        for(auto &p : v){
            int val = p.second;

            auto it = lower_bound(lis.begin(), lis.end(), val);
            if(it == lis.end()){ //bigger than all elements
                lis.push_back(val);
            } else { //replace with smaller number
                *it = val;
            }
        }

        return lis.size();
    }
};