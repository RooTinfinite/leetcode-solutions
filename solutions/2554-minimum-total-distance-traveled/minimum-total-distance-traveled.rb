def minimum_total_distance(robot, factory)
    robot.sort!
    factory.sort!
    
    m, n = robot.length, factory.length
    dp = Array.new(m + 1) { Array.new(n + 1, 0) }
    
    # Base case
    m.times { |i| dp[i][n] = Float::INFINITY }
    
    # Process each factory from right to left
    (n-1).downto(0) do |j|
        prefix = 0
        qq = [[m, 0]]
        
        # Process each robot from right to left
        (m-1).downto(0) do |i|
            prefix += (robot[i] - factory[j][0]).abs
            
            # Remove elements outside factory limit window
            qq.shift if qq[0][0] > i + factory[j][1]
            
            # Maintain monotonic queue property
            while !qq.empty? && qq[-1][1] >= dp[i][j+1] - prefix
                qq.pop
            end
            
            qq.push([i, dp[i][j+1] - prefix])
            dp[i][j] = qq[0][1] + prefix
        end
    end
    
    dp[0][0]
end