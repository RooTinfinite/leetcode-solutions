const specialNodes = (
    numNodes: number, 
    edges: number[][], 
    targetX: number, 
    targetY: number, 
    targetZ: number
): number => {
    const adjacencyList: number[][] = Array.from({ length: numNodes }, () => []);
    
    for (const [nodeU, nodeV] of edges) {
        adjacencyList[nodeU].push(nodeV);
        adjacencyList[nodeV].push(nodeU);
    }

    const computeDistancesFromNode = (startNode: number): number[] => {
        const distances = new Int32Array(numNodes).fill(-1);
        distances[startNode] = 0;
        
        const queue: number[] = [startNode];
        let queueReadIndex = 0;

        while (queueReadIndex < queue.length) {
            const currentNode = queue[queueReadIndex++];
            const currentDistance = distances[currentNode];

            for (const neighbor of adjacencyList[currentNode]) {
                if (distances[neighbor] === -1) {
                    distances[neighbor] = currentDistance + 1;
                    queue.push(neighbor);
                }
            }
        }
        
        return distances as unknown as number[];
    };

    const distancesFromX = computeDistancesFromNode(targetX);
    const distancesFromY = computeDistancesFromNode(targetY);
    const distancesFromZ = computeDistancesFromNode(targetZ);

    let specialNodeCount = 0;

    for (let node = 0; node < numNodes; node++) {
        const distToX = distancesFromX[node];
        const distToY = distancesFromY[node];
        const distToZ = distancesFromZ[node];

        let smallest, middle, largest;
        
        if (distToX <= distToY && distToX <= distToZ) {
            smallest = distToX;
            if (distToY <= distToZ) {
                middle = distToY;
                largest = distToZ;
            } else {
                middle = distToZ;
                largest = distToY;
            }
        } else if (distToY <= distToX && distToY <= distToZ) {
            smallest = distToY;
            if (distToX <= distToZ) {
                middle = distToX;
                largest = distToZ;
            } else {
                middle = distToZ;
                largest = distToX;
            }
        } else {
            smallest = distToZ;
            if (distToX <= distToY) {
                middle = distToX;
                largest = distToY;
            } else {
                middle = distToY;
                largest = distToX;
            }
        }

        if (smallest * smallest + middle * middle === largest * largest) {
            specialNodeCount++;
        }
    }

    return specialNodeCount;
};