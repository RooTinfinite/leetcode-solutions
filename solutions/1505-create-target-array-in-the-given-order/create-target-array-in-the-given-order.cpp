class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int j=0;j<index.size();j++)
        {
            res.insert(res.begin()+index[j],nums[j]);
        }
        return res;
    }
};