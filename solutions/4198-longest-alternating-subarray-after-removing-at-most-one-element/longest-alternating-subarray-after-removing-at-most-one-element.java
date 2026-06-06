class Solution {
    public int longestAlternating(int[] nums) {
        int l, r; l = 0; r = 1;
        Boolean up, used; up = null; used = false;
        int maxx = 0; int usedIdx = 0;

        while (r <= nums.length - 1) {
            int n1, n2; n1 = nums[r-1]; n2 = nums[r];
            // up
            if (n1 < n2) {
                // prev up
                if(up != null && up) {
                    if (used) {
                        used = false;
                        l = usedIdx;
                    } else { 
                        used = true;
                        usedIdx = r-1;
                        maxx = Math.max(maxx, r-l);
                        r++;
                    }
                } else { 
                    maxx = used ? Math.max(maxx, r-l) : Math.max(maxx, r-l+1);
                    r++;
                }
                up = true;
            // down
            } else if (n1 > n2) {
                //prev down
                if(up != null && !up) {
                   if (used) {
                        used = false;
                        l = usedIdx;
                    } else {
                        used = true;
                        usedIdx = r-1;
                        maxx = Math.max(maxx, r-l);
                        r++;
                    }
                } else {
                    maxx = used ? Math.max(maxx, r-l) : Math.max(maxx, r-l+1);
                    r++;
                }
                up = false;
            // same
            } else{
                if (used) {
                    used = false;
                    l = usedIdx;
                } else {
                    used = true;
                    usedIdx = r;
                    maxx = Math.max(maxx, r-l);
                    r++;
                }
            }
        }
        return maxx;
    }
}