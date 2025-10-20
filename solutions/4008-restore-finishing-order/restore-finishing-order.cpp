class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> friendSet(friends.begin(), friends.end());
        vector<int> result;

        for (int num : order) {
            if (friendSet.count(num)) {
                result.push_back(num);
            }
        }

        return result;
    }
};