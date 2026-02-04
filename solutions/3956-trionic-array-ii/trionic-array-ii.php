class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSumTrionic($nums) {
        $n = count($nums);
        $res = -1e16;
        $i = 1;

        while ($i < $n - 2) {
            $a = $b = $i;
            $net = $nums[$a];

            while ($b + 1 < $n && $nums[$b + 1] < $nums[$b]) {
                $net += $nums[++$b];
            }
            if ($b == $a) { $i++; continue; }

            $c = $b;
            $left = $right = 0;
            $lx = $rx = -PHP_INT_MAX;

            while ($a - 1 >= 0 && $nums[$a - 1] < $nums[$a]) {
                $left += $nums[--$a];
                $lx = max($lx, $left);
            }
            if ($a == $i) { $i++; continue; }

            while ($b + 1 < $n && $nums[$b + 1] > $nums[$b]) {
                $right += $nums[++$b];
                $rx = max($rx, $right);
            }
            if ($b == $c) { $i++; continue; }

            $res = max($res, $lx + $rx + $net);
            $i = $b;
        }
        return $res;
    }
}