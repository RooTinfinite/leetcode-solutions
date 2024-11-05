/**
 * @param {number[][]} isConnected
 * @return {number}
 */

class UF {
    constructor(n) {
        this.p = [...Array(n).keys()];
        this.height = Array(n).fill(1);
    }

    find(u) {
        if (this.p[u] === u) return u;
        return this.find(this.p[u]);
    }

    merge(root1, root2) {
        if (root1 === root2) return;
        if (this.height[root1] < this.height[root2]) {
            [root1, root2] = [root2, root1];
        }
        this.p[root2] = root1;
        this.height[root1] = Math.max(this.height[root1], 1 + this.height[root2]);
    }
}

var findCircleNum = function(isConnected) {
    const n = isConnected.length;
    const uf = new UF(n);
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (isConnected[i][j] === 1) {
                const root1 = uf.find(i);
                const root2 = uf.find(j);
                uf.merge(root1, root2);
            }
        }
    }
        
    const components = new Set();
    for (let i = 0; i < n; i++) {
        components.add(uf.find(i));
    }
        
    return components.size;    
};