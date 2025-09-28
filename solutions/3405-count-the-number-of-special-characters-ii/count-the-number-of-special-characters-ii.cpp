class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.length();
        int count = 0;
        vector<int> a(150, -1); // upperCase
        vector<int> b(150, -1); // lowerCase
        for(int i = 0; i < n; i++){
            if(s[i] >= 65 && s[i] <= 90){ // count first occurrence of capital letters 
                if(a[s[i]] == -1) a[s[i]] = i; 
            }
            else{ // count last occurrence of small letters
                b[s[i]] = i;
            }
        }
        // iterate on either of vector and according to the condition increase count
        for(int i = 0; i < a.size(); i++){
            if(a[i] == -1 || b[i + 32] == -1) continue;
            if(b[i + 32] < a[i]) count++;
        }
        return count;
    }
};