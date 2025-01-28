#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
string tostring(auto& nums) {
	string res;
	for(int num : nums) res.push_back(char(num));
	return res;
}

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
    	string s = tostring(nums);
    	auto zAll = z_function(s);
    	int n = nums.size(), ans = 0;
        // i = possible array2 start idx
        // thats why i != 0 and i != n-1
    	for(int i = 1; i < (n - 1); i++) {
            bool skipEnd = false;
    		if(zAll[i] >= i) {
                // ex:
                // [1,2,3,1,2,3,  9999,9999 ]
                // at idx = 3
                // then you match [1,2,3,1,2,3]
                // then there are 2 ways
                // n - (2*idx) = 8 - (2*3) = 8 - 6 = 2 ways
    			ans += n - 2*i;
                skipEnd = true; // skip checking >= 2*i because already counted
    		}
            s.erase(0, 1);
    		auto zSub = z_function(s);
            // for i = 2, then s = nums[2...end]
            // i = 2, nums = [1,2,3,4,5] then s = [3,4,5]
    		for(int j = 1; j < zSub.size(); j++) {
                // here check j >= i because zSub is shrunk from s.erase(0, 1) every loop
                // same as (i + j) >= 2*i
                // j >= 2*i - i -> j >= i
                if(skipEnd && j >= i) break;
    			if(zSub[j] >= j) {
    				ans++;
    			}
    		}
    	}
    	return ans;
    }
};