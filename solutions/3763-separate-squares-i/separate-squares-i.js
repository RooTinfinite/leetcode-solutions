var separateSquares = function (squares) {
    let max_y = 0,
        total_area = 0;
    for (const [x, y, l] of squares) {
        total_area += l * l;
        max_y = Math.max(max_y, y + l);
    }

    const check = (limit_y) => {
        let area = 0;
        for (const [x, y, l] of squares) {
            if (y < limit_y) {
                area += l * Math.min(limit_y - y, l);
            }
        }
        return area >= total_area / 2;
    };

    let lo = 0,
        hi = max_y;
    const eps = 1e-5;
    while (Math.abs(hi - lo) > eps) {
        const mid = (hi + lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
};