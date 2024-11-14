var getRow = function(rowIndex) {
    let res = [1];
    let prev = 1;
    for(let k = 1; k <= rowIndex; k++) {
        let next_val = prev * (rowIndex - k + 1) / k;
        res.push(next_val);
        prev = next_val;
    }
    return res;
};