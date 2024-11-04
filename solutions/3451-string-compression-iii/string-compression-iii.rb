def compressed_string(word)
    return "" if word.empty?
    
    comp = ""
    cnt = 1
    ch = word[0]
    
    (1...word.length).each do |i|
        if word[i] == ch && cnt < 9
            cnt += 1
        else
            comp << cnt.to_s << ch
            ch = word[i]
            cnt = 1
        end
    end
    
    comp << cnt.to_s << ch
    comp
end