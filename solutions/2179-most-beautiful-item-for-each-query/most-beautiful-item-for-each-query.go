func maximumBeauty(items [][]int, queries []int) []int {
    sort.Slice(items, func(i, j int) bool {
        return items[i][0] < items[j][0]
    })
    
    type Query struct {
        val, idx int
    }
    queriesWithIndex := make([]Query, len(queries))
    for i, q := range queries {
        queriesWithIndex[i] = Query{q, i}
    }
    sort.Slice(queriesWithIndex, func(i, j int) bool {
        return queriesWithIndex[i].val < queriesWithIndex[j].val
    })
    
    res := make([]int, len(queries))
    maxBea := 0
    j := 0
    for _, q := range queriesWithIndex {
        for j < len(items) && items[j][0] <= q.val {
            if items[j][1] > maxBea {
                maxBea = items[j][1]
            }
            j++
        }
        res[q.idx] = maxBea
    }
    return res
}