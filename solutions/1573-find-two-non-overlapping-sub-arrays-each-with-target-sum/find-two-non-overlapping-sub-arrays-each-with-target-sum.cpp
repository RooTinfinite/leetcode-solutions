class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int sum = 0; int s = 0; int n = arr.size();
        int curr = INT_MAX; int ans = INT_MAX;
        vector<int>best(n, INT_MAX);

        for(int i = 0; i<n; i++){
            sum += arr[i];
            while(sum > target) sum -= arr[s++];
            if(sum == target){
                if(s > 0 && best[s-1] != INT_MAX){
                    ans = min(ans , best[s-1] + i - s + 1);
                }
                curr = min(curr , i - s + 1);
            }
            best[i] = curr;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};