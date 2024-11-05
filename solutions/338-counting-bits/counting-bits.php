class Solution {

    /**
     * @param Integer $n
     * @return Integer[]
     */
    function countBits($n) {
    $ans = array_fill(0, $n + 1, 0);
    for ($i = 1; $i <= $n; $i++) {
        $ans[$i] = $ans[$i >> 1] + ($i & 1);
    }
    return $ans;
    }
}