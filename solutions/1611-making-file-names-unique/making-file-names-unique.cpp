class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string, int> m;
        
        for(int i=0;i<names.size();i++){
            
            if(m.count(names[i]) == 0){
                ans.push_back(names[i]);
                m[names[i]] = 1;
            }
            else{
                int k = m[names[i]];
                string new_name;
                while(true){
                    new_name = names[i] + "(" + to_string(k) + ")";
                    if(m.count(new_name) == 0) break;
                    k++;
                }
                ans.push_back(new_name);
                m[new_name] = 1;
                m[names[i]] = k+1;
            }
        }
        return ans;
    }
};