class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long peakelem = *max_element(nums.begin(),nums.end());
        long long asum = 0, dsum = 0;
        bool flag = true;
        for(int index = 0 ; index < nums.size() ; index++){
            if(nums[index]==peakelem){
                flag = false;
                continue;
            }
            if(flag) asum+=nums[index];
            else dsum+=nums[index];
        }
        if(asum>dsum) return 0;
        else if(dsum>asum) return 1;
        else return -1;
    }
};