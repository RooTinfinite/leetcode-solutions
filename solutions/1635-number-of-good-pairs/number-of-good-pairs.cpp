class Solution {
public:
            int numIdenticalPairs(vector<int>& A) {
        return accumulate(A.begin(), A.end(), 0, [count = unordered_map<int, int> {}] (auto x, auto y) mutable {
            return x + count[y]++;
        });
    }
};