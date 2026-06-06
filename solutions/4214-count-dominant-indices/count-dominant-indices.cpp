class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        double sum=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum+=nums[i];
        }

        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>((double)sum/(n-i-1))){
                cnt++;
            }
            sum-=nums[i+1];
        }
        return cnt;
        
    }
};