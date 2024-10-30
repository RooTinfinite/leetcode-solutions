// Helper function to calculate LIS lengths for each position
function lisLength(v: number[]): number[] {
    // Start with first element
    const lis: number[] = [v[0]];
    // Track LIS length ending at each position
    const lisLen: number[] = new Array(v.length).fill(1);

    for (let i = 1; i < v.length; i++) {
        // If current element is larger than last LIS element, extend the sequence
        if (v[i] > lis[lis.length - 1]) {
            lis.push(v[i]);
        } else {
            // Replace the smallest element that's >= current element
            // This maintains the potential for longer sequences
            const index = lowerBound(lis, v[i]);
            lis[index] = v[i];
        }
        // Store length of LIS up to current position
        lisLen[i] = lis.length;
    }
    return lisLen;
}

// Helper function to implement lower_bound functionality
function lowerBound(arr: number[], target: number): number {
    let left = 0;
    let right = arr.length;
    
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

function minimumMountainRemovals(nums: number[]): number {
    const n = nums.length;
    
    // Get LIS lengths from left to right (increasing part)
    const lis = lisLength(nums);
    
    // Get LIS lengths from right to left (decreasing part)
    nums.reverse();
    const lds = lisLength(nums);
    lds.reverse();
    nums.reverse(); // restore original array
    
    let removals = Number.MAX_SAFE_INTEGER;
    
    // For each potential peak position
    for (let i = 0; i < n; i++) {
        // Valid mountain needs both sides to have length > 1
        if (lis[i] > 1 && lds[i] > 1) {
            // Calculate removals needed:
            // Total length - (increasing length + decreasing length - 1)
            // -1 because peak is counted twice
            removals = Math.min(removals, n + 1 - lis[i] - lds[i]);
        }
    }
    
    return removals;
}