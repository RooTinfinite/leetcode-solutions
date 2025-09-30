class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int dd = 0, sd = 0;
        for(int i : nums){
            if(i / 10 != 0) dd += i;
            else sd += i;
        }
        return abs(dd - sd) > 0;
    }
};