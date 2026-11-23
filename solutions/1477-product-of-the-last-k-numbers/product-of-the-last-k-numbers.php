class ProductOfNumbers {
    private array $products;

    function __construct() {
        $this->products = [1];
    }
    function add($num) {
        if ($num === 0) {
            $this->products = [1]; } else {$this->products[] = end($this->products) *$num;
        }
    }
    function getProduct($k) {
        $n = count($this->products);
        if ($k >=$n) {
            return 0;
        }
        return intdiv($this->products[$n - 1],$this->products[$n - 1 -$k]);
    }
}