class Solution {

    // Calculates the greatest common divisor (GCD) of two non-negative integers.
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Counts the number of unique trapezoids that can be formed from a given set of points.
    public int countTrapezoids(int[][] points) {
        int n = points.length;
        if (n < 4) {
            return 0; // Not enough points to form a quadrilateral.
        }

        // --- Step 1: Count pairs of parallel segments efficiently ---
        long countPairs = 0;
        // Map from a slope to a map of lines with that slope.
        // Inner map: line identifier -> number of segments on that line.
        Map<String, Map<Long, Integer>> slopeToLinesMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long x1 = points[i][0], y1 = points[i][1];
                long x2 = points[j][0], y2 = points[j][1];
                long dx_long = x2 - x1, dy_long = y2 - y1;

                String slopeKey;
                long lineId;

                if (dx_long == 0) {
                    slopeKey = "inf"; // Vertical line
                    lineId = x1; // Line is identified by its x-coordinate
                } else {
                    int commonDivisor = gcd((int)Math.abs(dx_long), (int)Math.abs(dy_long));
                    long dx = dx_long / commonDivisor;
                    long dy = dy_long / commonDivisor;
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    slopeKey = dy + "/" + dx;
                    // Line identifier: from y = (dy/dx)x + c => c*dx = y*dx - x*dy
                    lineId = y1 * dx - x1 * dy;
                }

                // Get the map of lines for the current slope.
                Map<Long, Integer> linesMap = slopeToLinesMap.get(slopeKey);
                // If no map exists for this slope, create one.
                if (linesMap == null) {
                    linesMap = new HashMap<>();
                    slopeToLinesMap.put(slopeKey, linesMap);
                }
                // Increment the count for the specific line.
                linesMap.put(lineId, linesMap.getOrDefault(lineId, 0) + 1);
            }
        }

        // Calculate valid pairs using combinatorics
        for (Map<Long, Integer> lines : slopeToLinesMap.values()) {
            long totalSegmentsForSlope = 0;
            long collinearPairs = 0;
            for (int segmentsOnLine : lines.values()) {
                totalSegmentsForSlope += segmentsOnLine;
                collinearPairs += (long)segmentsOnLine * (segmentsOnLine - 1) / 2;
            }
            long totalPairs = totalSegmentsForSlope * (totalSegmentsForSlope - 1) / 2;
            countPairs += totalPairs - collinearPairs;
        }

        // --- Step 2: Count non-degenerate parallelograms efficiently ---
        long parallelogramCount = 0;
        Map<String, List<int[]>> midPointMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                String key = ((long)points[i][0] + points[j][0]) + "," + ((long)points[i][1] + points[j][1]);
                
                // Get the list of diagonals for the current midpoint.
                List<int[]> diagonalList = midPointMap.get(key);
                // If no list exists for this midpoint, create one.
                if (diagonalList == null) {
                    diagonalList = new ArrayList<>();
                    midPointMap.put(key, diagonalList);
                }
                // Add the current diagonal to the list.
                diagonalList.add(new int[]{i, j});
            }
        }

        for (List<int[]> diagonals : midPointMap.values()) {
            int k = diagonals.size();
            if (k < 2) continue;

            Map<String, Integer> diagonalSlopeCount = new HashMap<>();
            for (int[] diagonal : diagonals) {
                int p1_idx = diagonal[0];
                int p2_idx = diagonal[1];
                long dx = (long)points[p1_idx][0] - points[p2_idx][0];
                long dy = (long)points[p1_idx][1] - points[p2_idx][1];

                String slopeKey;
                 if (dx == 0) {
                    slopeKey = "inf";
                } else {
                    int commonDivisor = gcd((int)Math.abs(dx), (int)Math.abs(dy));
                    long norm_dx = dx / commonDivisor;
                    long norm_dy = dy / commonDivisor;
                    if (norm_dx < 0) {
                        norm_dx = -norm_dx;
                        norm_dy = -norm_dy;
                    }
                    slopeKey = norm_dy + "/" + norm_dx;
                }
                diagonalSlopeCount.put(slopeKey, diagonalSlopeCount.getOrDefault(slopeKey, 0) + 1);
            }
            
            long totalPairs = (long)k * (k - 1) / 2;
            long degeneratePairs = 0;
            for (int count : diagonalSlopeCount.values()) {
                degeneratePairs += (long)count * (count - 1) / 2;
            }
            parallelogramCount += totalPairs - degeneratePairs;
        }

        // --- Step 3: Calculate the final result ---
        long uniqueTrapezoids = countPairs - parallelogramCount;
        return (int)uniqueTrapezoids;
    }
}