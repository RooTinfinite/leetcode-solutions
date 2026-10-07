/**
 * @param {string} s
 * @return {string[]}
 */
var removeInvalidParentheses = function(s) {
    const isValid = (str) => {
        let count = 0;
        for (let char of str) {
            if (char === '(') count++;
            if (char === ')') {
                if (count === 0) return false;
                count--;
            }
        }
        return count === 0;
    };
    
    let result = [];
    let visited = new Set([s]);
    let queue = [s];
    let found = false;
    
    while (queue.length > 0) {
        let curr = queue.shift();
        
        if (isValid(curr)) {
            result.push(curr);
            found = true;
        }
        
        if (found) continue;
        
        for (let i = 0; i < curr.length; i++) {
            if (curr[i] !== '(' && curr[i] !== ')') continue;
            let nextState = curr.slice(0, i) + curr.slice(i + 1);
            if (!visited.has(nextState)) {
                visited.add(nextState);
                queue.push(nextState);
            }
        }
    }
    return result;
};