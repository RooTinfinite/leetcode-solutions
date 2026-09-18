class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>mp;
        for(int i = 0;i < n;i++){
            mp[nums[i]].push_back(i);
        }
        int sol = 0;
        for(auto it : mp){
            if(it.second.size() >= 3){
                bool flag = true;
                n = it.second.size();
                int d1 = abs(it.second[1] - it.second[0]);
                for(int i = 1; i < n;i++){
                    if(abs(it.second[i] - it.second[i-1]) != d1){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    sol++;
                }
            }
        }
        return sol;
    }
};