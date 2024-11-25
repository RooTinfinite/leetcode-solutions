var validArrangement = function(pairs) {
    const graph = new Map();
    const indegree = new Map();
    const outdegree = new Map();
    
    // Build graph and degrees
    for (const [from, to] of pairs) {
        if (!graph.has(from)) graph.set(from, []);
        graph.get(from).push(to);
        
        outdegree.set(from, (outdegree.get(from) || 0) + 1);
        indegree.set(to, (indegree.get(to) || 0) + 1);
    }
    
    let start = pairs[0][0];
    for (const node of outdegree.keys()) {
        const out = outdegree.get(node) || 0;
        const inn = indegree.get(node) || 0;
        if (out - inn === 1) {
            start = node;
            break;
        }
    }
    
    function hierholzer(node) {
        const stack = [];
        const path = [];
        stack.push(node);
        
        while (stack.length) {
            const current = stack[stack.length - 1];
            if (!graph.has(current) || !graph.get(current).length) {
                path.push(stack.pop());
            } else {
                const next = graph.get(current).pop();
                stack.push(next);
            }
        }
        
        return path.reverse();
    }
    
    const path = hierholzer(start);
    const result = [];
    
    for (let i = 0; i < path.length - 1; i++) {
        result.push([path[i], path[i + 1]]);
    }
    
    return result;
};