class Solution {
    private static final int MOD = 1000000007;
    public List<Integer> powerUpdate(int[] nums, int p, int[][] queries) {
        int n = nums.length, m = queries.length;

        //sorted array of all values in both nums and queries
        //the index of a value in the sorted array is considered its 'rank'
        int[] sorted = new int[n + m];
        for(int i = 0; i < n; i++) sorted[i] = nums[i];
        for(int i = 0; i < m; i++) sorted[n + i] = queries[i][0];
        Arrays.sort(sorted);

        //Fenwick Tree tracks the frequency of numbers currently in our array
        BIT bit = new BIT(n + m);
        for(int num : nums) {
            int rank = binarySearch(sorted, num); //get the rank of current num
            bit.update(rank, 1); //insert the rank into the tree
        }

        //process queries
        ArrayList<Integer> ans = new ArrayList<>(m);
        for(int i = 0; i < m; i++) {
            int val = queries[i][0];
            int k = n + i + 2 - queries[i][1]; //kth smallest instead of largest

            int queryRank = binarySearch(sorted, val); //get the rank of the query value
            bit.update(queryRank, 1); //insert the rank of the query value into the tree

            int kthRank = bit.kthSmallest(k); //calculate the rank of the kth smallest insertion so far
            p = pow(p, sorted[kthRank]); //p to the power of the value at the rank

            ans.add(p); //add new p to answer
        }

        return ans;
    }

    //standard lower bound, gets the first index of the target value
    private static int binarySearch(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while(left < right) {
            int mid = left + right >>> 1;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    //quick pow algorithm
    private static int pow(long num, long power) {
        long ans = 1L;
        while(power > 0) {
            if((power & 1) == 1) ans = ans * num % MOD;
            num = num * num % MOD;
            power >>>= 1;
        }
        return (int)ans;
    }
}

//Fenwick Tree with function for getting kth smallest rank
class BIT {
    private final int[] bit;
    private final int n, m;
    public BIT(int n) {
        this.n = n;
        this.m = 31 - Integer.numberOfLeadingZeros(n);
        this.bit = new int[n + 1];
    }
    public void update(int index, int val) {
        for(int i = index + 1; i <= n; i += i & -i) bit[i] += val;
    }
    public int query(int index) {
        int ans = 0;
        for(int i = index + 1; i > 0; i &= i - 1) ans += bit[i];
        return ans;
    }

    //calculates kth smallest insertion in O(log(n))
    public int kthSmallest(int target) {
        int index = 0;
        for(int i = m; i >= 0; i--) {
            if(index + (1 << i) < n && bit[index + (1 << i)] < target) {
                index += 1 << i;
                target -= bit[index];
            }
        }
        return index;
    }
}