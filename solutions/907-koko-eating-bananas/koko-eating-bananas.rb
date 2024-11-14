def min_eating_speed(piles, h)
    left = 1
    right = piles.max
    
    while left < right
        mid = left + (right - left) / 2
        
        if can_eat_all(piles, h, mid)
            right = mid
        else
            left = mid + 1
        end
    end
    
    left
end

def can_eat_all(piles, h, k)
    hours = 0
    piles.each do |pile|
        hours += (pile + k - 1) / k
        return false if hours > h
    end
    true
end