class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.size();
        int i=n-1;
        while(i>=0 && isVowel(s[i])) i--;
        if(i<0) return "";
        return s.substr(0,i+1);
    }

    bool isVowel(char ch){
        return ch=='a' ||
        ch=='e' ||
         ch=='i' || ch=='o' || ch=='u';
    }
};