def take_characters(s, k)
    freq = [0, 0, 0]
    n = s.length
    
    s.each_char do |c|
        freq[c.ord - 'a'.ord] += 1
    end
    
    return -1 if freq[0] < k || freq[1] < k || freq[2] < k
    
    curr = [0, 0, 0]
    max_len = 0
    left = 0
    
    (0...n).each do |right|
        curr[s[right].ord - 'a'.ord] += 1
        
        while left <= right && (curr[0] > freq[0] - k ||
               curr[1] > freq[1] - k ||
               curr[2] > freq[2] - k)
            curr[s[left].ord - 'a'.ord] -= 1
            left += 1
        end
        
        max_len = [max_len, right - left + 1].max
    end
    
    n - max_len
end