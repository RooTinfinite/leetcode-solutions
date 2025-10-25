#include <queue>
#include <vector>
using namespace std;

class Solution {

public:
    int maxTransactions(const vector<int>& transactions) const {
        long long valueOfTransactions = 0;
        int numberOfTransactions = 0;
        priority_queue<int, vector<int>, greater<>> minHeapNegativeValuesIncludedInTransactions;

        for (const auto& value : transactions) {

            if (value >= 0) {
                ++numberOfTransactions;
                valueOfTransactions += value;
                continue;
            }

            if (valueOfTransactions + value >= 0) {
                minHeapNegativeValuesIncludedInTransactions.push(value);
                ++numberOfTransactions;
                valueOfTransactions += value;
                continue;
            }

            if (!minHeapNegativeValuesIncludedInTransactions.empty() && minHeapNegativeValuesIncludedInTransactions.top() < value) {
                valueOfTransactions += value - minHeapNegativeValuesIncludedInTransactions.top();

                minHeapNegativeValuesIncludedInTransactions.pop();
                minHeapNegativeValuesIncludedInTransactions.push(value);
            }
        }

        return numberOfTransactions;
    }
};