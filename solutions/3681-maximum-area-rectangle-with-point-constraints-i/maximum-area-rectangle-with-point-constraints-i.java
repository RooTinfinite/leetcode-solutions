class Solution {
    public int maxRectangleArea(int[][] points) {
        TreeMap<Integer, TreeSet<Integer>> xMap = new TreeMap<>();
        HashMap<Integer, TreeSet<Integer>> yMap = new HashMap<>();

        for (int[] point : points) {
            xMap.computeIfAbsent(point[0], k -> new TreeSet<>()).add(point[1]);
            yMap.computeIfAbsent(point[1], k -> new TreeSet<>()).add(point[0]);
        }

        // Traverse through all the vertical edges and try to form a valid rectangle.
        int maxArea = -1;
        for (Map.Entry<Integer, TreeSet<Integer>> x : xMap.entrySet()) {
            // Found a vertical left edge.
            if (x.getValue().size() > 1) {
                int leftEdgeX = x.getKey();
                List<Integer> y = x.getValue().stream().toList();
                // Iterate through all the vertical left edges of a rectangle for same x.
                for (int i = 1; i < y.size(); i++) {
                    Integer rightEdgeX = yMap.get(y.get(i)).higher(leftEdgeX);
                    // Check for valid rectangle.
                    if (rightEdgeX == null
                            || !rightEdgeX.equals(yMap.get(y.get(i - 1)).higher(leftEdgeX))
                            || !isValidRectangle(xMap, leftEdgeX, rightEdgeX, y.get(i - 1), y.get(i))) {
                        continue;
                    }
                    maxArea = Math.max(
                            maxArea, (rightEdgeX - leftEdgeX) * (y.get(i) - y.get(i - 1)));
                }
            }
        }
        return maxArea;
    }

    private boolean isValidRectangle(TreeMap<Integer, TreeSet<Integer>> sortedPointsX, int x1, int x2, int y1, int y2) {
        Map<Integer, TreeSet<Integer>> betweenX = sortedPointsX.subMap(x1, true, x2, true);
        int count = 0;
        for (TreeSet<Integer> ySet : betweenX.values()) {
            // Count the number of points that fall on rectangle.
            for (Integer y : ySet) {
                if (y >= y1 && y <= y2) {
                    count++;
                }
            }
        }
        // There should always be 4 right corner points given the constraints for valid
        // rectangle.
        return count == 4;
    }
}