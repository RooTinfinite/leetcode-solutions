class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                   vector<int>& arr3) {
        vector<int> ans;
        map<int, int> counter;

        // Iterate through arr1, arr2, and arr3 to count the frequencies
        for (int e : arr1) {
            counter[e]++;
        }
        for (int e : arr2) {
            counter[e]++;
        }
        for (int e : arr3) {
            counter[e]++;
        }

        // Collect elements that appear in all three arrays
        for (const auto& item : counter) {
            if (item.second == 3) {
                ans.push_back(item.first);
            }
        }

        return ans;
    }
};