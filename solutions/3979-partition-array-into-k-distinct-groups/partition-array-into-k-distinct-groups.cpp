class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return false;
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        int g = n/k;
        for(auto i:m){
            if(i.second > g) return false;
        }
        return true;
    }
};