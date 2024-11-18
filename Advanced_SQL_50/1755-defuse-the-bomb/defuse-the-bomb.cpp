class Solution {
public:
int h(int k,vector<int>&code,int j,int n,int sign){
    int sum = 0;
    while(k){
        j = j + sign;
        if(j==-1) j= n-1;
        else if(j==n) j =0;
        sum+=code[j];
        k--;
    }
    return sum;
}
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0){
            return ans;
        }
        int sign = k>0?1:-1;


        for(int i=0;i<n;i++){
            ans[i] = h(abs(k),code,i,n,sign);
        }
        return ans;



    }
};