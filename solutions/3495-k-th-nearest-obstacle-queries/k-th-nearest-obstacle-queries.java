class Solution {
    public int[] resultsArray(int[][] queries, int k) {
         PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        int arr[] = new int[queries.length];
        int totalSum = 0,p=0;
        for(int i=0;i<queries.length;i++) {
            if((maxHeap.size()+1)==k) {
               int res = Math.abs(queries[i][0])+Math.abs(queries[i][1]); 
               maxHeap.add(res);
               arr[p++] = maxHeap.peek();
               continue;
            }
            else if(maxHeap.size()<k) {
               arr[p++] = -1;
               int res = Math.abs(queries[i][0])+Math.abs(queries[i][1]);
               maxHeap.add(res);
               continue;
            }
            else if(maxHeap.size()==k) {
              int res = Math.abs(queries[i][0])+Math.abs(queries[i][1]);
              if(res<=maxHeap.peek()) {
                maxHeap.poll();
                maxHeap.add(res);
                arr[p++] = maxHeap.peek();
              }
              else {
                 arr[p++] = maxHeap.peek();
              }
            }
             
        }
        return arr;
    }
}

/*
  make one max-heap
  ===
  1) check max heap if its size is less than k
   add it in max-heap

  2) if upcoming value is less than top of max heap and size is equal to k remove it from max heap

*/