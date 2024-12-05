class Solution {
    public boolean canChange(String start, String target) {
        if (start.equals(target)) {
            return true;
        }
        
        int pendingL = 0;
        int waitingR = 0;
        
        for (int i = 0; i < start.length(); i++) {
            char curr = start.charAt(i);
            char goal = target.charAt(i);
            
            if (curr == 'R') {
                if (pendingL > 0) {
                    return false;
                }
                waitingR++;
            }
            if (goal == 'L') {
                if (waitingR > 0) {
                    return false;
                }
                pendingL++;
            }
            if (goal == 'R') {
                if (waitingR == 0) {
                    return false;
                }
                waitingR--;
            }
            if (curr == 'L') {
                if (pendingL == 0) {
                    return false;
                }
                pendingL--;
            }
        }
        
        return pendingL == 0 && waitingR == 0;
    }
}