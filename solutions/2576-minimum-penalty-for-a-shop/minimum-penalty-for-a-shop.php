class Solution {
    public function bestClosingTime($customers) {
        $max_score = $score = 0;
        $best_hour = -1;
        
        for($i = 0; $i < strlen($customers); ++$i) {
            $score += ($customers[$i] === 'Y') ? 1 : -1;
            if($score > $max_score) {
                $max_score = $score;
                $best_hour = $i;
            }
        }
        
        return $best_hour + 1;
    }
}