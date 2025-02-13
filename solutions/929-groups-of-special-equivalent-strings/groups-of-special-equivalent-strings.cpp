class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> uniqueGroups;

        for (auto &word : words) {
            string even = "", odd = "";
            for (int j = 0; j < word.size(); j++) {
                if (j % 2 == 0) even += word[j];
                else odd += word[j];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            
            string key = even + odd; 
            uniqueGroups.insert(key);
        }

        return uniqueGroups.size();
    }
};