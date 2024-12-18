class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n=prices.size();
        int stack[500], top=0;
        stack[top]=n-1;
        vector<int> ans=prices;
        for(int i=n-2; i>=0; i--){
            while(top>=0 && prices[i]<prices[stack[top]])
                top--;
            if (top>=0) ans[i]-=prices[stack[top]];
            stack[++top]=i;
        }
        return ans;
    }
};