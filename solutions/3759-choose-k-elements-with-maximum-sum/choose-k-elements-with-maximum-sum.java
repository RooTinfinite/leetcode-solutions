class Solution {
    public long[] findMaxSum(int[] nums1, int[] nums2, int k) {
        int l = nums1.length;
        Integer[] idx = new Integer[l];
        for(int i=0;i<l;i++)
            idx[i] = i;
        // quickSort(idx , nums1 , nums2 , 0 , l-1);
        // arrays.sort seems to be faster than my quicksort
        // probably takes O(nlogn) time
        Arrays.sort(idx , new Comparator<Integer>() {
            @Override
            public int compare(Integer i , Integer j){
                return nums1[i] - nums1[j];
            }
        });
        //copy the nums1 and nums2 using a third array 
        // they become sorted as idx[] which is sorted according to nums1
        int[] temp =new int[l];
        for(int i=0;i<l;i++)
            temp[i] = nums1[idx[i]];
        for(int i=0;i<l;i++)
            nums1[i] = temp[i];
        for(int i=0;i<l;i++)
            temp[i] = nums2[idx[i]];
        for(int i=0;i<l;i++)
            nums2[i] = temp[i];

        //answer array to store answer
        long[] ans = new long[nums1.length];
        long sum = 0;//sum to store the sum of the k max elements
        //min queue to get the minimum to elements
        // this queue is restricted  with the size k
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y)->(x - y));
        //size of the min queue
        int size = 0;

        // loop that works n times
        for(int i = 0;i<l;){
            int j=i;
            long new_sum = sum;
            //calculate the sumn for the same elements which are present
            // we nned the maximum sum of the element indexes of the numbers less than the current number
            for(j = i;j<l && nums1[j]==nums1[i];j++){
                //assign answer to idx[j] index with the previously calculated sum.
                ans[idx[j]] = sum;

                // if the size is less than k we simply add to the min queue
                // and update the new_sum and size
                if(size < k){
                    new_sum += nums2[j];
                    pq.add(nums2[j]);
                    size++;
                }
                else{
                    /** if size==k
                    then check ifd the current value of nums2[j]
                    is greater than the minimum element in the queue
                    if it is smaller we donot need to change any thing
                    if it is not we remove minimum element from queue
                    and minus it from the new_sum
                    add the new number to min q and new_sum 
                    the size remains == k thefore no change required there.
                     */
                    if(nums2[j] > pq.peek()){
                        new_sum -= pq.remove();
                        new_sum += nums2[j];
                        pq.add(nums2[j]);
                    }
                }
            }
            // update the i = j which is the next unequal element in nums1(sorted)
            i = j;
            //update sum to the newly calculated sum
            sum = new_sum;
        }
        //total time cpmplexity of the loop  : O(nlogk)
        return ans;
    }
    // void quickSort(int[] idx , int[] nums1 , int[] nums2 , int l , int h){
    //     if(h <= l)
    //         return;
    //     int p = findPartition(idx , nums1 , nums2 , l , h);        
    //     quickSort(idx , nums1 , nums2 , l , p-1);
    //     quickSort(idx , nums1 , nums2 , p+1 , h);            
        
    // }
    // int findPartition(int[] idx , int[] nums1 , int[] nums2, int l , int h){
    //     int pivot = h;
    //     int i = l-1;
    //     for(int j = l;j<h;j++){
    //         if(nums1[j] <= nums1[pivot]){
    //             i++;
    //             swap(nums1 , i , j);
    //             swap(idx , i , j);
    //             swap(nums2 , i, j);
    //         }
    //     }
    //     swap(nums1 , i+1 ,pivot);
    //     swap(nums2 , i+1 ,pivot);
    //     swap(idx , i+1 ,pivot);
    //     return i+1;
    // }
    // void swap(int[] arr , int i , int j){
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }
}