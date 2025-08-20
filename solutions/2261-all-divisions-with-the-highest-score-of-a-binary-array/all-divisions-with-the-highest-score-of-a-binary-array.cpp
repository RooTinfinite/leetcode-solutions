class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+1,0),right(n+1,0);
        for(int i=1; i<=n; i++){
            left[i]=left[i-1];
            if(nums[i-1]==0) left[i]+=1;
        }
        for(int i=n-1; i>=0; i--){
            right[i]=right[i+1];
            if(nums[i]==1) right[i]+=1;
        }
        int maxi=0;
        vector<int> ans;
        for(int i=0; i<=n; i++) maxi=max(maxi,left[i]+right[i]);
        for(int i=0; i<=n; i++){
            if(maxi==left[i]+right[i]) ans.push_back(i);
        }
        return ans;
    }
};