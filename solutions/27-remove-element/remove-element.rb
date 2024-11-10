def remove_element(nums, val)
    write_index = 0
    
    nums.each_with_index do |num, read_index|
        if num != val
            nums[write_index] = nums[read_index]
            write_index += 1
        end
    end
    
    write_index
end