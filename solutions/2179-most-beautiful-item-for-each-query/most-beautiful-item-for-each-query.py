class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        sorted_items = sorted(items, key=lambda item: item[0])  # Step 1: Sort items by price
        
        prices = [item[0] for item in sorted_items] # Step 2: Extract prices and beauties
        beauties = [item[1] for item in sorted_items]
        
        max_beauties = list(accumulate(beauties, max, initial=0)) # Step 3: Create running maximum beauty array
        
        result = []     # Step 4: Find maximum beauty for each query price
        for query_price in queries:
            index = bisect_right(prices, query_price)
            result.append(max_beauties[index])
            
        return result