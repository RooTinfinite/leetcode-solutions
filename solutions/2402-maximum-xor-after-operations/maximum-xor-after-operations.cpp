class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> bits(32,0);
        for(int &i:nums) {
            for(int j=31;j>=0;j--) {
                if((i>>j)&1) {
                    bits[j]++;
                }
            }
        }
        int res = 0;
        for(int i=0;i<32;i++) {
            if(bits[i]) {
                res = res | 1<<i;
            }
        }
        return res;
    }
};