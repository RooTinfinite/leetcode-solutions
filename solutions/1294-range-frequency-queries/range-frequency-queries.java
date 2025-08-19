class RangeFreqQuery {
    int[][] arr;

    public RangeFreqQuery(int[] arr) {
        int max = 0;
        for (int num : arr) {
            max = Math.max(num, max);
        }
        this.arr = new int[max + 1][];
        int[] counts = new int[max + 1];
        for (int num : arr) {
            counts[num]++;
        }
        for (int i = 0; i <= max; i++) {
            if (counts[i] > 0)
                this.arr[i] = new int[counts[i]];
        }
        for (int i = arr.length - 1; i >= 0; i--) {
            this.arr[arr[i]][--counts[arr[i]]] = i;
        }
    }

    public int query(int left, int right, int value) {
        if (value >= arr.length || arr[value] == null)
            return 0;
        int l = binarySearch(arr[value], left);
        if (l == arr[value].length)
            return 0;
        int r = binarySearch(arr[value], l, right);
        return r - l + 1;
    }

    public int binarySearch(int[] arr, int target) {
        int l = 0;
        int r = arr.length;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (arr[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    public int binarySearch(int[] arr, int l, int target) {
        int r = arr.length;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (arr[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l - 1;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */