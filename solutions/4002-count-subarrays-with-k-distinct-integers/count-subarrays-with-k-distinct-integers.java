class Solution {
    public long countSubarrays(int[] nums, int k, int m) {
        long res = 0;
        int leftd = 0, leftv = 0, vcount = 0;
        HashMap<Integer, Integer> countd = new HashMap<>();
        HashMap<Integer, Integer> countv = new HashMap<>();
        
        for (int right = 0; right < nums.length; right++) {
            int curr = nums[right];
            
            // Handle distinct elements window (leftd)
            countd.put(curr, countd.getOrDefault(curr, 0) + 1);
            while (countd.size() > k) {
                int temp = nums[leftd];
                int c = countd.get(temp);
                if (c == 1) countd.remove(temp);
                else countd.put(temp, c - 1);
                leftd++;
            }

            // Handle elements with at least m occurrences (leftv)
            int freq = countv.getOrDefault(curr, 0) + 1;
            countv.put(curr, freq);
            if (freq == m) vcount++;

            while (vcount >= k) {
                int y = nums[leftv];
                int cy = countv.get(y);
                if (cy == m) vcount--;
                if (cy == 1) countv.remove(y);
                else countv.put(y, cy - 1);
                leftv++;
            }
            
            // The number of valid starting positions for this 'right'
            if (leftv > leftd) res += (leftv - leftd);
        }
        return res;
    }
}