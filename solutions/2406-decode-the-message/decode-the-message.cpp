class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<pair<char,char>> ch;
        vector<bool> visited(26,0);
        int i = 0;
        for(auto x : key){
            if(x == ' ')
            continue;
            else if(!visited[x-'a']){
                visited[x-'a'] = 1;
                ch.push_back({x,'a'+i});
                i++;
            }
            if(ch.size() == 26)
            break;
        }
        sort(ch.begin(),ch.end());

        string ans = "";
        for(auto x : message){
            if(x == ' ')
            ans += ' ';
            else
            ans += ch[x-'a'].second;
        }       
        return ans; 
    }
};