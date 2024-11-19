
var shortestSubarray = function(nums, k) {
        let res = Infinity;
        let curSum = 0;
        let q = []; // stores [prefixSum, endIdx] pairs
        
        for (let r = 0; r < nums.length; r++) {
            curSum += nums[r];
            
            if (curSum >= k) {
                res = Math.min(res, r + 1);
            }
            
            // Find the minimum valid window ending at r
            while (q.length && curSum - q[0][0] >= k) {
                const [prefix, endIdx] = q.shift();
                res = Math.min(res, r - endIdx);
            }
            
            // Validate the monotonic deque
            while (q.length && q[q.length - 1][0] > curSum) {
                q.pop();
            }
            
            q.push([curSum, r]);
        }
        
        return res === Infinity ? -1 : res;
    }
