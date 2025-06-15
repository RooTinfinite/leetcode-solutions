function maxDiff(num: number): number {
    const change = (x: number, y: number): string => {
        let numStr = num.toString();
        let res = "";
        for (let digit of numStr) {
            if (parseInt(digit) === x) {
                res += y.toString();
            } else {
                res += digit;
            }
        }
        return res;
    };

    let minNum = num;
    let maxNum = num;
    for (let x = 0; x < 10; ++x) {
        for (let y = 0; y < 10; ++y) {
            let res = change(x, y);
            // Check if there are leading zeros
            if (res[0] !== "0") {
                let resI = parseInt(res);
                minNum = Math.min(minNum, resI);
                maxNum = Math.max(maxNum, resI);
            }
        }
    }

    return maxNum - minNum;
}