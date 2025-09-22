var fibGenerator = function*() {
    let prev = 0, cur = 1;
    while (true){
        yield prev;
        next = prev + cur;
        prev = cur;
        cur = next;
    }
};
