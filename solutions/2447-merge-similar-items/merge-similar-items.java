class Solution {
    public List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        List<List<Integer>> list = new ArrayList<>();
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(int[] num : items1){
            if(map.containsKey(num[0])){
                map.put(num[0],map.get(num[0]) + num[1]);
            }
            else{
                map.put(num[0], num[1]);
            }
        }
        for(int[] num : items2){
            if(map.containsKey(num[0])){
                map.put(num[0],map.get(num[0]) + num[1]);
            }
            else{
                map.put(num[0], num[1]);
            }
        }
        for(int key : map.keySet()){
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(key);
            temp.add(map.get(key));
            list.add(temp);
        }
        return list;
    }
}