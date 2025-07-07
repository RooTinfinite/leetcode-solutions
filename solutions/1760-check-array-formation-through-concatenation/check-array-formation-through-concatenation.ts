function canFormArray(arr: number[], pieces: number[][]): boolean {
    const hash = {};

    for (let i = 0; i < pieces.length; i++) {
        const piece = pieces[i];

        hash[piece[0]] = piece;
    }

    for (let i = 0; i < arr.length;) {
        const num = arr[i];
        const nums = hash[num];

        if (!nums) {
            return false;
        }

        let index = 0;

        while (index < nums.length) {
            if (nums[index] !== arr[i]) {
                return false;
            }

            index++;
            i++;
        }
    }

    return true;
};