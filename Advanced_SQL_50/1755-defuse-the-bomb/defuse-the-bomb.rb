def decrypt(circ, k)
    n = circ.size
    result = Array.new(n, 0)
    
    return result if k == 0
    
    w_sum = 0
    start = k > 0 ? 1 : n + k
    end_pos = k > 0 ? k : n - 1
    
    (start..end_pos).each do |i|
        w_sum += circ[i % n]
    end
    
    n.times do |i|
        result[i] = w_sum
        w_sum -= circ[(start + i) % n]
        w_sum += circ[(end_pos + i + 1) % n]
    end
    
    result
end