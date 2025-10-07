class Solution {
    long[] median, cost;
    Long[][] dp;
    Map<Integer, Integer> max = new HashMap<>(), min = new HashMap<>();
    long left = 0, right = 0;
    int balance;
    public long minOperations(int[] nums, int x, int k) {
        int n = nums.length;
        cost = new long[n - x + 1];
        median = new long[n - x + 1];
        fillCostsAndMedians(nums, x);
        dp = new Long[n][k + 1];
        return solve(nums, 0, k, x);
    }
    private long solve(int[] nums, int pos, int k, int x) {
        int n = nums.length;
        if (k == 0) 
            return 0;
        if (pos == n)
            return Long.MAX_VALUE;

        if (dp[pos][k] != null)
            return dp[pos][k];
        long case1 = solve(nums, pos + 1, k, x);
        long case2 = Long.MAX_VALUE;
        if (pos + x <= n) {
            long ops = cost[pos];
            case2 = solve(nums, pos + x, k - 1, x);
            if (case2 != Long.MAX_VALUE)
                case2 += ops;
        }
        
        long res = Math.min(case1, case2);
        return dp[pos][k] = res;

    }
    private void fillCostsAndMedians(int[] nums, int x) {
        int n = nums.length;
        long[] median = new long[n - x + 1];
        PriorityQueue<Integer> maxForMin = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minForMax = new PriorityQueue<>();
        for (int i = 0; i < x; i++) {
            minForMax.add(nums[i]);
            right += nums[i];
        }
        for (int i = 0; i < x/2; i++) {
            int polled = minForMax.poll();
            maxForMin.add(polled);
            left += polled;
            right -= polled;
        }
        int maxSize = x / 2;
        int minSize = x % 2 == 0 ? x / 2 : x/2 + 1;
        median[0] = minForMax.peek();
        cost[0] = (maxSize * median[0]) - left + (right - (minSize * median[0]));
        balance = x % 2 == 0 ? 0 : -1;
        
        for (int i = 1; i + x - 1 < n; i++) {
            int in = nums[i + x - 1];
            int out = nums[i - 1];
            if (in >= minForMax.peek()) {
                minForMax.add(in);
                right += in;
                balance--;
            }    
            else {
                maxForMin.add(in);
                left += in;
                balance++;
            }      
            if (out <= maxForMin.peek()) {
                max.put(out, max.getOrDefault(out, 0) + 1);
                balance--;
                left -= out;
            }     
            else {
                min.put(out, min.getOrDefault(out, 0) + 1);
                balance++;
                right -= out;
            }    
            balanceHeap(maxForMin, minForMax);      
            
            median[i] = minForMax.peek();
            cost[i] = (long)(maxSize * median[i]) - left + (right - (minSize * median[i]));
        }
    }
    private void balanceHeap(PriorityQueue<Integer> maxForMin, PriorityQueue<Integer> minForMax) {
        int bal = balance;
        if (bal > 0) {
            int polled = maxForMin.poll();
            balance -= 2;
            minForMax.add(polled);
            left -= polled;
            right += polled;
            
                
        }
        else if (bal < -1) {
            int polled = minForMax.poll();
            balance += 2;
            maxForMin.add(polled);
            left += polled;
            right -= polled;
            
            
        }
        pruneHeap(minForMax, min);
        pruneHeap(maxForMin, max);
    }
    private void pruneHeap(PriorityQueue<Integer> pq, Map<Integer, Integer> map) {
        while (true) {      
            if (map.containsKey(pq.peek())) {
                int polled = pq.poll();
                map.put(polled, map.get(polled) - 1);
                if (map.get(polled) == 0)
                    map.remove(polled);
            }
            else break;
        }
    }
}