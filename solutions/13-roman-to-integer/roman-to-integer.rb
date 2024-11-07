def roman_to_int(s)
    roman = {
        'I' => 1, 'V' => 5, 'X' => 10,
        'L' => 50, 'C' => 100, 'D' => 500, 'M' => 1000
    }
    
    n = s.length
    result = roman[s[n-1]]
    
    (n-2).downto(0) do |i|
        if roman[s[i]] < roman[s[i+1]]
            result -= roman[s[i]]
        else
            result += roman[s[i]]
        end
    end
    
    result
end