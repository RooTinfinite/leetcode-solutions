def minimum_time(grid)
    moves = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    
    return -1 if grid[0][1] > 1 && grid[1][0] > 1
    
    rows, cols = grid.length, grid[0].length
    pq = [[0, 0, 0]] # time, row(x), col(y)
    seen = Array.new(rows) { Array.new(cols, false) }
    seen[0][0] = true
    
    while !pq.empty?
        time, row, col = pq.shift
        
        moves.each do |dr, dc|
            new_row, new_col = row + dr, col + dc
            
            next if new_row < 0 || new_row >= rows ||
                   new_col < 0 || new_col >= cols ||
                   seen[new_row][new_col]
            
            new_time = time + 1
            if grid[new_row][new_col] > new_time
                new_time += ((grid[new_row][new_col] - time) / 2) * 2
            end
            
            return new_time if new_row == rows - 1 && new_col == cols - 1
            
            seen[new_row][new_col] = true
            
            insert_idx = pq.bsearch_index { |x| x[0] > new_time } || pq.length
            pq.insert(insert_idx, [new_time, new_row, new_col])
        end
    end
    
    -1
end