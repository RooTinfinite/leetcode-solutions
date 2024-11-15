def find_length_of_shortest_subarray(arr)
    n = arr.length
    
    # 1. Find the rightmost point where array becomes non-ascending
    right = n - 1
    while right > 0 && arr[right - 1] <= arr[right]
        right -= 1
    end
    
    # 2. If array is already sorted in ascending order
    return 0 if right == 0
    
    # 3. Initial minimum length is from start to right pointer
    min_length = right
    
    # Check each element from left side
    (0...n).each do |left|
        # Break if left sequence becomes non-ascending
        break if left > 0 && arr[left - 1] > arr[left]
        
        # Find the first element from right that's >= arr[left]
        while right < n && arr[left] > arr[right]
            right += 1
        end
        
        # Update minimum length of subarray to be removed
        current_length = right - left - 1
        min_length = [min_length, current_length].min
    end
    
    min_length
end