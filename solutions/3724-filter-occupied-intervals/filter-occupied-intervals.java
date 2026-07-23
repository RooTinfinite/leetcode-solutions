class Solution {
    public List<List<Integer>> filterOccupiedIntervals(int[][] arr, int freeStart, int freeEnd) {
        int n = arr.length;
        Arrays.sort(arr, (a,b)-> Integer.compare(a[0], b[0]));
        List<int[]> temp = new ArrayList<>();
        for(int[] brr : arr){
            if(temp.isEmpty() || temp.get(temp.size()-1)[1]+1<brr[0]){
                temp.add(new int[]{brr[0], brr[1]});
            }
            else{
                temp.get(temp.size()-1)[1] = Math.max(temp.get(temp.size()-1)[1], brr[1]);
            }
        }
        List<List<Integer>> res = new ArrayList<>();
        for (int[] brr : temp) {
            int s = brr[0];
            int e = brr[1];
            
            if (e < freeStart || s > freeEnd) {
                res.add(Arrays.asList(s, e));
            } else {
                if (s < freeStart) {
                    res.add(Arrays.asList(s, freeStart - 1));
                }
                if (e > freeEnd) {
                    res.add(Arrays.asList(freeEnd + 1, e));
                }
            }
        }
        
        return res;
    }
}