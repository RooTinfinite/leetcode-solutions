class Solution {
    public int minimumOperations(int[] nums) {
        int n=nums.length;
       PriorityQueue<Integer> pq=new PriorityQueue<>();
       for(int num : nums){
        if(num!=0)
            pq.add(num);
       }
       int count=0;
       while(!pq.isEmpty())
       {
            count++;
            int top=pq.peek();

            for (int i = 0; i < n; i++) 
            {
              if (nums[i] != 0) nums[i] -= top;
            }
            pq.clear();

            for(int num : nums)
            {
                if(num!=0)
                pq.add(num);
            }
       }
       
       return count;
        
    }
}