class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        const int n=nums.size();
        if (n<=2) return nums;
        vector<int> sufM(n), ans={nums[0]};
        int rMax=sufM.back()=nums.back();
        for(int i=n-2; i>=0; i--){
            rMax=max(rMax, nums[i]);
            sufM[i]=rMax;
        }
        int lMax=nums[0];
        for(int i=1; i<n-1; i++){
            const int x=nums[i];
            if (x>lMax || x>sufM[i+1]) ans.push_back(x);
            lMax=max(x, lMax);
        }
        ans.push_back(nums.back());
        return ans;   
    }
};