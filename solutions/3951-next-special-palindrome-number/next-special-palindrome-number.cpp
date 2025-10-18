void findSubsets(vector<int>& arr, int index, int target, vector<int>& curr, vector<vector<int>>& result, int max_odds, int odd_count) {
    if (index >= (int)arr.size()) {
        if (target == 0) {
            result.push_back(curr);
        }
        return;
    }

    if (odd_count + (arr[index] % 2) <= max_odds) {
        curr.push_back(arr[index]);
        findSubsets(arr, index + 1, target - arr[index], curr, result, max_odds, odd_count + (arr[index] % 2));
        curr.pop_back();
    }

    findSubsets(arr, index + 1, target, curr, result, max_odds, odd_count);
}

vector<vector<int>> perfectSum(vector<int>& arr, int target, int max_odds) {
    vector<vector<int>> result;
    vector<int> curr;
    findSubsets(arr, 0, target, curr, result, max_odds, 0);
    return result;
}

int mainLogicInit(vector<long long>& L1) {
    vector<int> arr1 = {2, 4, 6, 8};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<string> L;

    for (int i = 2; i < 17; i++) {
        vector<vector<int>> res;
        if (i % 2 == 0) {
            res = perfectSum(arr1, i, (int)arr1.size());
        } else {
            res = perfectSum(arr2, i, 1);
        }

        bool x = false;
        int t = 0;
        for (auto& arr : res) {
            string s = "";
            x = false;
            for (auto val : arr) {
                if (val % 2 == 1) {
                    x = true;
                    t = val;
                }
                s += string(val / 2, char('0' + val));
            }

            sort(s.begin(), s.end());
            do {
                if (x) {
                    L.insert(s + to_string(t) + string(s.rbegin(), s.rend()));
                } else {
                    L.insert(s + string(s.rbegin(), s.rend()));
                }
            } while (next_permutation(s.begin(), s.end()));
        }
    }

    L1.clear();
    for (auto& str : L) {
        L1.push_back(stoll(str));
    }
    sort(L1.begin(), L1.end());
    return 0;
}

class Solution {
public:
    long long specialPalindrome(long long n) {
        static vector<long long> L1;
        static bool initialized = false;
        if (!initialized) {
            mainLogicInit(L1);
            initialized = true;
        }

        if (n == 0) {
            return 1;
        }
        auto x = upper_bound(L1.begin(), L1.end(), n) - L1.begin();
        return L1[x];
    }
};