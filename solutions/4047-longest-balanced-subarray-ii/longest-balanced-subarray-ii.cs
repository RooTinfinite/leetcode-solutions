public class LazyTag {
    public int toAdd;

    public LazyTag() {
        this.toAdd = 0;
    }

    public LazyTag Add(LazyTag other) {
        this.toAdd += other.toAdd;
        return this;
    }

    public bool HasTag() {
        return this.toAdd != 0;
    }

    public void Clear() {
        this.toAdd = 0;
    }
}

public class SegmentTreeNode {
    public int minValue;
    public int maxValue;
    public LazyTag lazyTag;

    public SegmentTreeNode() {
        this.minValue = 0;
        this.maxValue = 0;
        this.lazyTag = new LazyTag();
    }
}

public class SegmentTree {
    private int n;
    private SegmentTreeNode[] tree;

    public SegmentTree(int[] data) {
        this.n = data.Length;
        this.tree = new SegmentTreeNode[this.n * 4 + 1];
        for (int i = 0; i < tree.Length; i++) {
            tree[i] = new SegmentTreeNode();
        }
        Build(data, 1, this.n, 1);
    }

    public void Add(int l, int r, int val) {
        LazyTag tag = new LazyTag();
        tag.toAdd = val;
        Update(l, r, tag, 1, this.n, 1);
    }

    public int FindLast(int start, int val) {
        if (start > this.n) {
            return -1;
        }
        return Find(start, this.n, val, 1, this.n, 1);
    }

    private void ApplyTag(int i, LazyTag tag) {
        tree[i].minValue += tag.toAdd;
        tree[i].maxValue += tag.toAdd;
        tree[i].lazyTag.Add(tag);
    }

    private void Pushdown(int i) {
        if (tree[i].lazyTag.HasTag()) {
            LazyTag tag = new LazyTag();
            tag.toAdd = tree[i].lazyTag.toAdd;
            ApplyTag(i << 1, tag);
            ApplyTag((i << 1) | 1, tag);
            tree[i].lazyTag.Clear();
        }
    }

    private void Pushup(int i) {
        tree[i].minValue =
            Math.Min(tree[i << 1].minValue, tree[(i << 1) | 1].minValue);
        tree[i].maxValue =
            Math.Max(tree[i << 1].maxValue, tree[(i << 1) | 1].maxValue);
    }

    private void Build(int[] data, int l, int r, int i) {
        if (l == r) {
            tree[i].minValue = tree[i].maxValue = data[l - 1];
            return;
        }

        int mid = l + ((r - l) >> 1);
        Build(data, l, mid, i << 1);
        Build(data, mid + 1, r, (i << 1) | 1);
        Pushup(i);
    }

    private void Update(int targetL, int targetR, LazyTag tag, int l, int r,
                        int i) {
        if (targetL <= l && r <= targetR) {
            ApplyTag(i, tag);
            return;
        }

        Pushdown(i);
        int mid = l + ((r - l) >> 1);
        if (targetL <= mid)
            Update(targetL, targetR, tag, l, mid, i << 1);
        if (targetR > mid)
            Update(targetL, targetR, tag, mid + 1, r, (i << 1) | 1);
        Pushup(i);
    }

    private int Find(int targetL, int targetR, int val, int l, int r, int i) {
        if (tree[i].minValue > val || tree[i].maxValue < val) {
            return -1;
        }

        if (l == r) {
            return l;
        }

        Pushdown(i);
        int mid = l + ((r - l) >> 1);

        if (targetR >= mid + 1) {
            int res = Find(targetL, targetR, val, mid + 1, r, (i << 1) | 1);
            if (res != -1)
                return res;
        }

        if (l <= targetR && mid >= targetL) {
            return Find(targetL, targetR, val, l, mid, i << 1);
        }

        return -1;
    }
}

public class Solution {
    public int LongestBalanced(int[] nums) {
        var occurrences = new Dictionary<int, Queue<int>>();

        int len = 0;
        int[] prefixSum = new int[nums.Length];
        prefixSum[0] = Sgn(nums[0]);
        if (!occurrences.ContainsKey(nums[0])) {
            occurrences[nums[0]] = new Queue<int>();
        }
        occurrences[nums[0]].Enqueue(1);

        for (int i = 1; i < nums.Length; i++) {
            prefixSum[i] = prefixSum[i - 1];
            if (!occurrences.ContainsKey(nums[i])) {
                occurrences[nums[i]] = new Queue<int>();
            }
            var occ = occurrences[nums[i]];
            if (occ.Count == 0) {
                prefixSum[i] += Sgn(nums[i]);
            }
            occ.Enqueue(i + 1);
        }

        var seg = new SegmentTree(prefixSum);
        for (int i = 0; i < nums.Length; i++) {
            len = Math.Max(len, seg.FindLast(i + len, 0) - i);

            int nextPos = nums.Length + 1;
            occurrences[nums[i]].Dequeue();
            if (occurrences[nums[i]].Count > 0) {
                nextPos = occurrences[nums[i]].Peek();
            }

            seg.Add(i + 1, nextPos - 1, -Sgn(nums[i]));
        }

        return len;
    }

    private int Sgn(int x) {
        return (x % 2) == 0 ? 1 : -1;
    }
}