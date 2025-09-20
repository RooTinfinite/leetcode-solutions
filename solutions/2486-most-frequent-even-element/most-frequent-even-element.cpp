class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {

        unordered_map<int, int> freq;
        for (auto num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
            }
        }
        int maxFreq = 0;
        int result = -1;

        for (auto [num, count] : freq) {
            if (count > maxFreq || (count == maxFreq && num < result)) {
                maxFreq = count;
                result = num;
            }
        }
        return result;
    }
};