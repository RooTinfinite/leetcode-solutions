def count_unguarded(m, n, guards, walls)
    # Initialize grid with zeros
    g = Array.new(m) { Array.new(n, 0) }
    
    # Mark guards and walls as 2
    guards.each { |x, y| g[x][y] = 2 }
    walls.each { |x, y| g[x][y] = 2 }
    
    # Directions: up, right, down, left
    dirs = [-1, 0, 1, 0, -1]
    
    # Process each guard's line of sight
    guards.each do |guard_x, guard_y|
        4.times do |k|
            x, y = guard_x, guard_y
            dx, dy = dirs[k], dirs[k + 1]
            
            # Check cells in current direction until hitting boundary or obstacle
            while x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && g[x + dx][y + dy] < 2
                x += dx
                y += dy
                g[x][y] = 1
            end
        end
    end
    
    # Count unguarded cells (cells with value 0)
    g.sum { |row| row.count(0) }
end
