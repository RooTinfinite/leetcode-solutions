class Solution {
public:
    static bool checkEqualPartitions(vector<int>& nums, long long target) {
        const int n=nums.size(), bmask=(1<<n)-1;
        for(int mask=1; mask<=bmask; mask++){
            unsigned long long A[2]={1, 1};
            for(int i=0; i<n; i++){
                A[((mask>>i)&1)==1]*=nums[i];
            }
            if (A[0]==target && A[1]==target) return 1;
        }
        return 0;
    }
};