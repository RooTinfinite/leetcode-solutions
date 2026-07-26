class Solution {
public:
    int digitRange(int num) {
        if (num == 0) return 0;

        int mx = 0;
        int mn = 9;

        while (num > 0) {
            int digit = num % 10;
            mx = max(mx, digit);
            mn = min(mn, digit);
            num /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;

        for (int num : nums) {
            maxRange = max(maxRange, digitRange(num));
        }

        int sum = 0;

        for (int num : nums) {
            if (digitRange(num) == maxRange)
                sum += num;
        }

        return sum;
    }
};