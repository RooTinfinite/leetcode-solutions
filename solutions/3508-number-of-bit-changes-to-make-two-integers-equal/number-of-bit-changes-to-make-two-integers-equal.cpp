class Solution {
public:
    int minChanges(int n, int k) {
        if (n == k) {
            return 0;
        }

        int count = 0;
        while (n > 0 || k > 0) {
            int bitN = n & 1;
            int bitK = k & 1;

            if (bitK == 1 && bitN == 0) {
                return -1;
            }

            if (bitN == 1 && bitK == 0) {
                count++;
            }

            n >>= 1;
            k >>= 1;
        }

        return count;
    }
};