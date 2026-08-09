class Solution {
    public boolean canReach(int[] start, int[] target) {
        int st= start[0]+start[1];          // (start_X + start_Y)
        int end= target[0]+target[1];       // (target_X + target_Y)

        // check if start and target have same colour
        if(st%2==0 && end%2==0 || st%2!=0 && end%2!=0)
            return true;
        else
            return false;
    }
}