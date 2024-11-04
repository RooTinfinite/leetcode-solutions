class Solution {
public:
    string compressedString(string s) {
        string a="";
        int i = 0,n=s.size();
        while(i<n){
            int j = i+1;
            while(j<n and (j-i)<9 and s[j]==s[i]){
                j++;
            }
            int ct = j-i;
            char c = ct+'0';
            a+=c;
            a+=s[i];
            i=j;
        }
        return a;
    }
};