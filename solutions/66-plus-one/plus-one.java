class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        //Move along the input array starting from the end
        for (int idx = n - 1; idx >= 0; --idx) {
            //Set all the nines at the end of the array to zeros
            if (digits[idx] == 9) {
                digits[idx] = 0;
            }
            //Here we have the rightmost not-nine
            else {
                // Increase this rightmost not-nine by 1
                digits[idx]++;

                // and the job is done
                return digits;
            }
        }

        // We're here because all the digits are nines
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
}