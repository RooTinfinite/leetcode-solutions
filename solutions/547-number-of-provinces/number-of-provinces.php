class UF {
    private $p;
    private $height;

    function __construct($n) {
        $this->p = range(0, $n - 1);
        $this->height = array_fill(0, $n, 1);
    }

    function find($u) {
        if ($this->p[$u] == $u) return $u;
        return $this->find($this->p[$u]);
    }

    function merge($root1, $root2) {
        if ($root1 == $root2) return;
        if ($this->height[$root1] < $this->height[$root2]) {
            list($root1, $root2) = array($root2, $root1);
        }
        $this->p[$root2] = $root1;
        $this->height[$root1] = max($this->height[$root1], 1 + $this->height[$root2]);
    }
}

class Solution {

    /**
     * @param Integer[][] $isConnected
     * @return Integer
     */
    function findCircleNum($isConnected) {
        $n = count($isConnected);
        $uf = new UF($n);
        for ($i = 0; $i < $n; $i++) {
            for ($j = $i + 1; $j < $n; $j++) {
                if ($isConnected[$i][$j] == 1) {
                    $root1 = $uf->find($i);
                    $root2 = $uf->find($j);
                    $uf->merge($root1, $root2);
                }
            }
        }
        
        $components = [];
        for ($i = 0; $i < $n; $i++) {
            $components[$uf->find($i)] = true;
        }
        
        return count($components);
    }
}