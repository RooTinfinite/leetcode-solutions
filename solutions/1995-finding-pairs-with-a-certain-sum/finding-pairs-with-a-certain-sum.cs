public class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Dictionary<int, int> cnt;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.cnt = new Dictionary<int, int>();
        foreach (int num in nums2) {
            if (cnt.ContainsKey(num)) {
                cnt[num]++;
            } else {
                cnt[num] = 1;
            }
        }
    }

    public void Add(int index, int val) {
        int oldVal = nums2[index];
        cnt[oldVal]--;
        nums2[index] += val;
        if (cnt.ContainsKey(nums2[index])) {
            cnt[nums2[index]]++;
        } else {
            cnt[nums2[index]] = 1;
        }
    }

    public int Count(int tot) {
        int ans = 0;
        foreach (int num in nums1) {
            int rest = tot - num;
            if (cnt.ContainsKey(rest)) {
                ans += cnt[rest];
            }
        }
        return ans;
    }
}