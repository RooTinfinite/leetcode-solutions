class Solution {
    fun maxSumTrionic(nums: IntArray): Long {
        val n = nums.size
        var res = -1e16.toLong()
        var i = 1

        while (i < n - 2) {
            var a = i
            var b = i
            var net = nums[a].toLong()

            while (b + 1 < n && nums[b + 1] < nums[b]) {
                net += nums[++b].toLong()
            }
            if (b == a) { i++; continue }

            val c = b
            var left = 0L
            var right = 0L
            var lx = Long.MIN_VALUE
            var rx = Long.MIN_VALUE

            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
                left += nums[--a].toLong()
                lx = maxOf(lx, left)
            }
            if (a == i) { i++; continue }

            while (b + 1 < n && nums[b + 1] > nums[b]) {
                right += nums[++b].toLong()
                rx = maxOf(rx, right)
            }
            if (b == c) { i++; continue }

            res = maxOf(res, lx + rx + net)
            i = b
        }
        return res
    }
}