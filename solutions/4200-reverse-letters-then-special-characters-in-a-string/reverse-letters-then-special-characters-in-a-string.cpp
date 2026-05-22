class Solution {
public:
    string reverseByType(string s) {

        int i=0;
        int j=s.size()-1;

        while(i<j){
            while(i<s.size() && !isalpha(s[i])){
                i++;
            }
            while(j>=0 && !isalpha(s[j])){
                j--;
            }

            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        i=0;
        j=s.size()-1;

        while(i<j){
            while(i<s.size() && isalpha(s[i])){
                i++;
            }
            while(j>=0 && isalpha(s[j])){
                j--;
            }

            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};