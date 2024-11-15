class UnionFind {
    constructor(size) {
        this.group = new Array(size).fill(0);
        this.rank = new Array(size).fill(0);
        for (let i = 0; i < size; ++i) {
            this.group[i] = i;
        }
    }

    find(node) {
        if (this.group[node] != node) {
            this.group[node] = this.find(this.group[node]);
        }
        return this.group[node];
    }

    union(node1, node2) {
        let group1 = this.find(node1);
        let group2 = this.find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return false;
        }

        if (this.rank[group1] > this.rank[group2]) {
            this.group[group2] = group1;
        } else if (this.rank[group1] < this.rank[group2]) {
            this.group[group1] = group2;
        } else {
            this.group[group1] = group2;
            this.rank[group2] += 1;
        }

        return true;
    }
};


let minCostConnectPoints = function(points) {
    let n = points.length;
    let allEdges = [];

    // Storing all edges of our complete graph.
    for (let currNode = 0; currNode < n; ++currNode) {
        for (let nextNode = currNode + 1; nextNode < n; ++nextNode) {
            let weight = Math.abs(points[currNode][0] - points[nextNode][0]) + 
                         Math.abs(points[currNode][1] - points[nextNode][1]);

            allEdges.push([weight, currNode, nextNode]);
        }
    }

    // Sort all edges in increasing order.
    allEdges.sort((a, b) => a[0] - b[0]);

    let uf = new UnionFind(n);
    let mstCost = 0;
    let edgesUsed = 0;

    for (let i = 0; i < allEdges.length && edgesUsed < n - 1; ++i) {
        let [weight, node1, node2] = allEdges[i];

        if (uf.union(node1, node2)) {
            mstCost += weight;
            edgesUsed++;
        }
    }

    return mstCost;
};