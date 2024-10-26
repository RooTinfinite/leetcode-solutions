def tree_queries(root, queries)
    @heights = Array.new(50000, 0)
    @len = 0
    @d = Array.new(100001, 0)
    @l = Array.new(100001, 0)
    @r = Array.new(100001, 0)
    
    search(root, 0)
    
    n = @len
    maxl = Array.new(n, 0)
    maxr = Array.new(n, 0)
    
    (1...n).each do |i|
        maxl[i] = [maxl[i-1], @heights[i-1]].max
        maxr[n-i-1] = [maxr[n-i], @heights[n-i]].max
    end
    
    ret = []
    queries.each do |query|
        maxxl = maxl[@l[query]]
        maxxr = maxr[@r[query]]
        ret.push([maxxl, maxxr, @d[query]-1].max)
    end
    
    ret
end

def search(p, h)
    @d[p.val] = h
    
    if !p.left && !p.right
        @heights[@len] = h
        @l[p.val] = @r[p.val] = @len
        @len += 1
        return
    end
    
    @l[p.val] = @len
    
    search(p.left, h + 1) if p.left
    search(p.right, h + 1) if p.right
    
    @r[p.val] = @len - 1
end