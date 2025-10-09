class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            int r = num % 10;
            sum = sum + r;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSum(n);

        // step 1 : compute digit sum
        for (int i = 0; i < n; i++) {
            digitSum[i] = getDigitSum(nums[i]);
        }

        // step 2: create array of indices
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);

        // step 3: then sort using custom comparator
        sort(ord.begin(), ord.end(), [&](int l, int r) {
            if (digitSum[l] != digitSum[r]) {
                return digitSum[l] <
                       digitSum[r]; // primary - sorting based on digit sum
            }
            return nums[l] < nums[r]; // secondary - if digitsum equal sort than
                                      // them according to orginal value
        });

        // step 4: Detact Cycle
        vector<int> vis(n, 0);
        int cycles = 0;

        for (int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = ord[j];
            }
            cycles++;
        }

        // step 5: Calculate final Answer
        return n - cycles;
    }
};