#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Standard BIT/Fenwick Tree implementation
    vector<int> bitEven, bitOdd;
    int size;

    void update(vector<int>& bit, int idx, int val) {
        for (; idx <= size; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(vector<int>& bit, int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    vector<int> countSmallerOppositeParity(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // 1. Coordinate Compression
        // We need to map large values (up to 10^9) to a small range (1 to n)
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());
        
        size = sorted_nums.size();
        bitEven.assign(size + 1, 0);
        bitOdd.assign(size + 1, 0);

        vector<int> answer(n);

        // 2. Process from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Find the rank (1-indexed position) of nums[i]
            int rank = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin() + 1;
            
            if (nums[i] % 2 == 0) {
                // If current is even, count smaller odds seen so far
                answer[i] = query(bitOdd, rank - 1);
                update(bitEven, rank, 1);
            } else {
                // If current is odd, count smaller evens seen so far
                answer[i] = query(bitEven, rank - 1);
                update(bitOdd, rank, 1);
            }
        }

        return answer;
    }
};