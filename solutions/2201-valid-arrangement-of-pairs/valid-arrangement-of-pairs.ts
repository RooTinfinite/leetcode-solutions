function validArrangement(pairs: number[][]): number[][] {
        const adjacencyList = new Map<number, number[]>();
        const inOutDegree = new Map<number, number>();
        
        // Build graph and count in/out degrees
        for (const pair of pairs) {
            if (!adjacencyList.has(pair[0])) {
                adjacencyList.set(pair[0], []);
            }
            adjacencyList.get(pair[0])!.push(pair[1]);
            inOutDegree.set(pair[0], (inOutDegree.get(pair[0]) || 0) + 1);
            inOutDegree.set(pair[1], (inOutDegree.get(pair[1]) || 0) - 1);
        }
        
        // Find starting node
        let startNode = pairs[0][0];
        for (const [node, degree] of inOutDegree.entries()) {
            if (degree === 1) {
                startNode = node;
                break;
            }
        }
        
        const path: number[] = [];
        const nodeStack: number[] = [startNode];
        
        while (nodeStack.length > 0) {
            const neighbors = adjacencyList.get(nodeStack[nodeStack.length - 1]) || [];
            if (neighbors.length === 0) {
                path.push(nodeStack.pop()!);
            } else {
                const nextNode = neighbors.pop()!;
                nodeStack.push(nextNode);
            }
        }
        
        const arrangement: number[][] = [];
        const pathSize = path.length;
        
        for (let i = pathSize - 1; i > 0; --i) {
            arrangement.push([path[i], path[i-1]]);
        }
        
        return arrangement;
    }
