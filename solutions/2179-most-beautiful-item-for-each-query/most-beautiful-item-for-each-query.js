var maximumBeauty = function(items, queries) {
    // Step 1: Sort items by price
    items.sort((a, b) => a[0] - b[0]);
    
    // Step 2: Extract prices and beauties
    const prices = items.map(item => item[0]);
    const beauties = items.map(item => item[1]);
    
    // Step 3: Create running maximum beauty array
    const maxBeauties = [0];
    let currentMax = 0;
    for (const beauty of beauties) {
        currentMax = Math.max(currentMax, beauty);
        maxBeauties.push(currentMax);
    }
    
    // Step 4: Find maximum beauty for each query price using binary search
    return queries.map(query => {
        let left = 0, right = prices.length;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (prices[mid] <= query) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return maxBeauties[left];
    });
};