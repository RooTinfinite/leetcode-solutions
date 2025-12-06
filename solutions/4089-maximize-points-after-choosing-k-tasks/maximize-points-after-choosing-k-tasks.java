class Solution {
    public long maxPoints(int[] technique1, int[] technique2, int k) {
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        int count = 0;
        long total = 0L;
    
        for(int i = 0; i < technique1.length; i++) {
            if(technique1[i] >= technique2[i]) {
                total += technique1[i];
                count++;
            }
            else pq.offer(new int [] { i, technique2[i] -  technique1[i] });
        }

        while(!pq.isEmpty()) {
            int [] pair = pq.poll();
            int idx = pair[0];
            int diff = pair[1];
            
            if(count < k) {
                total += technique1[idx];
                count++;
            } else {
                total += technique2[idx];
                count++;
            }
        }

        return total;
    }
}