class Solution {

    public List<String> maxNumOfSubstrings(String s) {
        Seg[] seg = new Seg[26];
        for (int i = 0; i < 26; ++i) {
            seg[i] = new Seg(-1, -1);
        }
        // Preprocess the left and right endpoints.
        for (int i = 0; i < s.length(); ++i) {
            int charIdx = s.charAt(i) - 'a';
            if (seg[charIdx].left == -1) {
                seg[charIdx].left = seg[charIdx].right = i;
            } else {
                seg[charIdx].right = i;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (seg[i].left != -1) {
                for (int j = seg[i].left; j <= seg[i].right; ++j) {
                    int charIdx = s.charAt(j) - 'a';
                    if (
                        seg[i].left <= seg[charIdx].left &&
                        seg[charIdx].right <= seg[i].right
                    ) {
                        continue;
                    }
                    seg[i].left = Math.min(seg[i].left, seg[charIdx].left);
                    seg[i].right = Math.max(seg[i].right, seg[charIdx].right);
                    j = seg[i].left;
                }
            }
        }
        // Greedily select intervals.
        Arrays.sort(seg);
        List<String> ans = new ArrayList<>();
        int end = -1;
        for (Seg segment : seg) {
            int left = segment.left,
                right = segment.right;
            if (left == -1) {
                continue;
            }
            if (end == -1 || left > end) {
                end = right;
                ans.add(s.substring(left, right + 1));
            }
        }
        return ans;
    }

    class Seg implements Comparable<Seg> {

        int left, right;

        public Seg(int left, int right) {
            this.left = left;
            this.right = right;
        }

        public int compareTo(Seg rhs) {
            if (right == rhs.right) {
                return rhs.left - left;
            }
            return right - rhs.right;
        }
    }
}