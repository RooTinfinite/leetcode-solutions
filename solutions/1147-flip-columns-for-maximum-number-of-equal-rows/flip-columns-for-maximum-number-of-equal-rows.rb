def max_equal_rows_after_flips(mat)
    pat_freq = Hash.new(0)
    
    mat.each do |row|
        pattern = row[0] == 0 ? 
            row.join : 
            row.map { |bit| bit ^ 1 }.join
            
        pat_freq[pattern] += 1
    end
    
    pat_freq.values.max
end