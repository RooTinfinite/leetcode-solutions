class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items,(a,b)->a[0]-b[0]); 
        int maxBeauty = 0;
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for(int[] item: items){
            maxBeauty = Math.max(maxBeauty,item[1]); 
            tm.put(item[0],maxBeauty);
        }
        int result[] = new int[queries.length];
        int index=0;
        for(int query: queries){
            Integer key = tm.floorKey(query); 
            result[index++] = (key==null)?0:tm.get(key); 
        }
        return result;
    }
}