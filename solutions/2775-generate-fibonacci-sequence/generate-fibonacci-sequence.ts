function* fibGenerator(): Generator<number, any, number> {
    let prev = 0, cur = 1;
    while (true){
        yield prev;
        const next = prev + cur;
        prev = cur;
        cur = next;
    }
};