//below class is to sort offers based on end time
class comparator{
    public: 
    bool operator()(const vector<int> &a, const vector<int> &b){
        if(a[1] < b[1]) return true;
        if(a[1] == b[1]){
            if(a[0] < b[0]) return true;
            else if(a[0] == b[0]){
                if(a[2] > b[2]) return true;
                return false;
            }
        }
        return false;
    }
};
//sort function ends

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int sz = offers.size();
        //sort the offers
        sort(offers.begin(), offers.end(), comparator());
        
        //dp[i+1] means the max profit incurred till time i
        vector<int> dp(n+1, 0);
        //why shifted by 1? think and write in the comments.
        
        int res = 0;
        
    //HOT ZONE STARTS...
        int j=0; //index for offers
        for(int i=0; i<n; i++){ 
            //we calculate max profit from time 0 to i

            dp[i+1] = dp[i-1+1]; //if no offer available for this second
//if there is an offer for this second, then try taking THAT OFFER (which is offers[j])
//and BEST POSSIBLE PROFIT BEFORE THAT (which is dp[before start of offers[j]])
            while(j<sz && offers[j][1] == i){
                dp[i+1] = max(dp[i+1], offers[j][2] + dp[offers[j][0]-1+1]); //shifted dp by 1
                res = max(dp[i+1], res);
                j++; //moving to the next offer
            }
        }
    //HOT ZONE ENDS.

        //return the result
        return res;
        

//         cout<<"DP\n";
//         for(int i=0; i<=n; i++) cout<<i<<','<<dp[i]<<endl;
        
    }
};