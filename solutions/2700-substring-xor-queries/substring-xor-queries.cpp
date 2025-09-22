class Solution {
public:
    string convertToBinary(int v){
        string ans = "";
        while(v > 0){
            ans += to_string(v%2);
            v /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>>ans;
        unordered_map<string, int>mp;
        for(int i = 0; i < s.length(); i++){
            string temp = "";
            for(int j = i; j <= i + 30 - 1; j++){ //explnation has given why 30
                if(j >= s.length()) break;
                temp += s[j];
                if(mp.find(temp) == mp.end()) mp[temp] = i;
            }
        }
        for(auto it : queries){
            int first = it[0];
            int second = it[1];
            int xxor = first ^ second;
            string s2;
            if(xxor == 0){
                s2 = "0";
            } else {
                s2 = convertToBinary(xxor);
            }
            if(mp.find(s2) == mp.end()){
                ans.push_back({-1, -1});
            } else {
                int index = mp[s2];
                int l = s2.length();
                ans.push_back({index, index+l-1});
            }
        }
        return ans;
    }
};