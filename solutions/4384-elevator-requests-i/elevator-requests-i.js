/**
 * @param {number} n
 * @param {number[]} requests
 * @return {number}
 */
var elevatorRequests = function(n, requests) {
    let total = 0;
    let curr = 0;
    
    for (const floor of requests) {
        total += Math.abs(curr - floor);
        curr = floor;
    }
    
    return total;
};