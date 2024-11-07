def largest_combination(candidates)
    # Create array to store count of 1's at each bit position
    ans = Array.new(32, 0)
    
    # Process each number in candidates array
    candidates.each do |x|
        find(x, ans)
    end
    
    # Find the maximum count of 1's across all bit positions
    ans.max
end

def find(n, ans)
    j = 31
    
    while n > 0
        # Get rightmost bit
        a = n & 1
        
        # Add bit count to corresponding position
        ans[j] += a
        
        # Right shift n by 1
        n >>= 1
        
        j -= 1
    end
end

