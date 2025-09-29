/**
 * @param {number[]} hours
 * @return {number}
 */
var countCompleteDayPairs = function(hours) {
    let ans = 0;
    for (let i = 0; i < hours.length; i++) {
        for (let j = i + 1; j < hours.length; j++) {
            if ((hours[i] + hours[j]) % 24 === 0) {
                ans++;
            }
        }
    }
    return ans;
};