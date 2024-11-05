class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;  // Initialize ans with the maximum possible value

        while (l <= high) {
            int mid = l + (high - l) / 2;
            if (canEatAll(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canEatAll(const vector<int>& piles, int h, int k) {
        long long hours = 0;  // Use long long to store the number of hours

        for (int pile : piles) {
            hours += (pile + k - 1) / k;  // This is equivalent to ceil(pile / k)
            if (hours > h) {
                return false;
            }
        }
        return true;
    }
};