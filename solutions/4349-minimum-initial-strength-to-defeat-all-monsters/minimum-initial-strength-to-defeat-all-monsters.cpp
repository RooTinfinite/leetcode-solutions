class Solution {
public:
    bool check(long long mid, vector<int>& monsters, vector<long long>& prefix){
        long long curr = mid;

        for(int i = 0; i < monsters.size(); i++){
            long long total = curr + prefix[i];

            if(total >= monsters[i])
                curr = max(0LL, curr - monsters[i]);
            else
                return false;
        }

        return true;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {

        vector<long long> diff(monsters.size() + 1, 0);

        for(auto &b : boosts){
            diff[b[0]] += b[2];
            diff[b[1] + 1] -= b[2];
        }

        for(int i = 1; i < diff.size(); i++)
            diff[i] += diff[i - 1];

        long long l = 0;
        long long h = 1000000000000000000LL;
        long long ans = -1;

        while(l <= h){
            long long mid = l + (h - l) / 2;

            if(check(mid, monsters, diff)){
                ans = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};