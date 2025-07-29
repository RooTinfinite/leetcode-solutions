class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.length();
        int ans=0;

        int i=0;

        while(i<n){
            if(word[i]!='a'){
                i++;
                continue;
            }

            int j=i;
            int vowelCount=1;

            while(j+1<n && word[j]<=word[j+1]){
                if(word[j]<word[j+1]) vowelCount++;
                j++;
            }

            if(vowelCount==5) ans=max(ans,j-i+1);

            i=j+1;
        }
        return ans;
    }
};