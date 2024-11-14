func minEatingSpeed(piles []int, h int) int {
    left := 1
    right := 0
    
    for _, pile := range piles {
        if pile > right {
            right = pile
        }
    }
    
    for left < right {
        mid := left + (right - left) / 2
        
        if canEatAll(piles, h, mid) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    
    return left
}

func canEatAll(piles []int, h int, k int) bool {
    hours := 0
    for _, pile := range piles {
        hours += (pile + k - 1) / k
        if hours > h {
            return false
        }
    }
    return true
}