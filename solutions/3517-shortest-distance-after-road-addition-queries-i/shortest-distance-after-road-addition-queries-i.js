var updateDistances = function(graph, current, distances) {
    const newDist = distances[current] + 1;
    
    for (const neighbor of graph[current]) {
        if (distances[neighbor] <= newDist) {
            continue;
        }
        
        distances[neighbor] = newDist;
        updateDistances(graph, neighbor, distances);
    }
};

var shortestDistanceAfterQueries = function(n, queries) {
    const distances = Array(n).fill(0).map((_, i) => n - 1 - i);
    
    const graph = Array(n).fill(0).map(() => []);
    for (let i = 0; i < n-1; i++) {
        graph[i + 1].push(i);
    }
    
    const answer = [];
    
    for (const [source, target] of queries) {
        graph[target].push(source);
        distances[source] = Math.min(distances[source], distances[target] + 1);
        updateDistances(graph, source, distances);
        
        answer.push(distances[0]);
    }
    
    return answer;
};