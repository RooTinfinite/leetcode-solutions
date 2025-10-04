class Solution {
    public int minOperations(int n, int m) {
//Using sieve analysis to check prime in (1)
        boolean[] arr = new boolean[10002];
        Arrays.fill(arr, true);
        arr[0] = arr[1] = false;
        for (int i = 2; i < arr.length; i++) {
            if (arr[i]) {
                for (int j = i * 2; j < arr.length; j += i) {
                    arr[j] = false;
                }
            }
        }
//If n is prime than we return -1
        if (arr[n]) {
            return -1;
        }
//Making priority queue 
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{n, n});
        
        int[] visited = new int[10002];
        Arrays.fill(visited, Integer.MAX_VALUE);
        visited[n] = n;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int num = curr[0];
            int cost = curr[1];

            if (num == m) {
                return cost;
            }
//Converting to StringBuilder to make operations easy
            StringBuilder sb = new StringBuilder(String.valueOf(num));
            for (int i = 0; i < sb.length(); i++) {
                char originalChar = sb.charAt(i);

                if (originalChar != '9') {
                    sb.setCharAt(i, (char) (originalChar + 1));
                    int next = Integer.parseInt(sb.toString());
// checking for prime and cost for next and also length
                    if (next < arr.length && !arr[next] && cost + next < visited[next]) {
                        visited[next] = cost + next;
                        pq.offer(new int[]{next, cost + next});
                    }
                    sb.setCharAt(i, originalChar);
                }

                if (originalChar > '0') {
                    sb.setCharAt(i, (char) (originalChar - 1));
                    int next = Integer.parseInt(sb.toString());
                    if (next < arr.length && !arr[next] && cost + next < visited[next]) {
                        visited[next] = cost + next;
                        pq.offer(new int[]{next, cost + next});
                    }
                    sb.setCharAt(i, originalChar);
                }
            }
        }

        return -1;
    }
}