public class Solution {
    public bool PrimeSubOperation(int[] nums) {
        int maxElement = nums.Max();

        // Create Sieve of Eratosthenes array to identify prime numbers
        bool[] sieve = new bool[maxElement + 1];
        Array.Fill(sieve, true);
        sieve[1] = false;

        for (int p = 2; p <= Math.Sqrt(maxElement + 1); p++) {
            if (sieve[p]) {
                for (int j = p * p; j <= maxElement; j += p) {
                    sieve[j] = false;
                }
            }
        }

        // Check if array can be made strictly increasing by subtracting prime numbers
        int currValue = 1;
        int i = 0;
        while (i < nums.Length) {
            int difference = nums[i] - currValue;

            // Return false if current number is already smaller than required value
            if (difference < 0) {
                return false;
            }

            // Move to next number if difference is prime or zero
            if (sieve[difference] == true || difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return true;
    }
}