// TypeScript

function findChampion(n: number, edges: number[][]): number {
    const isUndefeated: boolean[] = new Array(n).fill(true);
    
    for (const [winner, loser] of edges) {
        isUndefeated[loser] = false;
    }
    
    let champion: number = -1;
    let championCount: number = 0;
    
    for (let team = 0; team < n; team++) {
        if (isUndefeated[team]) {
            champion = team;
            championCount++;
        }
    }
    
    return championCount === 1 ? champion : -1;
}