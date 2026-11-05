class Solution {
    ArrayList<Integer> l = new ArrayList<Integer>();
    long sum = Long.MIN_VALUE;

    public void Solve(ArrayList<Integer> l, int arr[], int k) {
        int i = 0, j = l.size() - 1;
        long s = 0;
        int x = arr.length - 1;
        while (j >= i) {
             if (i == k) {
                for (int p = i; p <= j; p++) {
                    s += l.get(p);
                }
                break;
            }
            if (l.get(j) == arr[x]) {
                s += l.get(j);
                j--;
                x--;
            } else {
                i++;
                s += arr[x];
                x--;
            }
        }
        sum = Math.max(sum, s);
    }

    public void insertData(int val) {
        if (l.size() == 0) {
            l.add(val);
        } else {
            int low = 0, high = l.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (l.get(mid) > val) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            l.add(low, val);
        }
    }

    public void removeData(int val) {
        int low = 0, high = l.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (l.get(mid) > val) {
                high = mid - 1;
            } else if (l.get(mid) == val) {
                l.remove(mid);
                break;
            } else {
                low = mid + 1;
            }
        }
    }

    public long maxSum(int[] nums, int length, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (i < length) {
                pq.add(nums[i]);
            } else {
                if (pq.peek() < nums[i]) {
                    pq.poll();
                    pq.add(nums[i]);
                }
            }
        }
        int x = 0;
        int arr[] = new int[length];
        while (pq.size() > 0) {
            arr[x] = pq.poll();
            x++;
        }
        for (int i = 0; i < length; i++) {
            insertData(nums[i]);
        }
        Solve(l, arr, k);
        int y = 0;
        for (int i = length; i < nums.length; i++) {
            removeData(nums[y]);
            y++;
            insertData(nums[i]);
            Solve(l, arr, k);

        }

        return sum;

    }
}