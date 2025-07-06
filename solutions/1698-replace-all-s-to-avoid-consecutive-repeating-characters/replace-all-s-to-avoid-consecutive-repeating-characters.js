/**
 * @param {string} s
 * @return {string}
 */
var modifyString = function(s) {
    let arr = s.split('');
    let n = arr.length;

    for (let i = 0; i < n; i++) {
        if (arr[i] === '?') {
            let left = (i > 0) ? arr[i - 1] : ' ';
            let right = (i + 1 < n) ? arr[i + 1] : ' ';

            arr[i] = (left !== 'a' && right !== 'a') ? 'a' :
                     (left !== 'b' && right !== 'b') ? 'b' : 'c';
        }
    }
    return arr.join('');
};