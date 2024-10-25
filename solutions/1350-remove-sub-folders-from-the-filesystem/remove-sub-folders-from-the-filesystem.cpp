class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i = 1; i < folder.size(); i++) {
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};