type Bucket struct {
    used           bool
    minval, maxval int
}

func minimum(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func maximum(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func maximumGap(nums []int) int {
    if nums == nil || len(nums) < 2 {
        return 0
    }

    mini, maxi := nums[0], nums[0]
    for _, num := range nums {
        mini = minimum(mini, num)
        maxi = maximum(maxi, num)
    }

    bucketSize := maximum(
        1,
        (maxi-mini)/(len(nums)-1),
    ) // bucket size or capacity
    bucketNum := (maxi-mini)/bucketSize + 1 // number of buckets
    buckets := make([]Bucket, bucketNum)

    for _, num := range nums {
        bucketIdx := (num - mini) / bucketSize // locating correct bucket
        if !buckets[bucketIdx].used {
            buckets[bucketIdx].used = true
            buckets[bucketIdx].minval = num
            buckets[bucketIdx].maxval = num
        } else {
            buckets[bucketIdx].minval = minimum(num, buckets[bucketIdx].minval)
            buckets[bucketIdx].maxval = maximum(num, buckets[bucketIdx].maxval)
        }
    }

    prevBucketMax, maxGap := mini, 0
    for _, bucket := range buckets {
        if !bucket.used {
            continue
        }

        maxGap = maximum(maxGap, bucket.minval-prevBucketMax)
        prevBucketMax = bucket.maxval
    }

    return maxGap
}