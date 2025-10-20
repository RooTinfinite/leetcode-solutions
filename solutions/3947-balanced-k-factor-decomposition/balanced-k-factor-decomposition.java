class Solution {
    public int[] minDifference(int n, int k) {
        if(k == 1) {
            return new int[]{n};
        }
        int[] result = new int[k];
        int maxDiff = Integer.MAX_VALUE;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                int[] rem = minDifference(n / i, k - 1);
                int[] newArr = new int[k];

                for(int j = 0; j < k - 1; j++) {
                    newArr[j] = rem[j];
                }
                newArr[k - 1] = i;
                Arrays.sort(newArr);
                int currentDiff = newArr[k - 1] - newArr[0];

                if(maxDiff > currentDiff) {
                    maxDiff = currentDiff;
                    result = newArr;
                }
            }
        }
        return result;
    }
}