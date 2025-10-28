class Solution {
    public int[] findBuildings(int[] heights) {
        List<Integer> ls = new ArrayList<>();
        int last = Integer.MIN_VALUE;
        for (int i = heights.length - 1; i >= 0; i--) {
            if (heights[i] > last) {
                ls.add(i);
                last = heights[i];
            }
        }
        
        int index = 0;
        int[] res = new int[ls.size()];
        for (int i = ls.size() - 1; i >= 0; i--)
            res[index++] = ls.get(i);
        
        return res;
    }
}