class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort(key = itemgetter(0))
        max_beauty = [*accumulate(map(itemgetter(1), items), max, initial = 0)]
        return [max_beauty[bisect_right(items, q, key = itemgetter(0))] for q in queries]