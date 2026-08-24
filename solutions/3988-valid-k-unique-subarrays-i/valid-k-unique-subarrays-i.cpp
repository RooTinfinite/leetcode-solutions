class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        
        unordered_set<int> global_set;
        int max_val = 0;
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] ^ nums[i];
            global_set.insert(nums[i]);
            if(nums[i] > max_val) max_val = nums[i];
        }
        int global_distinct = global_set.size();

        vector<bool> ans;
        ans.reserve(queries.size());
        map<pair<int,int>, bool> memo;

        vector<int> seen(max_val + 1, 0);
        int query_id = 0;

        for(const auto& q : queries){
            int l = q[0];
            int r = q[1];
            
            if(memo.count({l,r})){
                ans.push_back(memo[{l,r}]);
                continue;
            }
            
            int len = r - l + 1;

            if(len % 2 != 0){
                memo[{l,r}] = false;
                ans.push_back(false);
                continue;
            }
            if(len < 2 * k){
                memo[{l,r}] = false;
                ans.push_back(false);
                continue;
            }
            if((pref[r+1] ^ pref[l]) != 0){
                memo[{l,r}] = false;
                ans.push_back(false);
                continue;
            }

            query_id++;
            int cnt = 0;
            bool is_val = true;
            
            for(int i = l; i <= r; i++){
                if(seen[nums[i]] != query_id){
                    seen[nums[i]] = query_id;
                    cnt++;
                    
                    if(cnt > k){
                        is_val = false;
                        break;
                    }
                    if(cnt == k && global_distinct <= k){
                        break;
                    }
                }
            }
            
            if(is_val && cnt == k){
                memo[{l,r}] = true;
                ans.push_back(true);
            }
            else{
                memo[{l,r}] = false;
                ans.push_back(false);
            }
        }
        return ans;
    }
};