class Solution {
public:
    long long countValidSubstrings(string s) {
        // if we see a occ of abc, then all next will be invalid, so we have to find for rest
        // or we can replace abc with `d` then find all substrings that doesn't contain any d. easy

        int n = s.length(); 
        int left = 0; 
        long long valid = 0; 
        for(int i = 0; i < n; i++) {
            if(i >= 2 && s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c') left = i - 1; 
            valid += i - left + 1; 
        }
        return valid; 
    }    
};