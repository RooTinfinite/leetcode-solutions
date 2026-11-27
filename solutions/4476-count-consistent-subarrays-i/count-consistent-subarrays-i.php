class Solution {
    function countConsistent($nums) {$n = count($nums);$cnt = 0;
        for ($i = 0; $i < $n; $i++) {
            $add =$nums[$i];$min = $nums[$i];
            for ($j =$i; $j <$n; $j++) {$add &= $nums[$j];
                if ($nums[$j] < $min) {$min = $nums[$j];
                }
                if ($add === $min) {$cnt++;
                }
            }
        }
        return $cnt;
    }
}