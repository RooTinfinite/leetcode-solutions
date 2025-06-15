class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int n = arr.length, ans = 0, s = 0;
        for(int i = 0; i < k - 1; i++) s += arr[i];
        for(int i = k - 1; i < n; i++) {
            s += arr[i];
            if(s / k >= threshold) ans++;
            s -= arr[i - k + 1];
        }
        return ans;
    }
}