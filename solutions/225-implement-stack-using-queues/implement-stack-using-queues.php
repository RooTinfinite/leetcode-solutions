
class MyStack {
    private $q = [];

    public function push($x) {
        array_push($this->q, $x);
        for ($i = 0; $i < count($this->q) - 1; $i++) {
            array_push($this->q, array_shift($this->q));
        }
    }

    public function pop() {
        return array_shift($this->q);
    }

    public function top() {
        return $this->q[0];
    }

    public function empty() {
        return empty($this->q);
    }
}