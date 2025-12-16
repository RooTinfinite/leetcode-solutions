class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum = 0;
        int idx = -1;
        int n = balance.size();

        for(int i = 0; i < n; i++){
            sum += balance[i];
            if(balance[i] < 0) idx = i;
        }

        if(sum < 0) return -1;
        if(idx == -1) return 0;

        long long val = balance[idx];
        int left = (idx - 1 + n) % n;
        int right = (idx + 1) % n;
        long long ans = 0;
        int dist = 1;

        while(val < 0){
            if(balance[left] > 0){
                long long take = min((long long)balance[left], -val);
                val += take;
                ans += take * dist;
            }

            if(val < 0 && balance[right] > 0){
                long long take = min((long long)balance[right], -val);
                val += take;
                ans += take * dist;
            }

            left = (left - 1 + n) % n;
            right = (right + 1) % n;
            dist++;
        }

        return ans;
    }
};