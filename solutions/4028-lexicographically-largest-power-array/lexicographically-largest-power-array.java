class Solution {
    public int[] largestPower(int[] nums) {
        // form a grp 
        List<List<Integer>> grps = new ArrayList<>(); 
        grps.add(Arrays.stream(nums).boxed().toList()); 
        int power[] = new int[15]; 
        for(int bit = 14; bit >= 0; bit--) {
            //msb side, left -> right 
            List<List<Integer>> next = new ArrayList<>(); 
            int cnt = 0; // cnt of set bits 
            for(int i = 0; i < grps.size(); i++) {
                List<Integer> cur = grps.get(i); 
                List<Integer> ones = new ArrayList<>(); 
                List<Integer> zeros = new ArrayList<>(); 
                for(int x: cur) {
                    if((x & (1 << bit)) > 0) {
                        ones.add(x); 
                    } else zeros.add(x); 
                }

                if(ones.size() > 0) next.add(ones);  // add them first - so we discard 0 section early 
                if(zeros.size() > 0) next.add(zeros); 
                cnt += ones.size(); 
                if(zeros.isEmpty()) {
                    // all one's 
                    continue; 
                }

                // now we have some zero's too. that means we will not go to next grps, but we need to copy them
                for(int j = i + 1; j < grps.size(); j++) next.add(grps.get(j)); 
                break;  
            }
            power[14-bit] = cnt; 
            grps = new ArrayList<>(next); 
        }
        return power; 
    }
}