const nodesBetweenCriticalPoints = head => {
    let min = 100000, i = 1;
    const c = [0, 0];

    let prev = head, curr = head.next;
    let nxt = head.next.next;

    const isCrit = (a, b, c) => (b.val - a.val) * (b.val - c.val) > 0;

    while (nxt) {
        if (isCrit(prev, curr, nxt)) {
            if (c[0]) min = Math.min(min, i - c[1]);
            else c[0] = i;
            c[1] = i;
        }

        [prev, curr, nxt] = [curr, nxt, nxt.next]; i++;
    }

    if (c[0] === c[1]) return [-1, -1];

    return [min, c[1] - c[0]];
};