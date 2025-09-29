class Solution {
public:
    int valueAfterKSeconds(int n, int k){
        int mod = 1e9 + 7;
        vector<int> Sum(n , 1);
        while(k--) 
            for(int i = 1 ; i < n ; i++)
                Sum[i] = (Sum[i] + Sum[i - 1]) % 1000000007;
        return Sum[n - 1];
    }
};