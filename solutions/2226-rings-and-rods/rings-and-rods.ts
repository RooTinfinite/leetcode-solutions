function countPoints(rings: string): number {
    const target = "RGB";
    const dict: { [key: number]: string[] } = {};

    for (let i = 0; i <= 9; i++) {
        dict[i] = [];
    }

    for (let i = 0; i < rings.length; i += 2) {
        const color = rings[i];
        const index = parseInt(rings[i + 1]);
        dict[index].push(color);
    }

    const checkingListChars = (chars: string[], target: string): boolean => {
        return [...target].every(c => chars.includes(c));
    };

    let count = 0;

    for (const key in dict) {
        if (checkingListChars(dict[key], target)) {
            count++;
        }
    }

    return count;
}