class Solution {
    public boolean canAliceWin(int n) {
        return canAliceWin20250929(n);
    }
    // 20250929
    public boolean canAliceWin20250929(int n) {
        return helper20250929(n - 10, 10, true);
    }
    
    public boolean helper20250929(int n, int prev, boolean alice) {
        if(n < 0) {
            return !alice;
        }
        int remove = prev - 1;
        if(n - remove < 0) {
            return alice;
        }
        return helper20250929(n - remove, remove, !alice);
    }
}