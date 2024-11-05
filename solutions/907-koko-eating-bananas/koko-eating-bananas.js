var minEatingSpeed = function (piles, h) {
    let l = 1
    let high = Math.max(...piles)
    let ans = -1
    function checkHrs(mid, piles) {
        let hrs = 0
        console.log(mid)
        for (let i = 0; i < piles.length; i++) {
            hrs += Math.ceil(piles[i] / mid)
        }
        console.log(hrs, 'hrs')
        return hrs
    }

    while (l <= high) {
        let mid = Math.floor((l + high) / 2)

        const hrs = checkHrs(mid, piles)

        if (hrs <= h) {
            ans = mid
            high = mid - 1
        }
        else l = mid + 1
    }
    return ans
};