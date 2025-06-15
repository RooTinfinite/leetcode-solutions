class Solution {
  public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // If two intervals share the same start point,
    // put the longer one to be the first.
    sort(begin(intervals), end(intervals),
      [](const vector<int> &o1, const vector<int> &o2) {
      return o1[0] == o2[0] ? o2[1] < o1[1] : o1[0] < o2[0];
    });

    int count = 0;
    int end, prev_end = 0;
    for (auto curr : intervals) {
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
};