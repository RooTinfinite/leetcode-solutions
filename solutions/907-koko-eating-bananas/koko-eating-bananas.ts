function minEatingSpeed(piles: number[], h: number): number {
    let left: number = 1;
    let right: number = Math.max(...piles);
    
    while (left < right) {
        const mid: number = left + Math.floor((right - left) / 2);
        
        if (canEatAll(piles, h, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

function canEatAll(piles: number[], h: number, k: number): boolean {
    let hours: number = 0;
    for (const pile of piles) {
        hours += Math.ceil(pile / k);
        if (hours > h) return false;
    }
    return true;
}