def find_length_of_shortest_subarray(arr)
    n = arr.length
    return 0 if n == 1
    
    # Find the longest non-decreasing prefix
    left = 0
    left += 1 while left + 1 < n && arr[left] <= arr[left + 1]
    
    return 0 if left == n - 1
    
    # Find the longest non-decreasing suffix
    right = n - 1
    right -= 1 while right > 0 && arr[right - 1] <= arr[right]
    
    # Initial result: remove everything between left and right
    result = [n - left - 1, right].min
    
    # Try to merge prefix and suffix
    i, j = 0, right
    while i <= left && j < n
        if arr[i] <= arr[j]
            result = [result, j - i - 1].min
            i += 1
        else
            j += 1
        end
    end
    
    result
end