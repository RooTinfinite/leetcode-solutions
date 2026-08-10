class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> fq1,fq2,fq3;

        for(auto x:nums1){fq1[x]++; fq3[x]++;}
        for(auto x:nums2){fq2[x]++; fq3[x]++;}

        for(auto it:fq3){
            if(it.second%2==1) return -1;
        }

        int diff=0; int ans=0;
        for(auto it:fq3)
        {
            int freq = it.second;
            //both arrays must have fq/2 occurrences of this
            freq/=2;

            int x1 = fq1[it.first];
            if(x1==freq) continue; //if both arrays having same occurence then good

            diff+=(x1-freq);
            ans+= abs(x1-freq);
        }

        if(diff==0) return ans/2;

        return -1;

        
    }
};