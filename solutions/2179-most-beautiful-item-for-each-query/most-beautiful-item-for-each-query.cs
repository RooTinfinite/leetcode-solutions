public class Solution {
    public int[] MaximumBeauty(int[][] items, int[] queries) {
        Array.Sort(items, (a, b) => a[0].CompareTo(b[0]));
        var queriesWithIndex = queries.Select((q, i) => new { Query = q, Index = i })
                                    .OrderBy(x => x.Query)
                                    .ToArray();
        
        int[] res = new int[queries.Length];
        int maxBea = 0;
        int j = 0;
        foreach (var query in queriesWithIndex) {
            while (j < items.Length && items[j][0] <= query.Query) {
                maxBea = Math.Max(maxBea, items[j][1]);
                j++;
            }
            res[query.Index] = maxBea;
        }
        return res;
    }
}