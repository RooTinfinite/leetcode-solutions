//JavaScript Code
/**
 * @param {number[]} arr
 * @return {number}
 */
var trimMean = function(arr) {
    let sum = 0, n = arr.length, cnt = 0
    let skip = Math.floor(n / 20)
    arr.sort((a, b) => {
        return a - b
    })
    for(let i = skip; i < n - skip; ++i){
        sum += arr[i]
        cnt++
    }
    return sum / cnt
};