var canChange = function (start, target) {
    let x = 0, y = 0;

    while (x < start.length || y < target.length) {
        while (x < start.length && start[x] === '_') {
            x++;
        }
        while (y < target.length && target[y] === '_') {
            y++;
        }
        if (start[x] !== target[y]) return false;

        if (start[x] === 'L' && x < y) return false;

        if (start[x] === 'R' && y < x) return false;

        x++;
        y++;
    }
    return true;
};