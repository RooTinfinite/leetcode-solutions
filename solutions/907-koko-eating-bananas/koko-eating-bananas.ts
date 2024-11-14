// JavaScript

var minEatingSpeed = function(piles, h) {
    let left = 1;
    let right = Math.max(...piles);
    
    while (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        
        if (canEatAll(piles, h, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
};

function canEatAll(piles, h, k) {
    let hours = 0;
    for (const pile of piles) {
        hours += Math.ceil(pile / k);
        if (hours > h) return false;
    }
    return true;
}