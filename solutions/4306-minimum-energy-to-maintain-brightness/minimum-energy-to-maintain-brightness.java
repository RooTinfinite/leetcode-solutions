class Solution {
    public long minEnergy(int n, int brightness, int[][] intervals){
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->{
            if(a[0] != b[0]){
                return Integer.compare(a[0],b[0]);
            }
            return Integer.compare(a[1],b[1]);
        });
        for(int[] interval : intervals){
            pq.offer(interval);
        }
        long res = 0;
        int bulbCnt = (brightness + 2) / 3;
        long st = pq.peek()[0],end = pq.peek()[1];
        while(!pq.isEmpty()){
            if(end >= pq.peek()[0]){
                end = Math.max(end,pq.peek()[1]);
                pq.poll();
            }
            else{
                res += (end - st + 1) * bulbCnt;
                st = pq.peek()[0];
                end = pq.peek()[1];
            }
        }
        res += (end - st + 1) * bulbCnt;
        return res;
    }
}