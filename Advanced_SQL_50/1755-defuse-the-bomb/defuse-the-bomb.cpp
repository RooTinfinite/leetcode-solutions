class Solution {
public:
    vector<int> decrypt(vector<int>& circ, int k) {
        int n=circ.size();
        vector<int> ans(n, 0);
        if (k==0) return ans;
        if (k>0){
            int wsum=accumulate(circ.begin()+1, circ.begin()+k+1, 0);
            ans[0]=wsum;
            for(int l=1, r=k+1; l<n ; r++, l++){
                wsum+=-circ[l]+circ[r%n];
                ans[l]=wsum;
            }
            return ans;
        }
        k=-k;
        int wsum=accumulate(circ.end()-k , circ.end(), 0);
        ans[0]=wsum;
        for(int r=0, l=n-k; r<n-1; r++, l++){
            wsum+=-circ[l%n]+circ[r];
            ans[r+1]=wsum;
        }
        return ans;
    }
};