#include <vector>
using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                count += nums[i];
            else
                count -= nums[i];
        }
        return count;
    }
};