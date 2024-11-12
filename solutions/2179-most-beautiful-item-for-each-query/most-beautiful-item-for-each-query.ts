// TypeScript

function maximumBeauty(items: number[][], queries: number[]): number[] {
    // Step 1: Sort items by price in ascending order
    items.sort((a, b) => a[0] - b[0]);
    
    // Step 2: Extract prices and beauties into separate arrays
    const prices: number[] = items.map(item => item[0]);
    const beauties: number[] = items.map(item => item[1]);
    
    // Step 3: Create running maximum beauty array
    const maxBeauties: number[] = [0];
    let currentMax = 0;
    for (const beauty of beauties) {
        currentMax = Math.max(currentMax, beauty);
        maxBeauties.push(currentMax);
    }
    
    // Step 4: Process each query using binary search
    return queries.map(query => {
        const index = upperBound(prices, query);
        return maxBeauties[index];
    });
}

// Helper function for binary search
function upperBound(arr: number[], target: number): number {
    let left = 0, right = arr.length;
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}