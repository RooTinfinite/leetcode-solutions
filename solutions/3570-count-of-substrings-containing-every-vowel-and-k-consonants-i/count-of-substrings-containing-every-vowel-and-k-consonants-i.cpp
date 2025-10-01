class Solution {
public:
bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    else return false;
}
int atLeast(string word, int k){
    int n=word.size();
        int i=0, ans=0, conso=0;
        unordered_map<char,int>m;
        for(int j=0;j<n;j++){
            if(isVowel(word[j])){
                m[word[j]]++;
            }else{
                conso++;
            }
            while(m.size()==5 && conso>=k){
                ans += n-j;
            
                if(isVowel(word[i])){
                    m[word[i]]--;
                    if(m[word[i]]==0){
                        m.erase(word[i]);
                    }
                }else{
                    conso--;
                }
                i++;
            }
        }
        return ans;
}
    int countOfSubstrings(string word, int k) {
        return atLeast(word,k)-atLeast(word,k+1);
    }
};