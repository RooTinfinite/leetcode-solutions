class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = -1; i < n; i++){

            vector<int> arr;

            for(int j = 0; j < n; j++){
                if(i == j) continue;
                arr.push_back(nums[j]);
            }

            int m = arr.size();

            if(m < 2) continue;

            vector<int> prefix(m);
            vector<int> suffix(m);

            prefix[0] = arr[0];

            for(int j = 1; j < m; j++){
                prefix[j] = gcd(prefix[j - 1], arr[j]);
            }

            suffix[m - 1] = arr[m - 1];

            for(int j = m - 2; j >= 0; j--){
                suffix[j] = gcd(suffix[j + 1], arr[j]);
            }

            int score = 0;

            for(int j = 0; j < m - 1; j++){
                if(prefix[j] == suffix[j + 1]){
                    score++;
                }
            }

            ans = max(ans, score);
        }

        return ans;
    }
};