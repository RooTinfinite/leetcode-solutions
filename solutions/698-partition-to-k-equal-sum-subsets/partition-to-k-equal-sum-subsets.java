class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        if (sum % k != 0) return false;
        
        int targetSum = sum / k;
        Arrays.sort(nums);
        // add a reverse it helps!
        return backtrack(nums.length - 1, nums, new int[k], targetSum);
    }
    
    private boolean backtrack(int index, int[] nums, int[] sums, int targetSum) {
        if (index < 0) return true;
        
        for (int i = 0; i < sums.length; i++) {
            if (sums[i] + nums[index] > targetSum) continue;
            
            sums[i] += nums[index];
            
            if (backtrack(index - 1, nums, sums, targetSum)) {
                return true;
            }
            
            sums[i] -= nums[index];
            
            if (sums[i] == 0) break;// why ? explanation given below
        }
        
        return false;
    }
}
/*
Great question! The line if (sums[i] == 0) break; is indeed a crucial optimization that can significantly reduce the time complexity in many cases. Let's break down why this is so effective:

Avoiding Duplicate Work:
When we backtrack and remove a number from a subset, if that subset becomes empty (sum becomes 0), it means we're back to the starting point for that subset. If we continue to the next iteration of the loop, we'd be trying to add the current number to another empty subset. This would lead to exploring the same combinations we've already explored or will explore in future recursive calls.
Symmetry Breaking:
All empty subsets are identical from the perspective of our algorithm. Once we've tried adding the current number to one empty subset and it didn't lead to a solution, there's no point in trying to add it to other empty subsets.
Pruning the Search Tree:
By breaking the loop when we encounter an empty subset, we're effectively pruning a large portion of the search tree. This can drastically reduce the number of recursive calls and iterations.
Reducing Permutations:
Without this break, the algorithm would consider all permutations of the subsets, which is unnecessary since we only care about the content of the subsets, not their order.

Time Complexity Impact:

In the worst case (when no valid partition exists), the time complexity without this optimization could be O(k^n), where k is the number of subsets and n is the number of elements.
With this optimization, many redundant paths are eliminated, potentially reducing the time complexity significantly, although it remains exponential in the worst case.

Practical Impact:

For inputs where many valid solutions exist, this optimization might not make a huge difference.
However, for inputs where valid solutions are sparse or non-existent, this optimization can reduce the runtime from hours or days to seconds or minutes.

Example:
Consider an array [10, 10, 10, 7, 7, 7, 6, 6, 6] with k = 3. Without the optimization, the algorithm would try many permutations of how to distribute these numbers. With the optimization, once it tries [10, 10, 10] in one subset and backtracks, it immediately knows not to try 10 in the other empty subsets, significantly reducing the search space.
In summary, this simple optimization leverages the problem's structure to eliminate a vast number of unnecessary recursive calls, making the algorithm much more efficient in practice, especially for challenging inputs.
*/