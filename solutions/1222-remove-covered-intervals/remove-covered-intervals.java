class Solution {
  public int removeCoveredIntervals(int[][] intervals) {
    Arrays.sort(intervals, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        // Sort by start point.
        // If two intervals share the same start point,
        // put the longer one to be the first.
        return o1[0] == o2[0] ? o2[1] - o1[1]: o1[0] - o2[0];
      }
    });

    int count = 0;
    int end, prev_end = 0;
    for (int[] curr : intervals) {
      end = curr[1];
      // if current interval is not covered
      // by the previous one
      if (prev_end < end) {
        ++count;
        prev_end = end;
      }
    }
    return count;
  }
}