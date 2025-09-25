/**
 * @param {number[][]} grid
 * @return {number}
 */
var findChampion = function(grid) {
    let winner = 0;
    const n = grid.length;
    for (let opponent = 0; opponent < n; opponent++) {
        if (opponent === winner) continue;
        if (grid[winner][opponent] === 0) {
            winner = opponent;
        }
    }
    return winner;
};