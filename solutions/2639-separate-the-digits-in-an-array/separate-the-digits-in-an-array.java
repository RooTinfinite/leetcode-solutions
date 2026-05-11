class Solution {

    public int[] separateDigits(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.add(x % 10);
                x /= 10;
            }
        }

        Collections.reverse(res);
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }
}