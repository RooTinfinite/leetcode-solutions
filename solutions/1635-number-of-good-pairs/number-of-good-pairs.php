class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
   function numIdenticalPairs($A) {
    $ans = 0;
    $cnt = [];
    
    foreach ($A as $x) {
        $ans += $cnt[$x] ?? 0;
        $cnt[$x] = ($cnt[$x] ?? 0) + 1;
    }
    
    return $ans;
}

}