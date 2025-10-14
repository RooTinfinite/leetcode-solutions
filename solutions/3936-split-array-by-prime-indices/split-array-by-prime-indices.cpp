class Solution {
public:
    bool isPrime(int n) {
        if(n<=1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i=5; i*i <= n; i+=6) {
            if(n % i == 0 || n % (i+2) == 0) {
                return false;
            }
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        vector<int> a, b;
        for(int i=0; i<nums.size(); i++) {
            if(isPrime(i)) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        long long ans = 0;
        long long aSum = 0, bSum = 0;
        for(int i=0; i<a.size(); i++) aSum += a[i];
        for(int i=0; i<b.size(); i++) bSum += b[i];
        ans = abs(aSum - bSum);
        return ans;
    }
};