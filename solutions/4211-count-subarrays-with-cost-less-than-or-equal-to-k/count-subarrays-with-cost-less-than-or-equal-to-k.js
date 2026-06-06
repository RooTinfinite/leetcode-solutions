/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let max = []; // Monotonic decreasing queue (indices)
    let min = []; // Monotonic increasing queue (indices)
    let l = 0;
    
    // Pointers to simulate Deque behavior to avoid O(N) shift()
    let maxL = 0; 
    let minL = 0;
    
    let ans = 0;
    
    for(let r = 0; r < nums.length; r++){
        // Maintain Max Deque: Remove elements smaller than current
        while(max.length > maxL && nums[max[max.length-1]] <= nums[r]){
            max.pop();
        }
        max.push(r);
        
        // Maintain Min Deque: Remove elements larger than current
        while(min.length > minL && nums[min[min.length-1]] >= nums[r]){
            min.pop();
        }
        min.push(r);
        
        // Shrink window if the condition (max - min) * len > k is met
        while(
            (nums[max[maxL]] - nums[min[minL]]) * (r - l + 1) > k
        ){
            // If the max element is sliding out of window, move max pointer
            if(max[maxL] === l) maxL++;
            // If the min element is sliding out of window, move min pointer
            if(min[minL] === l) minL++;
            l++;
        }
        
        // Add all valid subarrays ending at r
        ans += (r - l + 1);
    }

    return ans;
};