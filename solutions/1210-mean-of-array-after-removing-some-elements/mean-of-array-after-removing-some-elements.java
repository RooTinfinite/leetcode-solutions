//Java Code
class Solution {
    public double trimMean(int[] arr) {
        int sum = 0, n = arr.length, percent5 = n / 20, cnt = 0;
        Arrays.sort(arr);
        for(int i = percent5; i < n - percent5; i++){
            sum += arr[i];
            cnt++;
        }
        return (double)sum / cnt;
    }
}