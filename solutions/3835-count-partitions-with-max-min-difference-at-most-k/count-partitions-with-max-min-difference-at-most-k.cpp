typedef long long ll;
class Solution {
public:
    const static int mod = (1e9 + 7);
    vector<ll> prefix;
    ll getsum(int i, int j)
    {
        if (j == -1 || (i >= j)) return 0;
        ll b = prefix[j];
        ll a = (i <= -1) ? 0 : prefix[i];
        return (b + mod - a) % mod;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        prefix = vector<ll>(n, 0);
        deque<int> minq;
        deque<int> maxq;
        int last = -1;
        ll pre = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = nums[i];
            while (!minq.empty() && nums[minq.front()] < cur - k)
            {
                last = max(last, minq.front());
                minq.pop_front();
            }
            while (!maxq.empty() && nums[maxq.front()] > cur + k)
            {
                last = max(last, maxq.front());
                maxq.pop_front();
            }

            while (!minq.empty() && nums[minq.back()] > cur)
            {
                minq.pop_back();
            }
            while (!maxq.empty() && nums[maxq.back()] < cur)
            {
                maxq.pop_back();
            }

            minq.push_back(i);
            maxq.push_back(i);

            // ll p1 = last == -1 ? 1 : getsum(last - 1, last);
            ll p1 = last == -1 ? 1 : 0;
            ll sum = getsum(last - 1, i - 1) % mod;
            sum = (sum + p1) % mod;
            // cout << i << "," << last << "," << sum << endl;
            prefix[i] = sum + pre;
            pre = prefix[i];
            ans = sum;
        }
        return ans;
        
    }
};