def add_spaces(s, spaces)
    i = 0
    j = 0
    res = []
    
    while i < s.length && j < spaces.length
        if i < spaces[j]
            res.push(s[i])
            i += 1
        else
            res.push(" ")
            j += 1
        end
    end
    
    res.push(s[i..-1]) if i < s.length
    
    res.join
end