/**
 * @param {string} customers
 * @return {number}
 */
var bestClosingTime = function(customers) {
    let max_score = 0, score = 0, best_hour = -1;
    for(let i = 0; i < customers.length; ++i) {
        score += (customers[i] === 'Y') ? 1 : -1;
        if(score > max_score) {
            max_score = score;
            best_hour = i;
        }
    }
    return best_hour + 1;
};