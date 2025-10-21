class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        long long res = 0, n = nums.size();
        unordered_map<int, int> freq; // {num, frequency}
        map<int, set<int>> vals;      // Frequencies and their nums sorted
        for (int i = 0; i < n; i++) {
            // 1. Remove prev number that is not included in current window.
            if (i - k >= 0) {
                int pprevFreq = freq[nums[i - k]], pprevVal = nums[i - k];
                vals[pprevFreq].erase(pprevVal);
                if (vals[pprevFreq].empty()) {
                    vals.erase(pprevFreq);
                }
                freq[pprevVal]--;
                if (freq[pprevVal] > 0) {
                    vals[freq[pprevVal]].insert(pprevVal);
                }
            }
            
            // 2. Remove frequency for current number, it will be updated later.
            int prevFreq = freq.count(nums[i]) > 0 ? freq[nums[i]] : 0;
            if (prevFreq > 0) {
                vals[prevFreq].erase(nums[i]);
                if (vals[prevFreq].empty())
                    vals.erase(prevFreq);
            }
            
            // 3. Make updated with current number.
            freq[nums[i]]++;
            vals[freq[nums[i]]].insert(nums[i]);
            if (i - k + 1 >= 0) {
                int maxFreq = vals.rbegin()->first;
                int mode = *vals[maxFreq].begin();
                res += 1LL * maxFreq * mode;
            }
        }
        return res;
    }
};