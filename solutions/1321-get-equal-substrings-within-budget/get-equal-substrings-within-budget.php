class Solution {
    /**
     * @param String $s
     * @param String $t
     * @param Integer $maxCost
     * @return Integer
     */
    function equalSubstring($s, $t, $maxCost) {
        // Length of input strings
        $n = strlen($s);
        
        // Two pointers for sliding window
        $l = 0;
        
        // Track current cost and max length found
        $cost = 0;
        $len = 0;
        
        // First pass: Try to include as many characters as possible from start
        for ($r = 0; $r < $n; $r++) {
            // Add cost of transforming current character
            $cost += abs(ord($s[$r]) - ord($t[$r]));
            
            // If cost exceeds maxCost, undo last addition and break
            if ($cost > $maxCost) {
                $cost -= abs(ord($s[$r]) - ord($t[$r]));
                break;
            }
        }
        
        // If we reached end of string and cost is acceptable,
        // entire string can be transformed
        if ($r == $n && $cost <= $maxCost) return $n;
        
        // Store the length of first valid window
        $len = $r;
        
        // Second pass: Sliding window approach
        for (; $r < $n; $r++) {
            // Add cost of including new character
            $cost += abs(ord($s[$r]) - ord($t[$r]));
            
            // While cost exceeds maxCost, shrink window from left
            while ($cost > $maxCost) {
                $cost -= abs(ord($s[$l]) - ord($t[$l]));
                $l++;
            }
            
            // Update maximum length if current window is larger
            $len = max($len, $r - $l + 1);
        }
        
        return $len;
    }
}