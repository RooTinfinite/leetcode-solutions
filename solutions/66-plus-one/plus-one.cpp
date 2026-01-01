class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // Move along the input array startin tightly from the end
        for (int i = n - 1; i >= 0; --i) {
            // Set all the nines at the end of the array to zeros
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            // Here we have the rightmost not-nine
            else {
                // Increase this rightmost not-nine by 1
                digits[i]++;
                // and the job is done
                return digits;
            }
        }
        // We're here because all the digits are nines
        digits.insert(digits.begin(), 1);
        return digits;
    }
};