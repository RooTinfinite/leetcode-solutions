function countCollisions(directions: string): number {
    const n: number = directions.length;
    let l: number = 0,
        r: number = n - 1;

    while (l < n && directions[l] === "L") {
        l++;
    }

    while (r >= l && directions[r] === "R") {
        r--;
    }

    let res: number = 0;
    for (let i = l; i <= r; i++) {
        if (directions[i] !== "S") {
            res++;
        }
    }
    return res;
}