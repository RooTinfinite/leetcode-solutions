function canReach(arr: number[], start: number): boolean {
    const n = arr.length;

    const visited = new Set<number>();
    const q: number[] = [start];

    while (q.length) {
        const i = q.shift()!;

        if (i < 0 || i >= n || visited.has(i))
            continue;

        if (arr[i] === 0)
            return true;

        visited.add(i);

        q.push(i + arr[i]);
        q.push(i - arr[i]);
    }

    return false;
}