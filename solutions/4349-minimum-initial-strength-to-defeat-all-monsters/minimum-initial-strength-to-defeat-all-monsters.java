class Solution {
    public long minInitialStrength(int[] monsters, int[][] boosts){
        long[] arr = new long[monsters.length + 1];
        for(int[] boost : boosts){
            arr[boost[0]] += boost[2];
            arr[boost[1] + 1] += -boost[2];
        }
        for(int i = 1 ; i < arr.length ; i++){
            arr[i] += arr[i - 1];
        }
        long l = 0 , h = 1000_000_000_000_000_000L , ans = -1;
        while(l <= h){
            long mid = (h - l) / 2 + l;
            if(check(mid , monsters , arr)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    private boolean check(long mid , int[] monsters , long[] prefix){
        long currStr = mid;
        int n = monsters.length;
        for(int i = 0 ; i < n ; i++){
            long totalStr = currStr + prefix[i];
            if(totalStr >= monsters[i]){
                currStr = Math.max(0 , currStr - monsters[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
}