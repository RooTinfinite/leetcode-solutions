def first_uniq_char(s)
    count = Hash.new(0)
    
    s.each_char do |c|
        count[c] += 1
    end
    
    s.each_char.with_index do |c, i|
        return i if count[c] == 1
    end
    -1
end