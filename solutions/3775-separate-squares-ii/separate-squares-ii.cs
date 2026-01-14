public class SegmentTree {
    private int[] count;
    private int[] covered;
    private int[] xs;
    private int n;

    public SegmentTree(int[] xs_) {
        xs = xs_;
        n = xs.Length - 1;
        count = new int[4 * n];
        covered = new int[4 * n];
    }

    private void Modify(int qleft, int qright, int qval, int left, int right,
                        int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            Modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            Modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

    public void Update(int qleft, int qright, int qval) {
        Modify(qleft, qright, qval, 0, n - 1, 0);
    }

    public int Query() {
        return covered[0];
    }
}

public class Solution {
    public double SeparateSquares(int[][] squares) {
        // save events: (y-coordinate, type, left boundary, right boundary)
        List<int[]> events = new List<int[]>();
        SortedSet<int> xsSet = new SortedSet<int>();

        foreach (var sq in squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.Add(new int[] { y, 1, x, xr });
            events.Add(new int[] { y + l, -1, x, xr });
            xsSet.Add(x);
            xsSet.Add(xr);
        }

        // sort events by y-coordinate
        events.Sort((a, b) => a[0].CompareTo(b[0]));
        // discrete coordinates
        int[] xs = xsSet.ToArray();
        // initialize the segment tree
        SegmentTree segTree = new SegmentTree(xs);

        List<long> psum = new List<long>();
        List<int> widths = new List<int>();
        long totalArea = 0;
        int prev = events[0][0];

        // scan: calculate total area and record intermediate states
        foreach (var eventItem in events) {
            int y = eventItem[0], delta = eventItem[1], xl = eventItem[2],
                xr = eventItem[3];
            int len = segTree.Query();
            totalArea += (long)len * (y - prev);
            segTree.Update(xl, xr, delta);
            // record prefix sums and widths
            psum.Add(totalArea);
            widths.Add(segTree.Query());
            prev = y;
        }

        // calculate the target area (half rounded up)
        long target = (totalArea + 1) / 2;
        // find the first position greater than or equal to target using binary
        // search
        int idx = BinarySearch(psum, target);
        // get the corresponding area, width, and height
        double area = psum[idx];
        int width = widths[idx], height = events[idx][0];

        return height + (totalArea - area * 2) / (width * 2.0);
    }

    private int BinarySearch(List<long> list, long target) {
        int left = 0;
        int right = list.Count - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid] < target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
}