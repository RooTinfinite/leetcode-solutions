class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> freq(100, 0);
        for (auto i : nums) {
            freq[i]++;
        }
        vector<int> v;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 2)
                v.push_back(i);
        }
        return v;
    }
};