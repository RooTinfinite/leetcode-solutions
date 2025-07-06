class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.length();
        int sp = 0;
        string word ="";
        vector<string> words;

        for(int i=0; i<n; i++){
            if(text[i] == ' '){
                sp++;
                if(!word.empty()){ 
                    words.push_back(word);
                }
                word = "";
            }
            else
               word += text[i];
        }
        if(!word.empty()){
            words.push_back(word);
        }
        
        int numWords = words.size();
        if (numWords == 1) {
          return words[0] + string(sp, ' ');
        }
        
        int last = sp % (numWords-1);
        int eqS = sp/(numWords-1);

        string result;
        for (int i = 0; i < numWords; ++i) {
            result += words[i];
            if (i < numWords - 1) result += string(eqS, ' ');
        }

        result += string(last, ' ');
        return result; 
    }
};