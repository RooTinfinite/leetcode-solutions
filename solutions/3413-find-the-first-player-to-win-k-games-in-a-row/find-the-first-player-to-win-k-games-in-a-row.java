class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        
        int count = 0;

        int j = 1;

        int i = 0;

        while(i < skills.length-1 && j < skills.length) {
            
            if(skills[i] > skills[j]) {
                j++;
                count++;
            }
            else {
                i = j;
                j++;
                count = 1;
            }
            if(count == k) break;
        }

        return i;

    }
}