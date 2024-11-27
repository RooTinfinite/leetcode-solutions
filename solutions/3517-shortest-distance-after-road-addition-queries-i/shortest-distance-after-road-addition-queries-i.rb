def shortest_distance_after_queries(n, queries)
    adj = Array.new(n) { |i| [i + 1] }
    
    def shortest_path(adj, n)
        q = [[0, 0]]  # [node, length]
        visit = Set.new([0])
        
        while !q.empty?
            cur, length = q.shift
            return length if cur == n - 1
            
            adj[cur].each do |nei|
                if !visit.include?(nei)
                    q.push([nei, length + 1])
                    visit.add(nei)
                end
            end
        end
    end
    
    res = []
    queries.each do |src, dst|
        adj[src].push(dst)
        res.push(shortest_path(adj, n))
    end
    res
end