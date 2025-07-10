class Solution {
    public int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++){
            int sum = 0, n = i;
            while (n != 0) {
                sum += n % 10;
                n /= 10;
            }
            if (sum != 0 && sum % 2 == 0) count++;
        }
        return count;
    }
}