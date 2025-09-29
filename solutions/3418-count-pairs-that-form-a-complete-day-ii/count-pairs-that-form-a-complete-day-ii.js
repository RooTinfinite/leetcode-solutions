/**
 * @param {number[]} hours
 * @return {number}
 */
var countCompleteDayPairs = function(hours) {
    let ans = 0;
    let count = new Array(24).fill(0);
    for (let hour of hours) {
        ans += count[(24 - hour % 24) % 24];
        count[hour % 24]++;
    }
        
    return ans;
};