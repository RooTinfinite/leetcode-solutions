def roman_to_int(s)
    def calc_scale(c, a1, a2)
        (c == a1 || c == a2) ? -1 : 1
    end
    
    result = 0
    chars = s.chars
    
    (0...chars.length).each do |n|
        next_char = chars[n + 1]
        
        case chars[n]
        when 'M'
            result += 1000
        when 'D'
            result += 500
        when 'C'
            result += 100 * calc_scale(next_char, 'M', 'D')
        when 'L'
            result += 50
        when 'X'
            result += 10 * calc_scale(next_char, 'C', 'L')
        when 'V'
            result += 5
        when 'I'
            result += 1 * calc_scale(next_char, 'X', 'V')
        end
    end
    
    result
end