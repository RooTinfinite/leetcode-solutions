class Solution {
public:

    void computeLPS(string &pattern, vector<int>&LPS, int &M){
        LPS[0] = 0; 
        int len = 0; 
        int i = 1; 
        while(i < M){
            if(pattern[i] == pattern[len]){
                len++; 
                LPS[i] = len; 
                i++;
            }
            else{
                if(len != 0)
                {
                    len = LPS[len-1];
                }
                else{
                    LPS[i]=0; 
                    i++;
                }
            }
        }
    }

    vector<int>KMP(string& pattern, string &text){
        int M = pattern.length(); 
        int N = text.length(); 
        vector<int>LPS(M, 0);
        computeLPS(pattern, LPS, M);

        vector<int>result;
        int j = 0; 
        int i = 0; 
        while(i < N){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            if(j == M){
                result.push_back(i-j); //i-j+1 for 1 Based indexing;
                j = LPS[j-1]; 
            }
            else if(i < N && text[i] != pattern[j]){
                if(j != 0){
                    j = LPS[j-1];
                }
                else{ 
                    i++;
                }
            }
        } 
        return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n  =s.length(); 
        vector<int>i_indices = KMP(a, s);
        vector<int>j_indices = KMP(b, s); 

        vector<int>result;

        for(int &i : i_indices){
            int leftLimit = max(0, i-k);
            int rightLimit = min(n-1,i+k);
            auto it = lower_bound(begin(j_indices), end(j_indices), leftLimit); 
            if(it != j_indices.end() && *it <= rightLimit ){
                result.push_back(i);
            }
        }
        return result;
    }
};