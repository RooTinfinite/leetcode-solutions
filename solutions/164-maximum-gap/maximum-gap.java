public class Solution {
    static class Bucket {
        public boolean used = false;
        public int minval = Integer.MAX_VALUE;
        public int maxval = Integer.MIN_VALUE;
    }

    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) return 0;

        int mini = Arrays.stream(nums).min().getAsInt(), maxi = Arrays.stream(
            nums
        )
            .max()
            .getAsInt();

        int bucketSize = Math.max(1, (maxi - mini) / (nums.length - 1)); // bucket size or capacity
        int bucketNum = (maxi - mini) / bucketSize + 1; // number of buckets
        Bucket[] buckets = new Bucket[bucketNum];

        for (int num : nums) {
            int bucketIdx = (num - mini) / bucketSize; // locating correct bucket
            if (buckets[bucketIdx] == null) buckets[bucketIdx] = new Bucket();

            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = Math.min(
                num,
                buckets[bucketIdx].minval
            );
            buckets[bucketIdx].maxval = Math.max(
                num,
                buckets[bucketIdx].maxval
            );
        }

        int prevBucketMax = mini, maxGap = 0;
        for (Bucket bucket : buckets) {
            if (bucket == null || !bucket.used) continue;

            maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
}