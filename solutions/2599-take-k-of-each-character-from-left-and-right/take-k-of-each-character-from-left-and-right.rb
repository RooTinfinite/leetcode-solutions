def take_characters(s, k)
    # Total counts
    count = [0, 0, 0]
    s.each_char do |c|
        count[c.ord - 'a'.ord] += 1
    end
    
    return -1 if count.min < k
    
    # Sliding Window
    res = Float::INFINITY
    l = 0
    s.length.times do |r|
        count[s[r].ord - 'a'.ord] -= 1
        
        while count.min < k
            count[s[l].ord - 'a'.ord] += 1
            l += 1
        end
        res = [res, s.length - (r - l + 1)].min
    end
    res
end