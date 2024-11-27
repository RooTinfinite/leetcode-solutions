def update_distances(graph, current, distances)
    new_dist = distances[current] + 1
    
    graph[current].each do |neighbor|
        next if distances[neighbor] <= new_dist
        
        distances[neighbor] = new_dist
        update_distances(graph, neighbor, distances)
    end
end

def shortest_distance_after_queries(n, queries)
    distances = (0...n).map { |i| n - 1 - i }
    
    graph = Array.new(n) { [] }
    (0...n-1).each do |i|
        graph[i + 1] << i
    end
    
    answer = []
    
    queries.each do |source, target|
        graph[target] << source
        distances[source] = [distances[source], distances[target] + 1].min
        update_distances(graph, source, distances)
        
        answer << distances[0]
    end
    
    answer
end