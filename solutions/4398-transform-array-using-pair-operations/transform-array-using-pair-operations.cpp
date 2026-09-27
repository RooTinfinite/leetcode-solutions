class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        return accumulate(source.begin(), source.end(), 0LL)
            == accumulate(target.begin(), target.end(), 0LL);
    }
};