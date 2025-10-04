#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, char> revMap;
        for (char c = 'a'; c <= 'z'; ++c) {
            revMap[c] = 'z' - (c - 'a');
        }

        long long total = 0;
        vector<stack<int>> stacks(26);

        for (int idx = 0; idx < s.length(); ++idx) {
            char curr = s[idx];
            char mirror = revMap[curr];

            if (!stacks[mirror - 'a'].empty()) {
                int prevIdx = stacks[mirror - 'a'].top();
                stacks[mirror - 'a'].pop();
                total += idx - prevIdx;
            } else {
                stacks[curr - 'a'].push(idx);
            }
        }

        return total;
    }
};