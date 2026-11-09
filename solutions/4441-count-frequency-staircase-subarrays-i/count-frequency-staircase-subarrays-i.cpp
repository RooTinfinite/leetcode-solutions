class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> first;
            vector<int> freq;
            int invalid = 0;

            for (int j = i; j < n; j++) {
                int num = nums[j];

                if (first.find(num) == first.end()) {
                    int idx = freq.size();
                    first[num] = idx;
                    freq.push_back(1);

                    if (idx != 0)
                        invalid++;
                } else {
                    int idx = first[num];
                    int old = freq[idx];
                    int expected = idx + 1;
                    int next = old + 1;

                    if (old != expected)
                        invalid--;

                    if (next > expected)
                        break;

                    freq[idx] = next;

                    if (next != expected)
                        invalid++;
                }

                if (invalid == 0)
                    ans++;
            }
        }

        return ans;
    }
};