// Using adamrbeier's solution
// LINK: https://leetcode.com/problems/minimum-operations-to-make-subarray-elements-equal/solutions/6286186/python-solution-track-median-of-subarrays-using-sortedcontainers-sortedlist

class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();

        multiset<int> below_median; // Use multiset for duplicates
        multiset<int> above_median;
        long long below_sum = 0;
        long long above_sum = 0;

        // Initialize below_median with the first k-1 elements
        for (int i = 0; i < k - 1; ++i) {
            below_median.insert(nums[i]);
            below_sum += nums[i];
        }
        // Sort below_median (in-place using a temporary)
        // Sort below_median (using a temporary)
        vector<int> temp_vec(below_median.begin(), below_median.end());
        sort(temp_vec.begin(), temp_vec.end(), greater<int>());
        below_median = multiset<int>(temp_vec.begin(), temp_vec.end());

 
        int median_index = k / 2;
        bool odd_adjust = (k % 2 == 1); // True when k is odd

        long long min_cost = numeric_limits<long long>::max(); 

        for (int lhs = 0; lhs <= n - k; ++lhs) {
            int rhs = lhs + k - 1;
            int rhs_num = nums[rhs];

            below_median.insert(rhs_num);
            below_sum += rhs_num;

            // Rebalance: Move elements from below_median to above_median
            while (below_median.size() > median_index) {
                auto it = prev(below_median.end()); // Get the last (largest) element
                int rhs_of_below = *it;
                below_sum -= rhs_of_below;
                below_median.erase(it);
                above_median.insert(rhs_of_below);
                above_sum += rhs_of_below;
            }

            // Ensure sorted order between below_median and above_median
            while (!above_median.empty() && *prev(below_median.end()) > *above_median.begin()) {
                int rhs_of_below_median = *prev(below_median.end());
                int lhs_of_above_median = *above_median.begin();

                below_median.erase(prev(below_median.end()));
                above_median.erase(above_median.begin());

                below_sum -= rhs_of_below_median;
                above_sum -= lhs_of_above_median;

                swap(rhs_of_below_median, lhs_of_above_median);

                below_median.insert(rhs_of_below_median);
                above_median.insert(lhs_of_above_median);

                below_sum += rhs_of_below_median;
                above_sum += lhs_of_above_median;
            }

            // Calculate and update min_cost
            long long local_cost = above_sum - below_sum;
            if (odd_adjust) {
                local_cost -= *above_median.begin();
            }
            min_cost = min(min_cost, local_cost);

            // Remove the leftmost element from the window
            int remove_val = nums[lhs];
            if (below_median.find(remove_val) != below_median.end()) {
                below_median.erase(below_median.find(remove_val));
                below_sum -= remove_val;
            } else {
                above_median.erase(above_median.find(remove_val));
                above_sum -= remove_val;
            }
        }

        return min_cost;
    }
};