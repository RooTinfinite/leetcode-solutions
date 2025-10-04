class Solution {
public:
    int maxLength(vector<int>& nums) {
        int cnt=2, n=nums.size(), M=5*7*8*9;
        for(int i=0; i<n; i++){
            int x=nums[i];
            int P=x, L=x, G=x, y;
            for(int j=i+1; j<n && P<=M; j++){
                y=nums[j];
                P*=y;
                G=gcd(G, y);
                L=lcm(L, y);
                if (P==G*L) cnt=max(cnt, j-i+1);
                else break;
            }
        }
        return cnt;
    }
};