class Solution {
    public int countSuffix(int[] nums, int[] target) {
        int n = nums.length;
        int[] freq = new int[100001];

        int nonZero = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int y = target[i];

            if (x == y) {
                continue;
            }

            if (freq[x] == 0) {
                nonZero++;
            }

            freq[x]++;

            if (freq[x] == 0) {
                nonZero--;
            }

            if (freq[y] == 0) {
                nonZero++;
            }

            freq[y]--;

            if (freq[y] == 0) {
                nonZero--;
            }
        }

        int bad = 0;

        for (int i = 1; i < n; i++) {
            if (target[i - 1] < target[i]) {
                bad++;
            }
        }

        int res = 0;
        boolean prefixEqual = true;

        for (int i = 0; i < n; i++) {
            if (prefixEqual && bad == 0 && nonZero == 0) {
                res++;
            }

            int x = nums[i];

            if (freq[x] == 0) {
                nonZero++;
            }

            freq[x]--;

            if (freq[x] == 0) {
                nonZero--;
            }

            int y = target[i];

            if (freq[y] == 0) {
                nonZero++;
            }

            freq[y]++;

            if (freq[y] == 0) {
                nonZero--;
            }

            if (nums[i] != target[i]) {
                prefixEqual = false;
            }

            if (i + 1 < n && target[i] < target[i + 1]) {
                bad--;
            }
        }

        return res;
    }
}