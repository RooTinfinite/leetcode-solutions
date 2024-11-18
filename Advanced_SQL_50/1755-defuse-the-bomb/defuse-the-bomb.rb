def decrypt(code, k)
    n = code.length
    res = Array.new(n, 0)
    
    return res if k == 0
    
    l = 0
    cur_sum = 0
    
    (0...(n + k.abs)).each do |r|
        cur_sum += code[r % n]
        
        if r - l + 1 > k.abs
            cur_sum -= code[l % n]
            l = (l + 1) % n
        end
        
        if r - l + 1 == k.abs
            if k > 0
                res[(l - 1) % n] = cur_sum
            elsif k < 0
                res[(r + 1) % n] = cur_sum
            end
        end
    end
    
    res
end