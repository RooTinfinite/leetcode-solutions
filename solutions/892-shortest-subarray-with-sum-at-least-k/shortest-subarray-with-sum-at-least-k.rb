def shortest_subarray(nums, k)
    res = Float::INFINITY
    cur_sum = 0
    q = [] # Will store [prefix_sum, end_idx]
    
    nums.each_with_index do |num, r|
        cur_sum += num
        res = [res, r + 1].min if cur_sum >= k
        
        # Find minimum valid window ending at r
        while !q.empty? && cur_sum - q[0][0] >= k
            prefix, end_idx = q.shift
            res = [res, r - end_idx].min
        end
        
        # Maintain monotonic queue
        while !q.empty? && q[-1][0] > cur_sum
            q.pop
        end
        
        q.push([cur_sum, r])
    end
    
    res == Float::INFINITY ? -1 : res
end