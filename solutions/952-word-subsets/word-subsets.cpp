class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        string unit = "";
        for (auto& v : B) {
            string tmp;
            sort(v.begin(), v.end());
            set_union(v.begin(), v.end(), unit.begin(), unit.end(), back_inserter(tmp));
            swap(unit, tmp);
        }
        vector<string> res;
        for (auto a : A) {
            string t = a;
            sort(t.begin(), t.end());
            if (includes(t.begin(), t.end(), unit.begin(), unit.end())) {
                res.push_back(a);
            }
        }
        return res;
    }
};