# Helper function to calculate LIS lengths for each position
def lis_length(arr)
  # Start with first element
  lis = [arr[0]]
  # Track LIS length ending at each position
  lis_len = Array.new(arr.size, 1)

  (1...arr.size).each do |i|
    # If current element is larger than last LIS element, extend the sequence
    if arr[i] > lis[-1]
      lis.push(arr[i])
    else
      # Replace the smallest element that's >= current element
      # This maintains the potential for longer sequences
      index = lis.bsearch_index { |x| x >= arr[i] } || lis.size
      lis[index] = arr[i]
    end
    # Store length of LIS up to current position
    lis_len[i] = lis.size
  end
  lis_len
end

def minimum_mountain_removals(nums)
  n = nums.size
  
  # Get LIS lengths from left to right (increasing part)
  lis = lis_length(nums)
  
  # Get LIS lengths from right to left (decreasing part)
  nums.reverse!
  lds = lis_length(nums)
  lds.reverse!
  nums.reverse! # restore original array
  
  removals = Float::INFINITY
  
  # For each potential peak position
  (0...n).each do |i|
    # Valid mountain needs both sides to have length > 1
    if lis[i] > 1 && lds[i] > 1
      # Calculate removals needed:
      # Total length - (increasing length + decreasing length - 1)
      # -1 because peak is counted twice
      removals = [removals, n + 1 - lis[i] - lds[i]].min
    end
  end
  
  removals
end