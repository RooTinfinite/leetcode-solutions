class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int res = 0, i = -1, j = plants.size();
        int left = capacityA, right = capacityB;
        while (++i < --j) {
            if (left < plants[i]) {
                left = capacityA;
                ++res;
            }
            if (right < plants[j]) {
                right = capacityB;
                ++res;
            }
            left -= plants[i];
            right -= plants[j];
        }
        return (i == j && max(left, right) < plants[i]) ? res + 1 : res;
    }
};