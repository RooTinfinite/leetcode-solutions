#include <vector>
#include <algorithm>
#include <numeric> // for gcd
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long max_ele=0;
        vector<long long> prefixGcd;
        vector<long long> sample;
        for(long long it : nums){
            max_ele=max(max_ele,it);
            sample.push_back(max_ele);
        }
        for(long long i=0;i<nums.size();i++){
            long long x=gcd(sample[i],nums[i]);
            prefixGcd.push_back(x);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long left=0;
        long long right=nums.size()-1;
        vector<pair<long long,long long>> v;
        while(left<right){
            v.push_back({prefixGcd[left],prefixGcd[right]});
            left++;
            right--;
        }
        long long sum=0;
        for(long long i=0;i<nums.size()/2;i++){
            sum+=gcd(v[i].first,v[i].second);
        }
        return sum;
    }
};