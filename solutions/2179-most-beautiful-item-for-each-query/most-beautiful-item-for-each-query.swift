class Solution {
    func maximumBeauty(_ items: [[Int]], _ queries: [Int]) -> [Int] {
        let sortedItems = items.sorted { $0[0] < $1[0] }
        let queriesWithIndex = queries.enumerated().map { ($1, $0) }.sorted { $0.0 < $1.0 }
        
        var res = Array(repeating: 0, count: queries.count)
        var maxBea = 0
        var j = 0
        
        for (query, index) in queriesWithIndex {
            while j < sortedItems.count && sortedItems[j][0] <= query {
                maxBea = max(maxBea, sortedItems[j][1])
                j += 1
            }
            res[index] = maxBea
        }
        return res
    }
}