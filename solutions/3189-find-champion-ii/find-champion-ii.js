// JavaScript

var findChampion = function(n, edges) {
    const isUndefeated = new Array(n).fill(true);
    
    for (const [winner, loser] of edges) {
        isUndefeated[loser] = false;
    }
    
    let champion = -1;
    let championCount = 0;
    
    for (let team = 0; team < n; team++) {
        if (isUndefeated[team]) {
            champion = team;
            championCount++;
        }
    }
    
    return championCount === 1 ? champion : -1;
};