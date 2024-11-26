class Solution {
public:
    unordered_map<string, bool> vis;
    bool helper(string bottom, unordered_map<string, vector<char>>&m, int start, string next){
        string temp=to_string(start)+"#"+bottom+"#"+next;
        if(vis.find(temp)!=vis.end())return vis[temp];
        if(bottom.size()==1)return true;
        if(start==(int)bottom.size()-1) return helper(next, m, 0, "");
        for(char c:m[bottom.substr(start, 2)]){
            if(helper(bottom,m,start+1, next+c)){
                 vis[temp]=true;
                return true;
            }
        }
        vis[temp]=false;
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> m;
        for(auto& s:allowed){
            m[s.substr(0,2)].push_back(s.back());
        }
        return helper(bottom, m, 0, "");
    }
};