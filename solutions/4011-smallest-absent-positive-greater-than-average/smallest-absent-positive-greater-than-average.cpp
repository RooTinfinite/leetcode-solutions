class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double sum = 0;
        for (int num : nums) {
            sum += num;
        }
        double avg = sum / nums.size();
        int count = 1;
        while (true) {
            if (count > avg && find(nums.begin(), nums.end(), count) == nums.end()) {
                return count;
            }
            count++;
        }
    }
};