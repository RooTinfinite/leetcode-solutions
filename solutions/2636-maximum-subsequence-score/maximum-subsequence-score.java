class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        long result = 0;
        long totalSum = 0;
        PriorityQueue<Integer> heap = new PriorityQueue<>();

        List<int[]> merged = new ArrayList<>();
        for (int i = 0; i < nums1.length; i++) {
            merged.add(new int[]{nums2[i], nums1[i]});
        }
        merged.sort((a, b) -> Integer.compare(b[0], a[0]));

        for (int[] pair : merged) {
            int maxOf2 = pair[0];
            int num1Val = pair[1];

            if (heap.size() == k) {
                totalSum -= heap.poll();
            }

            totalSum += num1Val;
            heap.offer(num1Val);

            if (heap.size() == k) {
                result = Math.max(result, totalSum * (long)maxOf2);
            }
        }

        return result;
    }
}