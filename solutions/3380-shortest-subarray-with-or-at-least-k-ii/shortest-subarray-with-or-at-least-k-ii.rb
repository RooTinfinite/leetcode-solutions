def minimum_subarray_length(nums, k)
    ans = Float::INFINITY
    d = {}
    
    nums.each_with_index do |x, i|
        temp = {}
        d.each do |or_, left|
            temp[or_ | x] = left
        end
        temp[x] = i
        d = temp
        
        d.each do |or_, left|
            if or_ >= k
                ans = [ans, i - left + 1].min
            end
        end
    end
    
    ans == Float::INFINITY ? -1 : ans
end