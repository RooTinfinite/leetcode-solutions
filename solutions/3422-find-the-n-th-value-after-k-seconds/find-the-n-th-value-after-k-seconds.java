public class Solution {
    public int valueAfterKSeconds(int n, int k) {
        int[] sum = new int[n];
        Arrays.fill(sum, 1);
        while(k-- > 0)
            for(int i = 1 ; i < n ; i++)
                sum[i] = (sum[i] + sum[i - 1]) % 1000000007;
        return sum[n - 1];
    }
}