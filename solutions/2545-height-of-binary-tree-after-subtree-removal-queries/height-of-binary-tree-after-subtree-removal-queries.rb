def tree_queries(root, queries)
    # Initialize arrays to store tree information
    # @heights: stores heights of leaf nodes
    # @len: tracks number of leaf nodes
    # @d: stores depth of each node
    # @l, @r: store left and right indices for each node's subtree range
    @heights = Array.new(50000, 0)
    @len = 0
    @d = Array.new(100001, 0)
    @l = Array.new(100001, 0)
    @r = Array.new(100001, 0)
    
    # Process the tree using DFS
    search(root, 0)
    
    n = @len  # Total number of leaf nodes
    # Arrays to store maximum heights from left and right perspectives
    maxl = Array.new(n, 0)
    maxr = Array.new(n, 0)
    
    # Build prefix and suffix maximum arrays
    (1...n).each do |i|
        # maxl[i] stores the maximum height of leaves to the left of index i
        maxl[i] = [maxl[i-1], @heights[i-1]].max
        # maxr[n-i-1] stores the maximum height of leaves to the right of index n-i-1
        maxr[n-i-1] = [maxr[n-i], @heights[n-i]].max
    end
    
    # Process each query
    ret = []
    queries.each do |query|
        # Find maximum height excluding current node's subtree
        maxxl = maxl[@l[query]]  # Max height to the left of subtree
        maxxr = maxr[@r[query]]  # Max height to the right of subtree
        # Result is maximum of: left max, right max, or depth-1
        ret.push([maxxl, maxxr, @d[query]-1].max)
    end
    
    ret
end

# DFS helper method to process the tree structure
def search(p, h)
    @d[p.val] = h  # Store current node's depth
    
    # If leaf node found
    if !p.left && !p.right
        @heights[@len] = h  # Store leaf height
        @l[p.val] = @r[p.val] = @len  # Mark leaf node range
        @len += 1
        return
    end
    
    @l[p.val] = @len  # Store left boundary of current subtree
    
    # Recursively process left and right children
    search(p.left, h + 1) if p.left
    search(p.right, h + 1) if p.right
    
    @r[p.val] = @len - 1  # Store right boundary of current subtree
end