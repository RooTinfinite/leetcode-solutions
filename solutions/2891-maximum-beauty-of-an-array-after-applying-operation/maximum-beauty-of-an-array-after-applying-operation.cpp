class Solution {
public:
    static int maximumBeauty(vector<int>& nums, int k) {
        auto [xMin, xMax]=minmax_element(nums.begin(), nums.end());
        const int a=*xMin, N=*xMax-a;
        vector<int> freq(N+1, 0);
        for(int x: nums)
            freq[x-a]++;
        
        int cnt=0, maxCnt=0;
        for(int l=0, r=0; r<=N; r++){
            cnt+=freq[r];
            if (r-l>2*k){
                cnt-=freq[l];
                l++;
            }
            maxCnt=max(maxCnt, cnt);
        }
        return maxCnt;
    }
};
