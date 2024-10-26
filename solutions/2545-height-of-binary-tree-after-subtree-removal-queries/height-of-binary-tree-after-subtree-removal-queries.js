var treeQueries = function(root, queries) {
    const heights = new Array(50000).fill(0);
    const d = new Array(100001).fill(0);
    const l = new Array(100001).fill(0);
    const r = new Array(100001).fill(0);
    let len = 0;
    
    function search(p, h) {
        d[p.val] = h;
        
        if (!p.left && !p.right) {
            heights[len] = h;
            l[p.val] = r[p.val] = len;
            len++;
            return;
        }
        
        l[p.val] = len;
        
        if (p.left) search(p.left, h + 1);
        if (p.right) search(p.right, h + 1);
        
        r[p.val] = len - 1;
    }
    
    search(root, 0);
    
    const n = len;
    const maxl = new Array(n).fill(0);
    const maxr = new Array(n).fill(0);
    
    for (let i = 1; i < n; i++) {
        maxl[i] = Math.max(maxl[i-1], heights[i-1]);
        maxr[n-i-1] = Math.max(maxr[n-i], heights[n-i]);
    }
    
    const ret = [];
    const k = queries.length;
    
    for (let i = 0; i < k; i++) {
        const maxxl = maxl[l[queries[i]]];
        const maxxr = maxr[r[queries[i]]];
        ret.push(Math.max(Math.max(maxxl, maxxr), d[queries[i]] - 1));
    }
    
    return ret;
};