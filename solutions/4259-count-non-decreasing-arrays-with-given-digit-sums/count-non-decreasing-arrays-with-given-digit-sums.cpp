class Solution{
public:
    int mod = 1e9 + 7;
    vector<int> numbersWithSum[55];

    void computesums(){
        for(int num = 0 ; num <= 5000 ; num++){
            int sum = 0;
            for(int curr = num ; curr > 0 ; curr /= 10){
                sum += curr % 10;
            }
            numbersWithSum[sum].push_back(num);
        }
    }
    
    int countArrays(vector<int> &digitsum){
        if(numbersWithSum[0].empty() == true) computesums();

        int n = digitsum.size();
        vector<int> prefixDP(5005 , 0);
        
        for(int pos = 0 ; pos < n ; pos++){
            vector<int> curr(5005 , 0);
            // try placing numbers whose sum of digits = digitsum[pos]
            for(int currNum : numbersWithSum[digitsum[pos]]){
                if(pos == 0){
                    curr[currNum] = 1;
                }
                else{
                    // find maximum PrevNumber with binary search
                    vector<int> &prevNumbers = numbersWithSum[digitsum[pos - 1]];
                    int maxIdx = upper_bound(prevNumbers.begin() , prevNumbers.end() , currNum) - prevNumbers.begin() - 1;
                    if(maxIdx >= 0) curr[currNum] = prefixDP[prevNumbers[maxIdx]];
                }
            }
            // compute prefix sum on DP[pos] and it will be used for DP[pos + 1]
            for(int num = 1 ; num <= 5000 ; num++) curr[num] = (curr[num] + curr[num - 1]) % mod;
            prefixDP = curr;
        }

        return prefixDP[5000];
    }
};