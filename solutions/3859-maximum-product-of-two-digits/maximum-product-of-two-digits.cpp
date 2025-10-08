class Solution {
public:
    int maxProduct(int n) {
        int large = n % 10;
        int secondLarge = INT_MIN;
        n /= 10;

        while (n != 0) {
            int r = n % 10;
            if (r >= large) {
                secondLarge = large;
                large = r;
            } else if (r != large && r > secondLarge) {
                secondLarge = r;
            }
            n /= 10;
        }

        return secondLarge * large;
    }
};