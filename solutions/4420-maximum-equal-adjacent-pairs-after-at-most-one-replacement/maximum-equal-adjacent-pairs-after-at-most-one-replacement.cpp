class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int base_pairs= 0;
        map<pair<int, int>, int> pair_count;
        int max_new_pairs=0;

        for(int i =0; i<n-1;++i)
        {
            if(nums[i]==nums[i+1])
            {
                base_pairs++;
            }
            else
            {
                int u = min(nums[i],nums[i+1]);
                int v = max(nums[i], nums[i+1]);
                int count = ++ pair_count[{u,v}];
                if(count>max_new_pairs)
                {
                    max_new_pairs = count;
                }
            }
        }
        return base_pairs+max_new_pairs;
    }
};