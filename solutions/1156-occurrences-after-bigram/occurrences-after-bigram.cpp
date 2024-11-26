class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans,words;
        string ag="";
        text+=' ';
        for(int i=0;i<text.size();i++){
            if(text[i]!=' '){
                ag+=text[i];
            }
            if(text[i]==' '){
                words.push_back(ag);
                ag="";
            }
        }
        for(int i=0;i<words.size()-2;i++){
            if(words[i]==first && words[i+1]==second){
                ans.push_back(words[i+2]);
            }
        }
        return ans;

    }
};