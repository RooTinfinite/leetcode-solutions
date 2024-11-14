class Solution {
    function getRow($rowIndex) {
        $res = [1];
        $prev = 1;
        for($k = 1; $k <= $rowIndex; $k++) {
            $next_val = $prev * ($rowIndex - $k + 1) / $k;
            $res[] = $next_val;
            $prev = $next_val;
        }
        return $res;
    }
}