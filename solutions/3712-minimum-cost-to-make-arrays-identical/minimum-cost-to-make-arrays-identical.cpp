class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int len = arr.size();
        vector<int> tmp = arr;
        vector<int> dst = brr;
        
        long long raw = 0;
        for(int i = 0; i < len; i++) {
            raw += abs(1LL * arr[i] - brr[i]);
        }
        
        sort(tmp.begin(), tmp.end());
        sort(dst.begin(), dst.end());
        
        long long srt = k;
        for(int i = 0; i < len; i++) {
            srt += abs(1LL * tmp[i] - dst[i]);
        }
        
        return min(raw, srt);
    }
};