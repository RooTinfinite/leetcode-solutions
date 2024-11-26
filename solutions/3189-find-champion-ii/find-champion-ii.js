// JavaScript

var findChampion = function(n, edges) {
    const incoming = new Array(n).fill(0);
    
    for (const [src, dst] of edges) {
        incoming[dst]++;
    }
    
    const champions = [];
    for (let i = 0; i < incoming.length; i++) {
        if (incoming[i] === 0) {
            champions.push(i);
        }
    }
    
    return champions.length > 1 ? -1 : champions[0];
};