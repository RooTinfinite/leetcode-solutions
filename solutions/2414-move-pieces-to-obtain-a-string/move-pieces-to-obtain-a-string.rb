def can_change(start, target)
    return true if start == target
    wait_l = 0
    wait_r = 0
    
    start.chars.zip(target.chars).each do |curr, goal|
        if curr == 'R'
            return false if wait_l > 0
            wait_r += 1
        end
        if goal == 'L'
            return false if wait_r > 0
            wait_l += 1
        end
        if goal == 'R'
            return false if wait_r == 0
            wait_r -= 1
        end
        if curr == 'L'
            return false if wait_l == 0
            wait_l -= 1
        end
    end
    wait_l == 0 && wait_r == 0
end