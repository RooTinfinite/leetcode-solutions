class Solution
  def max_moves(grid)
    m = grid.length 
    n = grid[0].length 
    
    res = 0
    dp = Array.new(m, 0)
    
    (1...n).each do |j|
      left_top = 0
      found = false
      
      m.times do |i|
        cur = -1
        nxt_left_top = dp[i]
        
        if i - 1 >= 0 && left_top != -1 && grid[i][j] > grid[i-1][j-1]
          cur = [cur, left_top + 1].max
        end
        
        if dp[i] != -1 && grid[i][j] > grid[i][j-1]
          cur = [cur, dp[i] + 1].max
        end
        
        if i + 1 < m && dp[i+1] != -1 && grid[i][j] > grid[i+1][j-1]
          cur = [cur, dp[i+1] + 1].max
        end
        
        dp[i] = cur
        found = found || dp[i] != -1
        left_top = nxt_left_top
      end
      
      break unless found
      res = j
    end
    
    res
  end
end

def max_moves(grid)
  Solution.new.max_moves(grid)
end