# @param {Integer[]} nums
# @return {Integer}
def longest_square_streak(nums)
    # Convert nums to a sorted set to remove duplicates and have ordered numbers
    nums = nums.uniq.sort
    
    # Create a set for O(1) lookup time
    num_set = nums.to_set
    
    # Track the maximum streak length found
    max_length = 0
    
    # Iterate through each number in sorted order
    nums.each do |num|
        # Initialize streak length for current number
        length = 0
        # Start with current number
        current = num
        
        # Keep squaring the number while it exists in our set
        while num_set.include?(current)
            length += 1
            current = current ** 2
        end
        
        # Only update max_length if we found a streak of length > 1
        if length > 1
            max_length = [max_length, length].max
        end
    end
    
    # Return max_length if we found a valid streak, otherwise return -1
    max_length > 1 ? max_length : -1
end