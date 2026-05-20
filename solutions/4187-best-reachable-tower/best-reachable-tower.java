class Solution {
    public int[] bestTower(int[][] towers, int[] center, int radius) {
        int [] ans=new int[2];
        Arrays.fill(ans, -1);
        int c1=center[0];
        int c2=center[1];
        int maxq=-1;
        for(int curr[] : towers){
            int currx=curr[0];
            int curry=curr[1];
            int currq=curr[2];
            int dist= Math.abs(currx - c1) + Math.abs(curry - c2);
            if(dist <=radius){
                if(currq > maxq){
                    maxq=currq;
                    ans[0]=currx;
                    ans[1]=curry;
                }
                if(currq == maxq){
                    if(currx < ans[0] || (currx == ans[0] && curry < ans[1])){
                        ans[0]=currx;
                        ans[1]=curry;
                    }
                }
            }
        }
        return ans;
    }
}