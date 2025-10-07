class Solution {

    int countInvs(int[] nums, int from, int to, int n) {
        if(to <= from) return 0;
        if(to == from + 1) {
            int res = (nums[from] > nums[to] && nums[from] - nums[to] <= n) ? 1 : 0;
            Arrays.sort(nums, from, to + 1);
            return res;
        }
        int mid = (from + to)/2;
        int l = countInvs(nums, from, mid, n);
        int r = countInvs(nums, mid + 1, to, n);
        int fst = from;
        int snd = from;
        int res = l + r;
        for(int i = mid + 1; i <= to; i++) {
            while(fst <= mid && nums[fst] <= nums[i]) fst++;
            while(snd <= mid && nums[snd] <= nums[i] + n) snd++;
            res += snd - fst;
        }
        int[] temp = new int[to - from + 1];
        int i = from, j = mid + 1, k = 0;
        for(; i <= mid && j <= to;) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= to) temp[k++] = nums[j++];
        System.arraycopy(temp, 0, nums, from, to - from + 1);
        return res;
    }


    public int minThreshold(int[] nums, int k) {
        int l = 0;
        int r = 1_000_000_002;
        while(l < r) {
            int mid = (l + r)/2;
            int myCnt = countInvs(nums.clone(), 0, nums.length - 1, mid);
            //System.out.println(mid + "-->" + myCnt);
            if(myCnt >= k) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l > 1_000_000_000 ? -1 : l;
    }
}