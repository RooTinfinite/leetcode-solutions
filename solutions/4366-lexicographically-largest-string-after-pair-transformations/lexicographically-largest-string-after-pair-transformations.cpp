class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<long long> convert(26, 0);
        long long base = 1;

        for(int i = 0; i < 26; i++){
            convert[i] = base;
            base *= 2;
        }

        vector<string> res;

        for(int n : nums){
            string cur = "";

            while(n > 0){
                int i = 25;

                while(convert[i] > n){
                    i--;
                }

                cur += (char)('a' + i);
                n -= convert[i];
            }

            res.push_back(cur);
        }

        return res;
    }
};