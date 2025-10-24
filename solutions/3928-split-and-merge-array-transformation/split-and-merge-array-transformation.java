class Solution {
    public int minSplitMerge(int[] nums1, int[] nums2) {
        int n = nums1.length;
        List<Integer> n1 = new ArrayList<>();
        for (int i : nums1) n1.add(i);
        List<Integer> n2 = new ArrayList<>();
        for (int i : nums2) n2.add(i);
        if (n1.equals(n2)) return 0;
        
        Queue<List<Integer>> q = new LinkedList<>();
        Set<List<Integer>> st = new HashSet<>();
        q.offer(n1);
        st.add(n1);
        int steps = 0; 
        
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                List<Integer> crr = q.poll();
                if (crr.equals(n2)) return steps;
                
                for (int l = 0; l < n; l++) {
                    for (int r = l; r < n; r++) {
                        List<Integer> left = new ArrayList<>(crr.subList(0, l));
                        List<Integer> right = new ArrayList<>(crr.subList(r + 1, n));
                        List<Integer> rem = new ArrayList<>(crr.subList(l, r + 1));
                        
                        List<Integer> newli = new ArrayList<>();
                        newli.addAll(left);
                        newli.addAll(right);
                        
                        for (int idx = 0; idx <= newli.size(); idx++) {
                            List<Integer> finalli = new ArrayList<>(newli);
                            finalli.addAll(idx, rem);
                            if (!st.contains(finalli)) {
                                st.add(finalli);
                                q.offer(finalli);
                            }
                        }
                    }
                }
            }
            steps++;  
        }
        return -1; 
    }
}