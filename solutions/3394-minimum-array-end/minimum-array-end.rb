def min_end(n, x)
    # Store available bit positions that are 0 in x
    shifts = []
    
    # Initialize result with starting number x
    cur = x
    
    # Calculate how many 1's we need to add (n-1)
    calc = n - 1
    
    # Find all bit positions that are 0 in x (up to 32 bits)
    (0..31).each do |i|
        shifts.push(i) if ((1 << i) & x) == 0
    end
    
    # Add remaining positions 32-63 for larger numbers
    (32..63).each do |i|
        shifts.push(i)
    end
    
    # Process each bit in calc (n-1)
    i = 0
    while calc > 0
        cur += (calc & 1) << shifts[i]
        calc >>= 1
        i += 1
    end
    
    cur
end