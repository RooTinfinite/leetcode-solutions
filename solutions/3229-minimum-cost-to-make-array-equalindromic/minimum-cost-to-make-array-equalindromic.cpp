typedef long long ll;

class Solution {
public:
    // to check  for palindrome
    bool isPalindrome(ll x) {
        if(x == 0 || x < 10)
            return true;
        
        ll n = x, i = 0 ,rev = 0;
        while(n != 0) {
            ll r = n % 10;
            rev = rev*10 + r;
            n = n / 10;
        }
        
        if(rev == x)
            return true;
        return false;
    }

    // to get left and right nearest palindrome for median
    pair<ll, ll> findNearestPalindrome(ll median) {
        ll left = median-1, right = median;
        while(left > 0 && !isPalindrome(left)) {
            left--;
        }
        while(right <= 1e9 && !isPalindrome(right)) {
            right++;
        }
        return {left, right};
    }
    
    // find cost using binary search and prefix sum in log(n) time complexity
    ll findCost(vector<int>& nums, vector<ll> &pre, ll palin) {
        ll n = nums.size();
        ll cost = 0, sum = pre[n-1];

        // edge cases
        if(palin < nums[0])
            return sum - palin*n;
        if(palin > nums[n-1])
            return palin*n - sum;
        
        // binary search
        ll left = 0, right = n-1, i = 0;
        while(left <= right) {
            ll mid = (left + right) /2;
            if(nums[mid] <= palin) {
                i = mid;
                left = mid + 1;
            }
            else
                right = mid-1;
        }

        cost = (palin*(i+1) - pre[i]) + ((sum-pre[i]) - (n-i-1)*palin); // O(1)

        return cost;
    }
    
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n, 0);
        sort(nums.begin(), nums.end());

        // calculate prefix sum
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        ll median = nums[n/2];
        pair<ll, ll> pp = findNearestPalindrome(median);
        
        ll cost = LLONG_MAX;
        // check for left nearest neighbour palindrome
        if(isPalindrome(pp.first))
            cost = min(cost, findCost(nums, pre, pp.first));

        // check for rightt nearest neighbour palindrome
        if(isPalindrome(pp.second))
            cost = min(cost, findCost(nums, pre, pp.second));
        
        // check for all array elements
        for(int i = 0; i < nums.size(); i++) {
            if(isPalindrome(nums[i]))
                cost = min(cost, findCost(nums, pre, nums[i]));
        }
        
        return cost;
    }
};