class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
       List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
               indices.add(i);
            }
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int occurrence = queries[i];
            if (occurrence<=indices.size()) {
                result[i] = indices.get(occurrence-1);
            } else {
                result[i] = -1;
            }
        }
        return result;
    }
}