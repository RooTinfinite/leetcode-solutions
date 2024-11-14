var kClosest = function(points, k) {
    // Sort the array with a custom lambda comparator function
    points.sort((a, b) => squaredDistance(a) - squaredDistance(b))
    
    // Return the first k elements of the sorted array
    return points.slice(0, k)
};

// Calculate and return the squared Euclidean distance
const squaredDistance = ([x, y]) => x ** 2 + y ** 2