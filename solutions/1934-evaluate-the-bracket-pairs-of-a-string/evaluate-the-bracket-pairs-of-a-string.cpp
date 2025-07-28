class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string> map;
        for(int i = 0, n = knowledge.size(); i < n; ++i) map[knowledge[i][0]] = knowledge[i][1];
        string res;
        for(int i = 0, len = s.length(); i < len; ++i){
            if(s[i] == '('){
                int start = ++i;
                while(s[i] != ')') ++i;
                string sub = s.substr(start , i - start);
                if(map.count(sub)) res += map[sub];
                else res.push_back('?');
            }
            else res += s[i];
        }
        return res;
    }
};