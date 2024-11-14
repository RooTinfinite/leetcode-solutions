class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // Sort the array with a custom lambda comparator function
        Arrays.sort(points, (a, b) -> squaredDistance(a) - squaredDistance(b));
        
        // Return the first k elements of the sorted array
        return Arrays.copyOf(points, k);
    }
    
    private int squaredDistance(int[] point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};