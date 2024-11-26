class Solution {
public:
  int f(int curr,int prev,vector<int>& nums,int n){
			int t=nums[curr]+nums[prev];
			int i=lower_bound(nums.begin(),nums.end(),t)-nums.begin();
			if(i<n && nums[i]==t) return 1+f(i,curr,nums,n);
			return 1;
		}

		int lenLongestFibSubseq(vector<int>& nums) {
			int n=nums.size();
			int maxi=0;
			for(int prev2=0;prev2<n;prev2++){
				for(int prev1=prev2+1;prev1<n;prev1++){
					int temp=nums[prev1]+nums[prev2];
					int ind=lower_bound(nums.begin(),nums.end(),temp)-nums.begin();
					if(ind<n && nums[ind]==temp) maxi=max(maxi,2+f(ind,prev1,nums,n));
				}
			}
			return maxi;
		}
	};