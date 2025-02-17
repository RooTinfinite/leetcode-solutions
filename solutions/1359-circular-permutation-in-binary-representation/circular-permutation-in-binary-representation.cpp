class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);//initialize DP vector
        int size = dp.size();//record the size since the size() is changing
        int exp = 1;//base exponent
        while(exp < n){//befor we reach n
            for(int i = size - 1; i >= 0; i--){
                dp.push_back(dp[i]);//append the mirror image(reverse) of the original DP vector to the end
            }
            size = dp.size();//update the new size while every copy&mirror paste doubles the size of the DP array
            for(int i = dp.size() / 2; i < dp.size(); i++){
                dp[i] += pow(2, exp);//add 2^exp to the rear half
            }
            exp++;
        }
		//parse the DP vector starting at 0 arbitrarily to let it start at `start`
        int index = find(dp.begin(), dp.end(), start) - dp.begin();
        vector<int> ret;
        int bound = (int)pow(2, n);
        for(int i = index; ret.size() < bound; i = (i + 1) % bound){
            ret.push_back(dp[i]);
        }
        return ret;
    }
};