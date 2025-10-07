class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string res(n+m-1, '?');

        //satisfy all T
        for(int i=0; i<n; i++){
            if(str1[i] == 'F') continue;
            for(int j=i; j-i<m; j++){
                if(res[j] == '?') res[j] = str2[j-i];
                else{
                    if(res[j] != str2[j-i]) return ""; //conflict not possile
                }
            }
        }

        //statisfy all F
        vector<vector<pair<int, char>>> notFrom(n+m-1); 
        vector<bool> satisfy(n, true);
        for(int i=0; i<n; i++){
            if(str1[i] == 'T') continue;
            bool isMatch = true;
            vector<pair<int, char>> tmp;
            bool onlyEmptyRem = true;
            for(int j=i; j-i<m; j++){
                if(res[j] != str2[j-i]){
                    isMatch = false;
                    if(res[j] != '?') onlyEmptyRem = false;
                }
                if(res[j] == '?') tmp.push_back({j, str2[j-i]});
            }
            if(isMatch) return "";
            if(onlyEmptyRem){
                satisfy[i] = false;
                for(auto& x: tmp) notFrom[x.first].push_back({i, x.second});
            }
        }

        vector<int> nextEmpty(n+m-1);
        nextEmpty[n+m-2] = n+m-1;
        for(int i=n+m-3; i>=0; i--){
            if(res[i+1] == '?') nextEmpty[i] = i+1;
            else nextEmpty[i] = nextEmpty[i+1];
        }


        for(int i=0; i<n+m-1; i++){
            if(res[i] != '?') continue;

            unordered_set<char> lastChance;  // there can be multiple last chance
            for(auto x: notFrom[i]) {
                if(satisfy[x.first]) continue;
                if(x.first + m  - 1 < nextEmpty[i]) lastChance.insert(x.second);
            }

            if(lastChance.size() == 0) {
                res[i] = 'a'; 
            }
            else {
                for(char t = 'a' ; t<='z'; t++) {
                    if(lastChance.count(t) > 0) continue;
                    res[i] = t;
                    break;
                }
                if(res[i] == '?') return ""; 
            }

            for(auto x: notFrom[i]) {
                if(satisfy[x.first]) continue;
                if(x.second != res[i]) satisfy[x.first] = true;
            }
        }

        return res;
    }
};