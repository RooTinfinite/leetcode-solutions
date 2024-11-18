def decrypt(code, k)
    n = code.length
    res = Array.new(n, 0)
    
    (0...n).each do |i|
        if k > 0
            (i + 1..i + k).each do |j|
                res[i] += code[j % n]
            end
        elsif k < 0
            (i - 1).downto(i - k.abs) do |j|
                res[i] += code[j % n]
            end
        end
    end
    
    res
end