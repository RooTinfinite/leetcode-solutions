class Solution {
    public int totalReplacements(int[] ranks) {
        int count = 0;
        int best = ranks[0];
        for(int i=1;i<ranks.length;i++){
            if(ranks[i]<best){
                count++;
                best = ranks[i];
            }
        }

        return count;
        
    }
}