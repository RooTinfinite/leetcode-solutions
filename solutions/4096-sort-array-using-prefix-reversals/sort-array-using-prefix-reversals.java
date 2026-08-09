class Solution {
    public int sortArray(int[] nums, int[] pre) {
        List<Integer> start = new ArrayList<>();
        for (int num : nums) {
            start.add(num);
        }
        
        List<Integer> target = new ArrayList<>(start);
        Collections.sort(target);

        if (start.equals(target)) return 0;

        Queue<List<Integer>> queue = new LinkedList<>();
        Set<List<Integer>> visited = new HashSet<>();
        
        queue.offer(start);
        visited.add(start);

        int res = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int j = 0; j < size; j++) {
                List<Integer> curr = queue.poll();
                
                for (int i : pre) {
                    List<Integer> next = new ArrayList<>(curr);
                    // Reverse the prefix
                    Collections.reverse(next.subList(0, i));
                    
                    if (next.equals(target)) {
                        return res + 1;
                    }
                    if (!visited.contains(next)) {
                        visited.add(next);
                        queue.offer(next);
                    }
                }
            }
            res++;
        }
        return -1;
    }
}