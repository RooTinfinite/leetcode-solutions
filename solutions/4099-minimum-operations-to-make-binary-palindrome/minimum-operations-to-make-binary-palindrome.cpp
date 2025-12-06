class Solution {
public:

    bool isPalindrome(int n) {
        string s = "";
        for(int i=0; i<32; i++) {
            if(n&(1<<i)) {
                s += '1';
            } else {
                s += '0';
            }
        }
        while(!s.empty() && s.back() =='0')
            s.pop_back();

        string b = s;
        reverse(s.begin(),s.end());
        return s == b;
    }
    int minOperationToPalindrome(int a) {
        if(isPalindrome(a)) return 0;
        
        for (int d = 1; d < 5000; d++) {
            if (a - d >= 1 && isPalindrome(a - d)) 
                return d;
            if (a + d > 0 && isPalindrome(a + d))
                return d;
        }
    
        return -1;
    }
    vector<int> minOperations(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        for(int i=0; i<n; i++) {
            ans[i] = minOperationToPalindrome(arr[i]);
        }

        return ans;
    }
};