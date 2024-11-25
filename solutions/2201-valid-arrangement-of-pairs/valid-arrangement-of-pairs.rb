def valid_arrangement(pairs)
    adjacency_list = Hash.new { |h, k| h[k] = [] }
    in_out_degree = Hash.new(0)
    
    # Build graph and count in/out degrees
    pairs.each do |pair|
        adjacency_list[pair[0]] << pair[1]
        in_out_degree[pair[0]] += 1  # out-degree
        in_out_degree[pair[1]] -= 1  # in-degree
    end
    
    # Find starting node
    start_node = pairs[0][0]
    in_out_degree.each do |node, degree|
        if degree == 1
            start_node = node
            break
        end
    end
    
    path = []
    node_stack = [start_node]
    
    while !node_stack.empty?
        neighbors = adjacency_list[node_stack.last]
        if neighbors.empty?
            path << node_stack.pop
        else
            next_node = neighbors.pop
            node_stack << next_node
        end
    end
    
    arrangement = []
    path_size = path.size
    
    (path_size - 1).downto(1) do |i|
        arrangement << [path[i], path[i-1]]
    end
    
    arrangement
end