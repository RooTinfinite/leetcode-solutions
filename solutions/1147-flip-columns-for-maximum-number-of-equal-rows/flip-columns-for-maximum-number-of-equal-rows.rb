def max_equal_rows_after_flips(matrix)
    count = Hash.new(0)
    
    matrix.each do |row|
        key = row.map { |n| row[0] == 1 ? 1 - n : n }
        count[key] += 1
    end
    
    count.values.max
end