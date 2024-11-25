var validArrangement = function(pairs) {
    const adjacencyList = new Map();
    const inOutDegree = new Map();
    
    // Build graph and count in/out degrees
    for (const [from, to] of pairs) {
        if (!adjacencyList.has(from)) {
            adjacencyList.set(from, []);
        }
        adjacencyList.get(from).push(to);
        
        inOutDegree.set(from, (inOutDegree.get(from) || 0) + 1);
        inOutDegree.set(to, (inOutDegree.get(to) || 0) - 1);
    }
    
    // Find starting node
    let startNode = pairs[0][0];
    for (const [node, degree] of inOutDegree) {
        if (degree === 1) {
            startNode = node;
            break;
        }
    }
    
    const path = [];
    const nodeStack = [startNode];
    
    while (nodeStack.length > 0) {
        const neighbors = adjacencyList.get(nodeStack[nodeStack.length - 1]) || [];
        if (neighbors.length === 0) {
            path.push(nodeStack.pop());
        } else {
            const nextNode = neighbors.pop();
            nodeStack.push(nextNode);
        }
    }
    
    const arrangement = [];
    for (let i = path.length - 1; i > 0; i--) {
        arrangement.push([path[i], path[i-1]]);
    }
    
    return arrangement;
};