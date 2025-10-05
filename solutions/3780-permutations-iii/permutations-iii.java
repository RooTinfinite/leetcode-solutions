class Solution {
    public int[][] permute(int n) {
        // Build the array of positive integers from 1 - n
        int[] nums = new int[n];
        for (int i = 0; i < nums.length;i++) nums[i] = i + 1;

        // boolean array to tracked used elements
        boolean[] used = new boolean[n];

        // a "candidate" permutation holder
        int[] candidate = new int[n];

        // valid permutations
        List<List<Integer>> permutations = new ArrayList<>();

        // compute the permutations
        permute(nums, 0, used, candidate, permutations);

        // convert back to the return type
        int[][] result = new int[permutations.size()][n];
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                result[i][j] = permutations.get(i).get(j);
            }
        }

        return result;
    }

    private void permute(int[] nums, int pos, boolean[] used, int[] candidate, List<List<Integer>> result) {
        if (pos == nums.length) {
            List<Integer> permutation = new ArrayList<>();
            for (int i = 0; i < candidate.length; i++) permutation.add(candidate[i]);
            result.add(permutation);
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                // Any element is valid in the first position. All other elements need to flip odd/even
                if (pos == 0 || candidate[pos - 1] % 2 != nums[i] % 2) {
                    candidate[pos] = nums[i];
                    used[i] = true;
                    permute(nums, pos + 1, used, candidate, result);
                    used[i] = false;
                }
            }
        }
    }
}