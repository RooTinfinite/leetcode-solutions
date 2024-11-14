class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1;
        long long right = 0;
        
        // Find maximum pile as upper bound
        for (int pile : piles) {
            right = max(right, (long long)pile);
        }
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            if (canEatAll(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return (int)left;
    }
    
private:
    bool canEatAll(vector<int>& piles, int h, long long k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
            if (hours > h) return false;
        }
        return true;
    }
};