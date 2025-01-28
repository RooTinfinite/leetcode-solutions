class Solution {
public:
    bool check(string &s, int ops, int mid){
        int n = s.length(); 
        int need = 0;
        // Handling case mid == 1
        if(mid == 1){
            int need0 = 0;
            // case - '010101...'
            for(int i=0;i<n;i++){
                if(i%2==0) {if(s[i]=='1') need0++;}
                else {if(s[i]=='0') need0++;}
            }
            int need1 = 0;
            // case - '101010...'
            for(int i=0;i<n;i++){
                if(i%2==1) {if(s[i]=='1') need1++;}
                else {if(s[i]=='0') need1++;}
            }
            need = min(need1, need0);
            return need <= ops;
        }
        int i = 0;
        while(i<n){
            int count = 0;
            int curr = s[i];
            // count elements in subarrays with similar element
            while(i<n && s[i]==curr){
                count++;
                i++;
            }
            need += (count)/(mid+1);
        }
        return need <= ops;
    }

    int minLength(string s, int ops) {
        int n = s.length();
        int low = 1, high = n;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            bool ch = check(s, ops, mid);
            if(ch){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};