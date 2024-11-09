def min_end(n, x)
    result = x
    remaining = n - 1
    position = 1
    
    while remaining != 0
        if (x & position) == 0
            result |= (remaining & 1) * position
            remaining >>= 1
        end
        position <<= 1
    end
    
    result.to_i
end