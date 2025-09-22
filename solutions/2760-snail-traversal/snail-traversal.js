Array.prototype.snail = function(row, col) {
    if (row * col != this.length) return [];
    let res = Array(row).fill().map(() => []);
    for (let i = 0; i < col; i++)
        for (let j = 0; j < row; j++) {
            let index = (i & 1) ? row - j - 1: j, 
                item = this[i * row + j];
            res[index].push(item);
        }
    return res;
}