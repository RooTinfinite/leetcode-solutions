
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elementsVec) {
        // Build a map { element -> leftmost index } by iterating from right to left
        unordered_map<int,int> elementIndex;
        for (int i = (int)elementsVec.size() - 1; i >= 0; i--) {
            elementIndex[elementsVec[i]] = i;
        }

        // For each number in groups, find the smallest index among all its factors
        vector<int> assigned;
        assigned.reserve(groups.size());
        for (int num : groups) {
            assigned.push_back(processFactors(num, elementIndex));
        }

        return assigned;
    }

private:
    int processFactors(int num, const unordered_map<int,int>& elementIndex) {
        int minIndex = INT_MAX;
        int limit = (int)floor(sqrt(num));

        for (int n = 1; n <= limit; n++) {
            if (num % n == 0) {
                int smallDivisor = n;
                int largeDivisor = num / n;

                if (elementIndex.find(smallDivisor) != elementIndex.end()) {
                    minIndex = min(minIndex, elementIndex.at(smallDivisor));
                }
                if (elementIndex.find(largeDivisor) != elementIndex.end()) {
                    minIndex = min(minIndex, elementIndex.at(largeDivisor));
                }
            }
        }
        return (minIndex == INT_MAX) ? -1 : minIndex;
    }
};